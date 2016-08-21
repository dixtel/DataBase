#include "Input.h"


Input::Input() {

}

Input::~Input() {
	cout << "Object Input is deleted\n";
}

bool Input::parse(string what, string how) {
	for(int i = 0; i < what.length(); i++) {
		for (int y = 0; y < how.length(); y++) {
			if(what[i] == how[y]) return true;
		}
	}
	return false;
}

int Input::menu() {
	int choose; //1, 2, 3

	do {
		cin >> choose;
		cin.clear();
		cin.ignore(256, '\n');

	} while(!(choose > 0 && choose < 4));

	return choose;
}

int Input::userMenu() {
	int choose; //1, 2, 3, 4

	do {
		cin >> choose;
		cin.clear();
		cin.ignore(256, '\n');

	} while(!(choose > 0 && choose < 5));

	return choose;
}

string Input::login() {
	string login;

	do {
		cin >> login;
		cin.clear();
		cin.ignore(256, '\n');
	} while (parse(login, "!@#$%^&*()_+-=[]{}'|?/>.<,:; "));

	return login;
}

string Input::password() {
	string password;

	do {
		cin >> password;
		cin.clear();
		cin.ignore(256, '\n');

	} while (parse(password, "!@#$%^&*()_+-=[]{}'|?/>.<,:; "));

	return password;
}

string Input::age() {
	string age;

	do {
		cin >> age;
	} while (parse(age, "!@#$%^&*()_+-=[]{}'|?/>.<,:; qwertyuiopasdfghjklzxcvbnm"));

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
