#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
using namespace std;

#define MAXTOKENS 3
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
			cout << "\nAlready at root directory."  << endl;
		else{
			cout << "\nResetting to root directory." << endl;
			pathStr = "/";
			pathVec = {"/"};
		}
	}
	int getVecSize(){
		return pathVec.size();
	}
	void pushPathVec(string str){
		if (pathVec.size() > 1)
			pathVec.push_back("/");
		pathVec.push_back(str);
	}
	string getVecElem(int idx){
		return pathVec[idx];
	}
	void cutPath(int i){
		int j = pathVec.size()-1;
		for (j; j > i;j--){
			pathVec.pop_back();
		}
	}
	void popBack(int i){ // move back i directories

		i *=2;
		if (pathVec.size()-1 < i){
			setPathRoot();
			return;
		}
		cout << "\nMoving back " << i/2 << " directories." << endl;
		for (int j =0; j < i; j++){
		 pathVec.pop_back();
		}
		syncStr();
	}
	
	void stepBack(){ 	// go back one directory (..)
		if (pathVec.size() >1){
			cout << "\nMoving back one directory." << endl;
			pathVec.pop_back();
			pathVec.pop_back(); // remove "/"
			syncStr();
		}
		else
			cout << "\nCannot step back. In root directory." << endl;
	}
	void syncStr(){ 	// sync string back up with more discrete vector
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
bool isValidPath(string path){
		return true;
	}
	
int updatePath(vector<string> newPath, Path &path){
	bool contains = 0;
	int index = -1;
	int checkedPaths = 0;
	cout << "\nUpdating path.." << endl;
	for (int i = 0; i < path.getVecSize(); i++){
		for (int j = 0; j <newPath.size(); j++){
			if (!checkedPaths){ // save from extra looping & checking
			string temp = newPath[j];
			for (int i = 0; i < temp.length(); i++){
				if ((int)temp[i] < 48 || ((int)temp[i]>57 && (int)temp[i]<65) || 
				((int)temp[i] > 90 && (int)temp[i] < 97) || (int)temp[i] > 122){
					cout << "\nNon-alphanumeric pathname invalid." << endl;
					return -1;
				}
			}	
			}
	
			if (path.getVecElem(i) == newPath[j]){
				if(index < i)
					index = i;
				contains = 1;
			}
		}
	}
	if (!contains){
		for (int i = 0; i < newPath.size(); i++){
			if (isValidPath(newPath[i])){
				path.pushPathVec(newPath[i]);
			}
		}
	}
	else{
		path.cutPath(index);
		for (int i = 1; i < newPath.size();i++){
			if (isValidPath(newPath[i]))
				path.pushPathVec(newPath[i]);	
		}
	}

	path.syncStr();
	return 1;
} // End UpdatePath()


//   		### Further parse if second pathname starts with a dot (.) ###
int dotCommand(Path &path){
	if (tokenArr[1] == ".") // No directory change
		return 1;
	else if (tokenArr[1] == ".."){ // remove previous directory
		path.stepBack();
	}
	else{
		int j =0;
		int stepCount = 1;
		int valid = 1;
		while (tokenArr[1].length()-1 > j){
			if (tokenArr[1][j] == '.' && tokenArr[1][j+1]=='.'){
				if(tokenArr[1].length() <= j+2){
					path.popBack(stepCount);
					return 1;
				}
				else if (tokenArr[1][j+2] == '/'){
					stepCount++;
					j +=3;
				}
				else if (tokenArr[1][j+2] == '.')
					return -1;
			}
			else
				return -1;
		}
		
	}
		return 1;
} // End of dotCommand()


// 		### Further parse if second pathname starts with slash (/) ###
void slashCommand(Path &path){
	vector<string> newPaths; // vector of new paths
	int j =0; // iterator through second token
	string temp; // temp string for each Path
	int switcher = 0; // tell us if when we need to push temp into vector
	bool onlySlash = 1; // whether or not there are only slashes in 2nd token

	while (tokenArr[1].length() > j){
		if (tokenArr[1][j] == '/'){
			j++;
			if (switcher == 1){
				newPaths.push_back(temp);
				temp = "";
				switcher =0;
				
			}
		}
		else{
			temp += tokenArr[1][j];
			switcher = 1;	
			onlySlash = 0;
			j++;
			
		}
	}
	if (switcher == 1){
		newPaths.push_back(temp);
		temp = "";
		switcher =0;
				
	}
	j--;
	int checkUpdate = 0;
	if (onlySlash){
		path.setPathRoot();
		return;
	}
	
	else
		checkUpdate = updatePath(newPaths, path);
	if (checkUpdate < 0)
		return;
		
		
} // End of slashCommand()

//  		 #### Parser function to check for simple format conditions ####
int parser(Path &path){
	if (tokenArr[0].compare(path.getPath()) != 0 && tokenArr[0].compare(".") != 0){
		cout << "\nCurrent directory incorrect." << endl;
		return -1;
		}
	else{
		if (tokenArr[1] == ""){
			cout << "\nNo second input" << endl;
			return -1;
		}	
	int dRes = 0;
		switch(tokenArr[1][0]){
			case '.':
				 dRes= dotCommand(path);
				if (dRes < 0)
					cout << "\nInvalid Command." << endl;
				break;
			case '/':
				slashCommand(path);
				return 1;
			default:
				cout << "\nInvalid Command." << endl;
			break;
		}
	}
			
	return 1;
	
} // End of parser()


//     	#### Scanner function to parse string into individual tokens ####
int scanner(string input, Path &path){
	if (input == "exit" || input == "quit" || input == "q")
		return -1;
	
	// empty tokenArr for next command
	for (int i = 0; i < MAXTOKENS && tokenArr[i] != ""; i++){
		tokenArr[i] = "";
	}
	//  ###  splitting strings into tokens  ###
	char * str = new char[input.size() + 1]; // converting string to char*
	copy(input.begin(), input.end(), str);   
	str[input.size()] = '\0';
	char * pch;
	pch = strtok (str," \n\t"); // set delimiter
	int i = 0;
	string s;
	while (pch != NULL){
		s = pch;
		tokenArr[i] = pch;
		pch = strtok (NULL, " \n\t");
		i++;
  	}
  	delete[] str;
	string str1;
	//   ### inserting tokens into global array ###
	for (int i = 0 ; i < MAXTOKENS && tokenArr[i] != "";i++){
		str1 = tokenArr[i];
  		for (size_t j=0; j<str1.length(); ++j){
  			tokenArr[i][j] = str1[j];
  		}
    	}
    	if (tokenArr[0] == ""){
    		cout << "\nNo input." << endl;
    		return -1;
    	}
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

