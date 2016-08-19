#include "App.h"

App::App(string dat, string tmp) {
	data = dat;
	tmpdata = tmp;
	file = new File(dat ,tmp);
}

App::~App() {
	delete file;
	file = NULL;

	if(user) delete user;
	user = NULL;
}

bool App::registerUser(string log, string pas, int ag, string tex) {
	if(user) delete user;
	user = new User(log, pas, ag, tex);

	string result = user -> getUser();

	bool isgood = file -> ADD( result );

	if(isgood) return true;
	else return false;
}

void App::createUser(string use) {
	if(user) delete user;
	user = new User( use );
}

bool App::checkUserLogin(string log, string pas) {
	return file -> CHECK(log, pas);
}

bool App::checkUserRegister(string log) {
	return file -> CHECK_LOGIN(log);
}


string App::getUser(string log, string pas) {
	string result = file -> GET(log, pas);
	return result;
}

string App::getUserLogin() {
	return user -> getUserLogin();
}

string App::getUserPassword() {
	return user -> getUserPassword();
}

int App::getUserAge() {
	return user -> getUserAge();
}

string App::getUserText() {
	return user -> getUserText();
}
