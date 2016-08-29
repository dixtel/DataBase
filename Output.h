#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <iostream>
#include <vector>
#include <unistd.h> // usleep
#include <cstdlib> // clear

using namespace std;

class Output {
	public:
		Output();
		~Output();
		void AnimateText(vector <string> text);
		void Menu();
		void ShowLoginText();
		void ShowPasswordText();
		void ConfirmPassword();
		void BadPassword();
		void ShowAgeText();
		void ShowText();
		void ConfirmOperation();
		void ErrorRegister();
		void ErrorOpenFile();
		void UserNotFound();
		void UserIsRegister();
		void ShowUser( vector <string> user );

};

#endif // _OUTPUT_H_
