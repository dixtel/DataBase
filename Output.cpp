#include "Output.h"

Output::Output() {

}

Output::~Output() {
		cout << "Object Output is deleted\n";
}

void Output::menu() {
	cout << endl << "--MENU--" << endl
	<< "1. Login" << endl
	<< "2. Register" << endl
	<< "3. Quit" << endl;
}

void Output::login() {
	cout << "Enter login: ";
}

void Output::password() {
	cout << "Enter password: ";
}

void Output::confirmPassword() {
	cout << "Enter agin password: ";
}

void Output::badPassword() {
	cout << "Bad Password\n";
}

void Output::age() {
	cout << "Enter Age: ";
}

void Output::text() {
	cout << "Enter text: ";
}

void Output::confirmRegister() {
	cout << "Confirm register, (yes/no): ";
}

void Output::errorRegister() {
	cout << "Error register\n";
}

void Output::userNotFound() {
	cout << "User not found\n";
}

void Output::userIsRegister() {
	cout << "Login already exists\n";
}

void Output::userMenu( string log, string pas, int ag, string tex ) {
	string login = log;
	string password = pas;
	int age = ag;
	string text = tex;

	cout << "------------------------------" << endl
		 << "Username:   " << login << endl
		 << "Password:   " << password << endl
		 << "Age:        " << age << endl
		 << "Text:       " << text << endl
		 << "------------------------------" << endl
		 << "1. Edit password" << endl
		 << "2. Edit age" << endl
		 << "3. Edit text" << endl
		 << "5. Exit" << endl;
}
