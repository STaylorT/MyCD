# MyCD
**FILES**:
- mycd.py: Main program simulating Unix-like "cd" command. 
- test.py: unittest program that tests the output value for the parser function in mycd.py

mycd.py can be ran via windows command line with: [py mycd.py arg1 arg2]

This program takes 2 inputs from the command line (arg1 = currDirectory ; arg2 = newDirectory). Directory names must be alphanumeric. The only non-alphanumeric characters allowed to be input are for the following commands

**Second command string options:**
- ".." - steps back one directory.
- "." - stays in current directory.
- "/" - takes you to root directory. (Or separates commands/files/directories)
- "dirName" - takes you to dirName within current directory.
   
   ~ You can stack commands with a "/" separating them:
   
   For example, the following are valid commands:
   - "abc/def ../123" | Result : "abc/123"
   - "/abc/def ghi///../klm" | Result: "abc/def/klm"
   - "/abc/def /klm" | Result: "/klm"
   - "/abc/def/ghi def/klm" | Result: "abc/def/klm"
   

