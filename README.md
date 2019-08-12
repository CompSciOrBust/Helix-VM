# Homebrw Hexlix VM

Homebrew helix is a proof of concept virtual machine which is supposed to act as a compatability layer for developers writing console homebrew the same way the JVM allows java applications to run on any system.

## Building

Currently you can build for Horizon OS (Nintendo switch) and Windows NT. Once user input has been added support will also come for the 3DS and PS Vita.

* To build for windows run compile.bat after installing [MinGW](https://sourceforge.net/projects/mingw/).
* To compile for the Nintendo Switch run make inside of MSys2 after intsalling [LibNX](https://github.com/switchbrew/libnx).

## Running and writing executables

On windows place an exe.bin file in the same folder as Helix's executable to run it.
On Nintendo Switch place an exe.bin file on the root of the SD card to run it.

The assembler isn't capabale of compiling executables yet but exe.bin files can be made by hand using a hex editor like [HXD](https://mh-nexus.de/en/hxd/). Look at Opcodes-WIP.txt to see a list of op codes and VM_CPU_Execute.cpp to see what they do. All instructions are 4 bytes long, the op code is the fourth byte and the opperands go in the first to third bytes.

## Running

To run on windows run hbh.exe in a command prompt.
To run on Nintendo Switch place HBH_NX.nro in the /switch/ folder on your SD card. Open [nx-hbmenu](https://github.com/switchbrew/nx-hbmenu) with [Atmosphere-nx](https://github.com/Atmosphere-NX/Atmosphere) and open HBH_NX.
