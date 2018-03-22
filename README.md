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


$ cd LimbOS;

$ make; 



Notice there is an executable called "_", this is a dummy program that does nothing. I made it simply to be used to comment out lines in the Makefile. It does nothing, so please feel free to replace it's contents with your own version (maybe output some ascii art if you're so inclined).


# Currently I'm working in the folder microKern/ as a test site.
## This has become a bit messy
	I originally gave up on the project and tossed a lot of my work into the Drop01 folder in order to get things back to buildable setting. 
	I took a month or two off to focus on school and work.
	Now I want to focus on getting things working and don't want to delve too deeply at the same time. 
	I'm basically in a holding mode where research is slow and progress is even slower...
