#include <iostream>
#include "App.h"
#include "Input.h"
#include "Output.h"

using namespace std;

void pause() {
	cin.clear();
	cout << "Press enter to continue...";
	cin.ignore();
}

int main() {
	string data("data.txt");
	string tmpdata("tmpdata.txt");

	App app(data, tmpdata);

	Output output;
	Input input;

	while(true) {
		output.menu();
		int choose = input.menu();

		if(choose == 3) break;
		if(choose == 2) {
			output.login();
			string login = input.login();

			output.password();
			string password1 = input.password();

			output.confirmPassword();
			string password2 = input.password();

			if(password1 != password2) {
				output.badPassword();
				pause();
				continue;
			}

			output.age();
			int age = input.age();

			output.text();
			string text = input.text();

			output.confirmRegister();
			string choose = input.confirmRegister();

			if(choose != "yes") continue;

			bool result = app.registerUser(login, password1, age, text);

			if(!result) {
				output.errorRegister();
				pause();
				continue;
			}
		}

		output.login();
		string login = input.login();

		output.password();
		string password = input.password();

		bool result = app.checkUser(login, password);

		if(!result) {
			output.userNotFound();
			pause();
			continue;
		}

		string user_result = app.getUser(login, password);

		app.createUser( user_result );

		output.user( app.getUserLogin(),
								 app.getUserPassword(),
								 app.getUserAge(),
								 app.getUserText() );

		pause();
	}
  	
  	pause();
	return 0;
}