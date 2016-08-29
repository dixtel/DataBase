#include "Output.h"

Output::Output() {

}

Output::~Output() {
		cout << "Object Output is deleted\n";
}

void Output::AnimateText(vector <string> text) {
	int currentwidth = text[0].size();
	for (int i=1; i<text.size(); i++) {
		if(currentwidth >= text[i].size()) continue;
		currentwidth = text[i].size();
	}

	const int widthText = currentwidth;
	const int heightText = text.size();

	char emptyBoardText[heightText][widthText];

	for(int i=0; i<heightText; i++) {
		for(int y=0; y<widthText; y++) {
			emptyBoardText[i][y] = ' ';
		}
	}

	emptyBoardText[0][0] = text[0][0];

	for(int i = 1; i < widthText + (heightText); i++) {
		for(int y = 0; y < heightText; y++) {
			if( (i - y) < 0 ) break;
			if( (i - y) > widthText) continue;
			if( text[y].size() < (i - y) ) continue;
			emptyBoardText[y][i-y] = text[y][i-y];
		}

		system("clear");

		for(int i=0; i<heightText; i++) {
			for(int y=0; y<widthText; y++) {
				cout << emptyBoardText[i][y];
			}
			cout << endl;
		}

		usleep(25 * 1000);
	}
}

void Output::Menu() {
	cout << endl << "--MENU--" << endl
	<< "1. Login" << endl
	<< "2. Register" << endl
	<< "3. Quit" << endl;
}

void Output::ShowLoginText() {
	cout << "Enter login: ";
}

void Output::ShowPasswordText() {
	cout << "Enter password: ";
}

void Output::ConfirmPassword() {
	cout << "Enter agin password: ";
}

void Output::BadPassword() {
	cout << "Bad Password\n";
}

void Output::ShowAgeText() {
	cout << "Enter age: ";
}

void Output::ShowText() {
	cout << "Enter text: ";
}

void Output::ConfirmOperation() {
	cout << "Confirm operation, (yes/no): ";
}


void Output::ErrorRegister() {
	cout << "Error register\n";
}

void Output::ErrorOpenFile() {
	cout << "Error open file\n";
}

void Output::UserNotFound() {
	cout << "User not found\n";
}

void Output::UserIsRegister() {
	cout << "Login already exists\n";
}

void Output::ShowUser( vector <string> user ) {
	vector <string> outputText;

	outputText.push_back("------------------------------");
	outputText.push_back("Username:   " + user[0]);
	outputText.push_back("Password:   " + user[1]);
	outputText.push_back("Age:        " + user[2]);
	outputText.push_back("Text:       " + user[3]);
	outputText.push_back("------------------------------");
	outputText.push_back("1. Edit password");
	outputText.push_back("2. Edit age");
	outputText.push_back("3. Edit text");
	outputText.push_back("4. Delete user");
	outputText.push_back("5. Exit");

	AnimateText(outputText);
}
