#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

class Input {
	private:
		bool parse(string what, string how);
	public:
		Input();
		~Input();
		int Menu();
		int UserMenu();
		string EnterLogin();
		string EnterPassword();
		string EnterAge();
		string EnterText();
		string EnterConfirmOperation();
};

#endif // _INPUT_H_
