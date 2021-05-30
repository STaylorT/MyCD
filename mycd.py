import sys;
import re;

def changeDir(currPath, newPath):
    newDir = ""
    for str in currPath:
        newDir += '/' + str
    for str in newPath:
        newDir+= '/' + str
    print(newDir)

def isValidPath(path1, path2):
    """ Checks if given path is a valid path name 
        returns true if valid and false otherwise"""

    print("Looking at currPath")
    # 
    Path1 = [str(x) for x in path1.split('/') if x.strip()]
    print(Path1)
    for string in Path1:
        if (not string.isalnum()):
            exit("Invalid path name: Non-alphanumeric characters present.")
    
    Path2 = [str(x) for x in path2.split('/') if x.strip()]
    print(Path2)
    for string in Path2:
        if (not string.isalnum()):
            exit("Invalid path name: Non-alphanumeric characters present.")
    changeDir(Path1, Path2)



#   ----------- Main --------------   #
if (not len(sys.argv) == 3):
    sys.exit("Incorrect number of arguments.")
currPathUser = sys.argv[1]
newPathUser = sys.argv[2]
isValidPath(currPathUser,newPathUser)
