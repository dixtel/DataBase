#include "Input.h"


Input::Input() {

}

Input::~Input() {
	cout << "Object Input is deleted\n";
}

int Input::menu() {
	int choose; //1, 2, 3

	cin >> choose;

	cin.clear();
	cin.ignore(256, '\n');

	return choose;
}

string Input::login() {
	string login;

	cin >> login;

	cin.clear();
	cin.ignore(256, '\n');

	return login;
}

string Input::password() {
	string password;

	cin >> password;

	cin.clear();
	cin.ignore(256, '\n');

	return password;
}

int Input::age() {
	int age;

	cin >> age;

	cin.clear();
	cin.ignore(256, '\n');

	return age;
}

string Input::text() {
	string text;

	getline(cin, text);

	return text;
}

string Input::confirmRegister() {
	string choose; // yes, no

	cin >> choose;

	cin.clear();
	cin.ignore(256, '\n');

	return choose;
}
