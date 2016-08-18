#include "User.h"

using namespace std;

User::User(string log, string pas, int ag, string tex)
{
	login = log;
	password = pas;
	age = ag;
	text = tex;
}

User::User(string res)
{
	string user = res;

	string log;
	string pas;
	int ag;
	string tex;

	int counter = 0;

	while(user[counter] != ' ') {
		log += user[counter];
		counter++;
	}

	counter++;

	while(user[counter] != ' ') {
		pas += user[counter];
		counter++;
	}

	counter++;

	string tmp_age;

	while(user[counter] != ' ') {
		tmp_age += user[counter];
		counter++;
	}

	counter += 2;

	while(user[counter] != '"') {
		tex += user[counter];
		counter++;
	}

	istringstream convert(tmp_age);
	convert >> age;

	login = log;
	password = pas;
	age = ag;
	text = tex;
}

User::~User() {
	cout << "Object user is deleted\n";
}

string User::getUser() {
	stringstream convert;
	convert << age;

	string result = login + " " +
					password + " " +
					convert.str() + " \"" +
					text + "\"";
	return result;
}

string User::getUserLogin() {
	return login;
}

string User::getUserPassword() {
	return password;
}

string User::getUserAge() {
	stringstream convert;
	convert << age;

	return convert.str();
}

string User::getUserText() {
	return text;
}
