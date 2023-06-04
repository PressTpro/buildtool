# buildtool
a Linux Command Line tool for building packages based on build.inf files

buildtool is inspired on GNU make, buildtool uses build.inf files instead of Makefiles
# Compiling
download buildtool.cpp and compile it with g++

# build.inf
these files have information about the program that is gonna be compiled, a build.inf file contains
- Input File: The file that will be compiled
- Output File: (SAVE_OUTPUT Flag should be on the bottom of the file)
- Compiler: The app that will be used to compile the code (Example: gcc or g++)
 
