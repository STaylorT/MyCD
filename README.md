# MyCD
'Simple' program simulating Unix-like CD command; mycd.cpp can be compiled and ran through command line with

[g++ -o mycd mycd.cpp] and [./mycd] , respectively.

**Note: No Command Line Arguments Are Required When Running Program; The program has its own command line of sorts**

The initial path in the program is "/", the root directory.

After starting program, you will continuously be given a prompt: "# " where you can type the _current path_ followed by a _new directory path_ to change the current directory.

**Note: When you type your first command, your first "token" must be "/", since it is the initial current path.**

**SYNTAX:** When typing the two tokens in command line, type the current directory, followed by one space, followed by the new directory.

To exit out of the program, type "exit" or "quit" at the command prompt.
