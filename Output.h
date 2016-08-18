#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <iostream>

using namespace std;

class Output {
	public:
		Output();
		~Output();
		void menu();
		void login();
		void password();
		void confirmPassword();
		void badPassword();
		void age();
		void text();
		void confirmRegister();
		void errorRegister();
		void userNotFound();
		void user( string log, string pas, string ag, string tex );

};

#endif // _OUTPUT_H_