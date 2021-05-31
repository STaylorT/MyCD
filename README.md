# MyCD
**FILES**:
- mycd.py: Main program simulating a simple shell that uses Unix-like "cd" command. 

mycd.py can be ran via windows command line with: [py mycd.py arg1 arg2]

This program takes 2 inputs from the command line (arg1 = currDirectory ; arg2 = newDirectory). Directory names must be alphanumeric. The only non-alphanumeric characters allowed to be input are for the following commands

**Second command string options:**
- ".." - steps back one directory.
- "." - stays in current directory.
- "/" - takes you to root directory.
- "dirName" - takes you to dirName within current directory.
   
   ~ You can enter multiple directories at once. E.g. ". dirName1/dirName2/dirName3" is valid.
   
   ~ The following overwrite is valid: at directory "/abc/efg". Enter command ". abc/123" will take you to "/abc/123".
   
   ~  "../../.." - moves back x directories, where x = the number of ".."s separated by a "/". 

