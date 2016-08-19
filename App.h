#ifndef _APP_H_
#define _APP_H_

#include <iostream>
#include "File.h"
#include "User.h"

class App
{
	private:
    string data;
    string tmpdata;
    File *file = NULL;
    User *user = NULL;

    public:
    App(string dat, string tmp);
    ~App();
    bool registerUser(string log, string pas, int ag, string tex);
    void createUser(string use);
    bool checkUserLogin(string log, string pas);
    bool checkUserRegister(string log);
    string getUser(string log, string pas);
    string getUserLogin();
    string getUserPassword();
    int getUserAge();
    string getUserText();
};

#endif // _APP_H_
