#include <iostream>
#include "App.h"
#include "Input.h"
#include "Output.h"

using namespace std;

string fileDirectoryRead("data.txt");
string fileDirectorySave("tmpdata.txt");

App app(fileDirectoryRead, fileDirectorySave);
Output output;
Input input;

void Pause();
void Login();
void UserMenu();
void Register();


int main() {
	if( app.ErrorOpenFile() ) {
		output.ErrorOpenFile();
		Pause();
		return 0;
	}

	while(true) {
		output.Menu();
		int choose = input.Menu();

		if(choose == 1) {
			Login();
			if(app.IsLogin()) {
				UserMenu();
			}
		}
		else if(choose == 2) {
			Register();
		}
		else if(choose == 3) break;
	}
	
	return 0;
}

void Pause() {
	cin.clear();
	cout << "Press enter to continue...";
	cin.ignore();
}

void Login() {
	output.ShowLoginText();
	string login = input.EnterLogin();

	output.ShowPasswordText();
	string password = input.EnterPassword();

	if( !app.CheckUserIsRegister(login, password) ) {
		output.UserNotFound();
		Pause();
		return;
	}

	app.LoginUser(login, password);
}

void UserMenu() {
	while(true) {
		output.ShowUser( app.GetUser() );
		
		int choose = input.UserMenu();

		if(choose == 1) { 
			output.ShowPasswordText();
			string password = input.EnterPassword();

			app.ChangeDataUser("password", password);
		}
		else if(choose == 2) {
			output.ShowAgeText();
			string age = input.EnterAge();

			app.ChangeDataUser("age", age);
		}
		else if(choose == 3) {
			output.ShowText();
			string text = input.EnterText();

			app.ChangeDataUser("text", text);
		}
		else if(choose == 4) {
			output.ConfirmOperation();
			string choose = input.EnterConfirmOperation();

			if(choose == "yes") {
				app.DeleteUser();
				app.LogoutUser();
				break;
			}
		}
		else if(choose == 5) {
			app.LogoutUser();
			break;
		}
	}
}

void Register() {
	output.ShowLoginText();
	string login = input.EnterLogin();

	if( app.CheckLogin(login) ) {
		output.UserIsRegister();
		Pause();
		return;
	}

	output.ShowPasswordText();
	string password1 = input.EnterPassword();

	output.ConfirmPassword();
	string password2 = input.EnterPassword();

	if(password1 != password2) {
		output.BadPassword();
		Pause();
		return;
	}

	output.ShowAgeText();
	string age = input.EnterAge();

	output.ShowText();
	string text = input.EnterText();

	output.ConfirmOperation();
	string choose = input.EnterConfirmOperation();

	if( choose != "yes" ) return;

	if( !app.CreateUser(login, password1, age, text) ) {
		output.ErrorRegister();
		Pause();
	}
}

