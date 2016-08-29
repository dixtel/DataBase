#include "DataManager.h"

using namespace std;

DataManager::DataManager(string fileDirectoryRead, string fileDirectorySave){
	file = new File(fileDirectoryRead, fileDirectorySave);
}

DataManager::~DataManager() {
	if(file) {
		delete file;
	}

	file = NULL;
	cout << "Object DataManager is deleted\n";
}

vector<string> DataManager::SplitUser(string user) {
	vector <string> userElement;
	int counter = 0;

	for (int i = 0; i < 4; i++) {
		string tmpElement;

		if( i == 3 ) {
			counter++;

			while(user[counter] != '"') {
				tmpElement += user[counter];
				counter++;
			}

			userElement.push_back(tmpElement);
			break;
		}

		while(user[counter] != ' ') {
			tmpElement += user[counter];
			counter++;
		}

		userElement.push_back(tmpElement);
		counter++;
	}

	return userElement;
}

string DataManager::JoinUser(string login, string password, string age, string text) {
	return login + " " + password + " " + age + " \"" + text + "\"";
}

bool DataManager::ErrorOpenFile() {
	return file -> ErrorOpenFile();
}			

bool DataManager::ChangeDataUser(string login, vector <string> user) {
	string changedUser = JoinUser(user[0], user[1], user[2], user[3]);
	return file -> ChangeDataUser(login, changedUser);
}

bool DataManager::CreateUser(string login, string password, string age, string text) { 
	string user = JoinUser(login, password, age, text);
	return file -> AddUser(user);
}

bool DataManager::DeleteUser(string login, string password) {
	return file -> DeleteUser(login ,password);
}

bool DataManager::CheckLogin(string login) {
	return file -> CheckLogin(login);
}

bool DataManager::CheckUserIsRegister(string login, string password) {
	return file -> CheckUserIsRegister(login, password);
}

vector<string> DataManager::GetUser(string login, string password) {
	string user = file -> GetUser(login, password);
	return SplitUser(user);
}


