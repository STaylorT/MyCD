# MyCD
**FILES**:
- mycd.cpp: Main program simulating a simple shell that uses Unix-like "cd" command. 
- testInput.txt: Test input file containing most cases. Can be redirected to executable on command line like [./mycd < testInput.txt]
- testOutput.txt: Contains output of program when testInput.txt is ran through. [./cd < testInput.txt > textOutput.txt]
- script.txt: Contains script of linux command window during execution **note: this is probably easier to read than test.Output.txt since it shows input as well**

'Simple' program simulating Unix-like CD command; mycd.cpp can be compiled and ran via linux command line with:

[g++ -o mycd mycd.cpp] and [./mycd] , respectively. mycd takes from stdin.

This program takes input from user and keeps track of an arbitrary path directory. It gives user the ability to move up and down directory path via commands expained below. The program will print the current directory along with a "# " prompt after each command.

The initial path in the program is "/", the root directory.

After starting program, you will continuously be given a prompt: [yourCurrentDirectory# ]. You can type the _current path_ followed by a _new directory path_ to change the current directory.

**Note: When you type your first command, your first token (current path) must be "/" (or ".", see below), since it is the initial current path.**

Since it is a bit annoying to retype the directory after each command, you can type "." for short as the "current path" for the first command string.

**SYNTAX:** When prompted to type the two tokens, type the current directory string, followed by one space, followed by the new directory string.

**Second command string options:**
- ".." - steps back one directory.
- "." - stays in current directory.
- "/" - takes you to root directory.
- "/dirName" - takes you to dirName within current directory. (**Note: forward slash (/) is required in front of dirName**)
    ~ You can enter multiple directories at once. E.g. ". /dirName1/dirName2/dirName3" is valid.
- "../../.." - moves back x directories, where x = the number of ".."s separated by a "/".

To exit out of the program, type "exit" or "quit" at the command prompt.

