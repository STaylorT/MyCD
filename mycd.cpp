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

class Path{
	vector<string> pathVec;
	string pathStr;
	
	public:
	Path(vector<string>,string);
		
	string getPath(){
		return pathStr;
	}
	void setPathRoot(){ 	// reset path to root directory (/)
		pathStr = "/";
		pathVec = {"/"};
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
	
	void stepBack(){ 	// go back one directory (..)
		pathVec.pop_back();
		syncStr();
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
	
void updatePath(vector<string> newPath, Path &path){
	bool contains = 0;
	cout << "updating path.." << endl;
	for (int i = 0; i < path.getVecSize(); i++){
		for (int j = 0; j <newPath.size(); j++){
			if (path.getVecElem(i) == newPath[j])
				contains = 1;
		}
	}
	if (!contains){
		for (int i = 0; i < newPath.size(); i++){
			if (isValidPath(newPath[i])){
				path.pushPathVec(newPath[i]);
			}
		}
	}

	path.syncStr();
} // End UpdatePath()


//   		### Further parse if second pathname starts with a dot (.) ###
void dotCommand(Path &path){
	if (tokenArr[1] == ".") // No directory change
		return;
	else if (tokenArr[1] == ".."){ // remove previous directory
		cout << "Moving back one directory." << endl;
		path.stepBack();
	}
		
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
	
	if (onlySlash){
		cout << "Resetting to root directory." << endl;
		path.setPathRoot();
		return;
	}
	
	else
		updatePath(newPaths, path);
		
		
} // End of slashCommand()

//  		 #### Parser function to check for simple format conditions ####
int parser(Path &path){
	if (tokenArr[0].compare(path.getPath()) != 0 && tokenArr[0].compare(".") != 0){
		cout << "Current directory incorrect." << endl;
		return -1;
		}
	else{
		if (tokenArr[1] == ""){
			cout << "No second input" << endl;
			return -1;
		}	
	
		switch(tokenArr[1][0]){
			case '.':
				dotCommand(path);
				break;
			case '/':
				slashCommand(path);
				return 1;
			default:
				cout << "Invalid Command." << endl;
			break;
		}
	}
			
	return 1;
	/*
	for (int i = 0; i < temp.length(); i++){
		if ((int)temp[i] < 48 || ((int)temp[i]>57 && (int)temp[i]<65) || 
		((int)temp[i] > 90 && (int)temp[i] < 97) || (int)temp[i] > 122){
			cout << "Non-alphanumeric input." << endl;
			return -1;
		}
	}
	*/
	
} // End of parser()


//     	#### Scanner function to parse string into individual tokens ####
int scanner(string input, Path &path){
	if (input[0] == ' '){
		cout << "Directory cannot start with space." << endl;
		return -2;
	}
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
    		cout << "No input." << endl;
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
	while (input != "exit" && input!="exit"){
		input = "";
		cout << path.getPath() << "# ";
		getline(cin,input);
		int scanResult = scanner(input, path); //run input through a scanner
	

	}
	
	return 0;
}

