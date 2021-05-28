#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
using namespace std;

#define MAXTOKENS 3
vector<string> tokens;

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
	void updatePath(string newPath){
		
	}
	void stepBack(){ 	// go back one directory (..)
		pathVec.pop_back();
		syncStr();
	}
	void syncStr(){ 	// sync string back up with more discrete vector
		pathStr = "";
		for(int i = 0; i < pathVec.size();i++){
			pathStr += pathVec[i];
		}
	}
};
Path::Path(vector<string> path, string pathStr1){
	pathVec = path;
	pathStr = pathStr1;
}
//   		### Further Parse if second pathname starts with a dot ###
void dotCommand(Path path){
	if (tokenArr[1] == ".") // No directory change
		return;
	else if (tokenArr[1] == ".."){ // remove previous directory
		path.stepBack();
	}
		
} // End of dotCommand

// 		### Further Parse if second pathname starts with slash ###
void slashCommand(Path path){

} // End of slashCommand
//  		 #### Parser function to check for simple format conditions ####
int parser(Path path){
	if (tokenArr[0].compare(path.getPath()) != 0){
		cout << path.getPath() << endl;
		cout << "Current directory incorrect." << endl;
		return -1;
		}
	else{
		switch(tokens[1][0]){
			case '.':
				dotCommand(path);
				break;
			case '/':
				slashCommand(path);
				return 1;
			default:
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
	
} // End parser function

//     	#### Scanner function to parse string into individual tokens ####
int scanner(string input, Path path){
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
	for (int i = 0; i < MAXTOKENS; i++){
		cout << "Token " << i << " " << tokenArr[i] << endl;
	}
	parser(path);
	return 1;
} // End scanner function

int main(int argc, char **argv){
	string input = "";
	Path path ({"/"},"/");
	cout << path.getPath();
	while (input != "exit"){
		input = "";
		cout << "# ";
		cout << " ";
		getline(cin,input);
		scanner(input, path); //run input through a scanner
	}
	
	return 0;
}

