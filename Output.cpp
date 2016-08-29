#include "Output.h"

Output::Output() {

}

Output::~Output() {
		cout << "Object Output is deleted\n";
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
	cout << "------------------------------" << endl
		 << "Username:   " << user[0] << endl
		 << "Password:   " << user[1] << endl
		 << "Age:        " << user[2] << endl
		 << "Text:       " << user[3] << endl
		 << "------------------------------" << endl
		 << "1. Edit password" 	<< endl
		 << "2. Edit age" 		<< endl
		 << "3. Edit text" 		<< endl
		 << "4. Delete user" 	<< endl
		 << "5. Exit" 			<< endl;
}
