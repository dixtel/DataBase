#include "App.h"

App::App(string fileDirectoryRead, string fileDirectorySave) {
	dataManager = new DataManager(fileDirectoryRead, fileDirectorySave);
}

App::~App() {
	if (dataManager) {
		delete dataManager;
	}
	if(user) {
		delete user;
	}

	dataManager = NULL;
	user = NULL;

	cout << "Object App is deleted\n";
}
	
void App::LoginUser(string login, string password) {
	if(this -> user) {
		delete this -> user;
	}
	vector <string> user = dataManager -> GetUser(login, password);
	this -> user = new User(user[0], user[1], user[2], user[3]);
}


void App::LogoutUser() {;
	if(user) {
		delete user;
	}
	user = NULL;
}

void App::ChangeDataUser(string where, string change) {
	if(user) {
		user -> ChangeDataUser(where, change);
	}
	vector <string> changedUser = GetUser();
	dataManager -> ChangeDataUser( changedUser[0] , changedUser );
}

bool App::ErrorOpenFile() {
	return dataManager -> ErrorOpenFile();
}

bool App::IsLogin() {
	if(user) {
		return true;
	}
	return false;
}

bool App::CreateUser(string login, string password, string age, string text) {
	return dataManager -> CreateUser(login, password, age, text);
}

bool App::DeleteUser() {
	vector <string> user = GetUser();
	return dataManager -> DeleteUser(user[0], user[1]);
}

bool App::CheckLogin(string login) {
	return dataManager -> CheckLogin(login);
}

bool App::CheckUserIsRegister(string login, string password) {
	return dataManager -> CheckUserIsRegister(login, password);
}

vector <string> App::GetUser() {
	if(user) {
		return user -> GetUser();
	}
	// if not - non void
}
