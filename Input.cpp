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

int Input::Menu() {
	int choose;
	do {
		while(true) {
			if( cin >> choose ) break;
			cin.clear();
			cin.ignore(256, '\n');
		}

		cin.clear();
		cin.ignore(256, '\n');
	} while( !(choose >= 1 && choose <= 3) );

	return choose;
}

int Input::UserMenu() {
	int choose; 
	do {
		while (true) {
			if ( cin >> choose ) break;
			cin.clear();
			cin.ignore(256, '\n');
		} 

		cin.clear();
		cin.ignore(256, '\n');
	} while( !( (choose >= 1 )&& (choose <= 5) ) );

	return choose;
}

string Input::EnterLogin() {
	string login;
	do {
		cin >> login;
		cin.clear();
		cin.ignore(256, '\n');
	} while (parse(login, "!@#$%^&*()_+-=[]{}'|?/>.<,:; "));

	return login;
}

string Input::EnterPassword() {
	string password;

	do {
		cin >> password;
		cin.clear();
		cin.ignore(256, '\n');
	} while (parse(password, "!@#$%^&*()_+-=[]{}'|?/>.<,:; "));

	return password;
}

string Input::EnterAge() {
	string age;
	do {
		cin >> age;
		cin.clear();
		cin.ignore(256, '\n');
	} while (parse(age, "!@#$%^&*()_+-=[]{}'|?/>.<,:; qwertyuiopasdfghjklzxcvbnm"));

	return age;
}

string Input::EnterText() {
	string text;

	getline(cin, text);

	cin.clear();

	return text;
}

string Input::EnterConfirmOperation() {
	string choose; 

	do {
		cin >> choose;
		cin.clear();
		cin.ignore(256, '\n');
	} while( !((choose == "yes") || (choose == "no")) );

	return choose;
}
