#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>
#include <string>

using namespace std;

class Input {
	public:
			Input();
			~Input();
			int menu();
			int userMenu();
			string login();
			string password();
			string age();
			string text();
			string confirmRegister();
};

#endif // _INPUT_H_
