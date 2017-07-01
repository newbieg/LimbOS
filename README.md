# LimbOS 0.0.2
My own 32 bit Operating System - Rudimentary testing phase
##
## Details:
Currently developement is in the very basics of OS design. I am aiming for a useable 32 bit computer with a command line interface. 
While GUI, 64 bit, and cross-compiled programs are not off the table, they are not in any way a priority with this OS.


Only major advancements will merit a bump in the version name. Currently this OS isn't yet a true Operating System, and it's name is somewhat descriptive of itself. It's either hanging by a limb over the void that is limbo, or it is a growing branch that is striving to improve and grow... Only the future can tell. 


## Build Instructions:
The Makefile is written to automate the build and run of the kernel, however there is some setup on your part (it does not install missing tools). 
To use the Makefile, follow word-for-word the tutorial on creating a cross-compiler found here at http://wiki.osdev.org/GCC_Cross-Compiler - and add it to your environment PATH variable.

You may need to also build and install other third party software such as gnu's bin-utils as found in the above tutorial.

Also make sure that Qemu is installed on your system as that's the Makefile's chosen VM.

Currently the OS does not have the ability to write anything to file, so it's a recomendation that it be built as an iso file as in the Makefile process. As an ISO you can use dd on it to write it to a usb drive, but only do so if you know the whole process and understand that it will wipe all previous information on that drive.


$ cd OSDEV01;

$ make; 


