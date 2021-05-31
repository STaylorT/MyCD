#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>
using namespace std;

#define MAXTOKENS 2
string tokenArr[MAXTOKENS];

	// ## class representing a directory path 
class Path{
	vector<string> pathVec; // to keep more discrete track of paths and tokens
	string pathStr; // for easy printing
	
	public:
	Path(vector<string>,string);
		
	string getPath(){ // return path
		return pathStr;
	}
	void setPathRoot(){ 	// reset path to root directory (/)
		if (pathVec.size() == 1)
			int b =0;
		else{
			pathStr = "/";
			pathVec = {"/"};
		}
	}
	// return size of path vector
	int getVecSize(){
		return pathVec.size();
	}
	// push back given string to path vector
	void pushPathVec(string str){
		if (pathVec.size() > 1)
			pathVec.push_back("/");
		pathVec.push_back(str);
		syncStr();
	}
	// returns a element of path vector specified by given index
	string getVecElem(int idx){
		return pathVec[idx];
	}
	// trims down path to given index of path vector
	void cutPath(int i){
		int j = pathVec.size()-1;
		for (j; j > i;j--){
			pathVec.pop_back();
		}
		syncStr();
	}	
	void stepBack(){ 	// go back one directory (..)
		if (pathVec.size() >1){
			pathVec.pop_back();
			if (pathVec.size() > 1)
				pathVec.pop_back(); // remove "/"
			syncStr();
		}
	}
	// sync string back up with more discrete vector
	void syncStr(){ 	
		pathStr = "";
		for(int i = 0; i < pathVec.size();i++){
			pathStr +=  pathVec[i];
		}
	}
};
Path::Path(vector<string> path, string pathStr1){
	pathVec = path;
	pathStr = pathStr1;
}
//  		 #### Main parser function to look at input ####
int parser(Path &path){
		if (tokenArr[0] == ""){
			cout << "\nNo second input" << endl;
			return -1;
		}

    bool startWithSlash = 0;
    if (tokenArr[0][0] == '/')
        startWithSlash = 1;
// Splitting second path by "/" characters
    string path2 = tokenArr[0];
    vector<string> pathVec2;
    char * str = new char[path2.size() + 1]; // converting string to char*
	copy(path2.begin(), path2.end(), str);   
	str[path2.size()] = '\0';
	char * pch;
	pch = strtok (str,"/"); // set delimiter
	int i = 0;
	string s;
	while (pch != NULL){
		s = pch;
		pathVec2.push_back(pch);
		pch = strtok (NULL, "/");
		i++;
  	}
  	delete[] str;
// End of splitting second path: results in PathVec2
	if (startWithSlash)
           path.setPathRoot();
       // looping over the command without the "/"s
	for (int i = 0; i < pathVec2.size(); i++){
            if(pathVec2[i] == "."){
                continue;
            }
            else if(pathVec2[i] == ".."){
                path.stepBack();
            }
            else{
            	bool cutIt = 0;
            	bool isAlNum = 1;
                for (int j = 0; j < pathVec2[i].length(); j++){
                    if (!isalnum(pathVec2[i][j])){
                    	isAlNum = 0;
                    	cout << "No such file or directory found." << endl;
                    	return -1;
                    }
                        
                 }
                 // if the given token is valid, check if currpath contains this file/dir
                if (isAlNum){
                	for (int k = 0; k < path.getVecSize();k++){
                            if (pathVec2[i] == path.getVecElem(k)){
                                path.cutPath(k);
                                cutIt = 1;
                                break;
                            } 
                        }
                }
                 if (!cutIt){ // simply push this file/directory to the new path
                    path.pushPathVec(pathVec2[i]);  
            		}
		}
		  
               }
           

	return 1;
	
} // End of parser()


//     	#### Scanner function to parse string into individual tokens ####
int scanner(string input, Path &path){
	if (input == "exit" || input == "quit" || input == "q")
		return -1;
	
	// empty tokenArr for next command
	for (int i = 0; i < MAXTOKENS; i++){
		tokenArr[i] = "";
	}
	string scannedInput = "";
	for (int i = 0; i < input.length(); i++){
		if (input[i] != ' ' && input[i] != '\n' && input[i] != '\t')
			scannedInput += input[i];
		else{
			cout << "Invalid Input" << endl;
			return -1;
		}
	}
	tokenArr[0] = scannedInput;
	int parseResult = parser(path);
	if (parseResult > 0)
		return 1;
	else
		return -1;
	return 1;
} // End of scanner();

int main(int argc, char **argv){
	string input = "";
	Path path ({"/"},"/");
	while (input != "exit" && input!="quit" && input != "q"){
		input = "";
		cout << path.getPath() << "# ";
		getline(cin,input);
		int scanResult = scanner(input, path); //run input through a scanner

	}
	
	return 0;
}

