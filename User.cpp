#include "User.h"

using namespace std;

User::User(string login, string password, string age, string text) {
	this -> login  		= login;
	this -> password	= password;
	this -> age 		= age;
	this -> text 		= text;
}

User::~User() {
	cout << "Object user is deleted\n";
}

void User::ChangeDataUser(string where, string change) {
	if(where == "password") {
		password = change;
	} 
	else if(where == "age") {
		age = change;
	} 
	else if(where == "text")  {
		text = change;
	}
}

vector <string> User::GetUser() {
	vector <string> user;
	user.push_back(login);
	user.push_back(password);
	user.push_back(age);
	user.push_back(text);
	return user;
}
