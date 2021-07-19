#include <bits/stdc++.h>
#include "dictionary.hpp"
using namespace std;

#define end "\n" 

void sendToLoad();
bool error = false;

int main() {
	// load in dictionary
	cout << "Please wait while the dictionary is being load." << end;
	sendToLoad();
	if (error) return 1;
	cout << "Dictionary has " << getDictionarySize() << " words." << end;
	
	while (true) {
		// ask for user input
		string input = "";
		cout << "What word would you like to search for? ";
		getline(cin, input);
		
		cout << "input: " << input << end;

		string output = searchForWord(input);
		cout << output << end;
		
		// check if user wants to search again
		string exit = "";
		while (exit != "y" && exit != "n") {
			cout << "Would you like to search some more (y/n)? ";
			getline(cin, exit);
		}
		if (exit == "n") break;
	}
	
	unloadDictionary();
}

// calls load function for all files
void sendToLoad() {
	string filenames[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", 
		"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	for (string filename: filenames) {
		string file = "csvDict\\" + filename + ".csv";
		bool loaded = loadWords(file);
		if (!loaded) {
			error = true;
			cout << "Sorry an error has occurred" << end; 
			break;
		}
	}
}
