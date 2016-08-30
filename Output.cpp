#include "Output.h"

Output::Output() {

}

Output::~Output() {
		cout << "Object Output is deleted\n";
}

void Output::AnimateText(vector <string> text, int miliseconds) {
	int maxWidthTextwidth = text[0].size();
	for (int i = 1; i < text.size(); i++) {
		if(maxWidthTextwidth >= text[i].size()) continue;
		maxWidthTextwidth = text[i].size();
	}

	const int widthText = maxWidthTextwidth;
	const int heightText = text.size();

	char emptyBoardText[heightText][widthText];

	for(int i = 0; i < heightText; i++) {
		for(int y = 0; y < widthText; y++) {
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

		usleep(miliseconds * 1000);
	}
}

void Output::Menu() {
	vector <string> outputText;

	outputText.push_back("------------------------------");
	outputText.push_back("   MENU  ");
	outputText.push_back("1. Login");
	outputText.push_back("2. Register");
	outputText.push_back("3. Quit");
	outputText.push_back("------------------------------");

	AnimateText(outputText, 25);
}

void Output::ShowLoginText() {
	vector <string> outputText;
	outputText.push_back("Enter login: ");
	AnimateText(outputText, 25);
}

void Output::ShowPasswordText() {
	vector <string> outputText;
	outputText.push_back("Enter password: ");
	AnimateText(outputText, 25);
}

void Output::ConfirmPassword() {
	vector <string> outputText;
	outputText.push_back("Enter agin password: ");
	AnimateText(outputText, 25);
}

void Output::BadPassword() {
	vector <string> outputText;
	outputText.push_back("Bad Password");
	AnimateText(outputText, 25);
}

void Output::ShowAgeText() {
	vector <string> outputText;
	outputText.push_back("Enter age: ");
	AnimateText(outputText, 25);
}

void Output::ShowText() {
	vector <string> outputText;
	outputText.push_back("Enter text: ");
	AnimateText(outputText, 25);
}

void Output::ConfirmOperation() {
	vector <string> outputText;
	outputText.push_back("Confirm operation, (yes/no): ");
	AnimateText(outputText, 25);
}


void Output::ErrorRegister() {
	vector <string> outputText;
	outputText.push_back("Error register");
	AnimateText(outputText, 25);
}

void Output::ErrorOpenFile() {
	vector <string> outputText;
	outputText.push_back("Error open file");
	AnimateText(outputText, 25);
}

void Output::UserNotFound() {
	vector <string> outputText;
	outputText.push_back("User not found");
	AnimateText(outputText, 25);
}

void Output::UserIsRegister() {
	vector <string> outputText;
	outputText.push_back("Login already exists");
	AnimateText(outputText, 25);
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

	AnimateText(outputText, 25);
}
