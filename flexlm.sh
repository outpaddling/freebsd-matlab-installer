#!/bin/sh

# Quiet FreeBSD expr -r errors
PATH=/compat/linux/bin:/compat/linux/usr/bin:$PATH
export PATH

case "$1" in
start)
    if [ -e /usr/local/etc/lmboot_TMW ]; then
	/usr/local/etc/lmboot_TMW -glnx86 -u matlab && echo 'MATLAB_lmgrd'
    fi
    ;;
stop)
    if [ -e /usr/local/etc/lmdown_TMW ]; then
	/usr/local/etc/lmdown_TMW  > /dev/null 2>&1
    fi
    ;;
*)
    echo "Usage: $0 {start|stop}"
    exit 1
    ;;
esac

