# MyCD
**FILES**:
- mycd.cpp: Main program simulating a simple shell that uses Unix-like "cd" command. 
- testInput.txt: Test input file containing poetic case testing. Can be redirected to executable on command line like [./mycd < testInput.txt]
- testOutput.txt: Contains output of program when testInput.txt is ran through. [./cd < testInput.txt > textOutput.txt]
- script.txt: Contains script of linux command window during execution **note: this is probably easier to read than test.Output.txt since it shows both input + output**

Simple program simulating Unix-like CD command; mycd.cpp can be compiled and ran via linux command line with:

[g++ -o mycd mycd.cpp] and [./mycd] , respectively. mycd takes from stdin.

This program takes input from user and keeps track of an arbitrary path directory. It gives user the ability to move up and down directory path via commands explained below. The program will print the current directory along with a "# " prompt after each command entered. 

The initial path in the program is "/", the root directory.

After starting program, you will continuously be given a prompt: [yourCurrentDirectory# ]. You can type a _new directory path_ to change the current directory.

**SYNTAX:** To avoid syntax issues, simply type the command or new directory (alphanumeric only) at the prompt, without any spaces or tabs.

**Command Options:**
- ".." - steps back one directory.
- "." - stays in current directory.
- "/" - takes you to root directory. (seconds as directory/file/command separator)
- "/dirName" - takes you to dirName within current directory. (**Note: forward slash (/) is required in front of dirName**)
   
   ~ You can stack these commands on the same line if each command is separated by a "/".
   
   For example, valid commands include:
   - "abc/def/../123" ||| Process:  >> "/abc" >> "/abc/def" >> "/abc" >> "/abc/123"
   - "hello/world/../../goodbye" ||| Process:  >> "/hello" >> "/hello/world" >> "/hello" >> "/" >> "/goodbye"
   - "/abc/." ||| Process:  >> "/" >> "/abc" >> "/abc"

To exit out of the program, type "exit" or "quit" at the prompt.

