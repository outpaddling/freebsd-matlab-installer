# freebsd-matlab-installer
Script for installing Linux Matlab on FreeBSD

This is an archived copy of my old matlab-installer script for installing
Linux Matlab on FreeBSD.  At one time, it allowed for near full
functionality of Matlab on FreeBSD systems, using the Linux compatibility
kernel module and a few linux-c* ports, such as a Linux JRE.

Even the MEX compiler worked, as long as the user's PATH was correctly
set to find the Linux compilers during a Matlab session.

A copy of the corresponding FreeBSD port is in matlab-installer-port.

I have not had access to a Matlab license for
several years now, and the script must be updated with each new Matlab
version, so don't expect this to work anymore.  I'm posting it here in
case someone is interested enough to update it for more recent Matlab
versions.

Note: It can be tricky to get the JRE working with the installer, but
creating any missing linux-c* ports from the RPMs is quite easy.

I personally recommend using math/octave instead.  It's free, runs
on pretty much any OS, can be installed in minutes on FreeBSD
with "pkg install octave", and is highly
compatible with Matlab.  Any differences are considered bugs by the
Octave project, though Octave will always lag behind the latest Matlab,
obviously.

Also, the Octave project won't have equivalents for every Matlab
add-on, though they do have equivalents for most of the major ones.
Chances are, Octave will do everything you need, especially if you're 
willing to bend a little.

I once had a conversation with a Matlab user that
went something like this:

```
User:   We need a new Matlab license.

Me:     OK, but that will cost $thousands and may take months to get through
	purchasing.  Have you tried Octave?

User:   Yes, we use Octave sometimes.

Me:     How has it worked for you?

User:   Quite well, actually.  It runs pretty much all our scripts,
	unless we coded them in the latest Matlab version.

Me:     Then stop coding in the latest Matlab version.  Then we won't have
	to delay your research, waste the university's money on another
	license, and waste I.T. time setting up and maintaining a license
	server.
```


