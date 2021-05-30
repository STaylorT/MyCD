import sys;
import re;

def Parser(path1, path2):
    """ Checks if both paths are valid and performs correct 
        directory change based on second path name"""
    # check if current directory is valid
    if (len(path1) > 0 and path1[0][:1] != '/'):
            exit('Current directory invalid')
    # list to keep track of path names to add from path2
    newPath = []
    # split current directory into directory/filename tokens
    Path1 = [x for x in path1.split('/') if x.strip()]
    for string in Path1:
        if (not string.isalnum()):
            exit("Invalid current path: Non-alphanumeric characters present.")
    # if path2 starts with "/", return to home directory
        if (len(path2) > 0 and path2[0] == "/"):
             for char in path2:
                 if (char != '/'):
                     exit("Invalid Command")
        exit("/")
     # split current directory into directory/filename tokens
    Path2 = [x for x in path2.split('/') if x.strip()]   
    # iterate over the tokens in path2 to parse command     
    for tok in Path2:
        if(tok == "."):
            continue
        elif(tok == ".."):
            if (len(newPath) < 1):
                if (len(Path1) > 0):
                    Path1.pop()
            else:
                newPath.pop()
        elif(tok.isalnum()):
            newPath.append(tok)
        else:
            exit("No such file or directory")
    # create new pathname         
    retPath = []
    for str1 in Path1:
        retPath += '/' + str1
    for str1 in newPath:
        retPath += '/' + str1
    retStr = ""
    for char in retPath:
        retStr += char
    if (len(retStr) == 0):
        print ("/")
    else:
        print (retStr)

#   ----------- Main --------------   #
if (not len(sys.argv) == 3):
    sys.exit("Incorrect number of arguments.")
currPathUser = sys.argv[1]
newPathUser = sys.argv[2]
Parser(currPathUser,newPathUser)
