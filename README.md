# MyCD
'Simple' program simulating Unix-like CD command; mycd.cpp can be compiled and ran via linux command line with:

[g++ -o mycd mycd.cpp] and [./mycd] , respectively.

**Note: No Command Line Arguments Are Required When Running Program; The program has its own command line prompts**

The initial path in the program is "/", the root directory.

After starting program, you will continuously be given a prompt: [yourCurrentDirectory# ]. You can type the _current path_ followed by a _new directory path_ to change the current directory.

**Note: When you type your first command, your first token (current path) must be "/" (or ".", see below), since it is the initial current path.**

Since it is a bit annoying to retype the directory after each command, you can type "." for short as the "current path" for the first command string.

**SYNTAX:** When typing the two tokens in command line, type the current directory, followed by one space, followed by the new directory.

**Second command string options:**
- ".." - steps back one directory.
- "." - stays in current directory.
- "/" - takes you to root directory.
- "/dirName" - takes you to dirName within current directory. (**Note: forward slash (/) is required in front of dirName**)

To exit out of the program, type "exit" or "quit" at the command prompt.

