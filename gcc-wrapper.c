#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define DEBUG   0
#define MAX_ARG_SIZE    1024
#define PREFIX  "/usr/local/gentoo-stage3"

int     main(int argc,char *argv[])

{
    extern int  errno;
    int         c;
    char        *p,
		*temp;
    
    /* 
     * Gentoo gcc contains hard-coded paths to files such as
     * /usr/bin/gcc-config, which will not be found in the FreeBSD root
     * tree.  We must chroot() to /usr/local/gentoo-stage3 in order for
     * gcc to function.
     */
    if ( chroot("/usr/local/gentoo-stage3") != 0 )
    {
	fprintf(stderr,"Error: chroot() failed: %s\n",strerror(errno));
	return 1;
    }
    
    /* Relinquish root euid after chroot() */
    seteuid(getuid());

#if DEBUG == 1
    printf("UID = %d   EUID = %d\n",getuid(),geteuid());
#endif

    /* Update paths in gcc arguments to reflect chroot to gentoo-base3 */
    for (c=0; argv[c] != NULL; ++c)
    {
	p = strstr(argv[c],PREFIX);
	if ( p != NULL )
	{
	    /* Null-terminate string preceding PREFIX in original arg */
	    *p = '\0';
	    
	    /* Build new arg with / replacing PREFIX */
	    temp = malloc(MAX_ARG_SIZE+1);
	    snprintf(temp,MAX_ARG_SIZE,"%s%s",
		    argv[c],            /* Points to string before PREFIX */
		    p+strlen(PREFIX)    /* Points to string after PREFIX */
		    );
	    
	    /* Replace old arg with new in argv[] */
	    argv[c] = temp;
	}
    }
    
    /* Check arguments */
#if DEBUG == 1
    putchar('\n');
    for (c=0; argv[c] != NULL; ++c)
	puts(argv[c]);
#endif

    execvp("/usr/bin/gcc",argv);
    return 0;
}

