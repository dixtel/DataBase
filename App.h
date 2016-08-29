#ifndef _APP_H_
#define _APP_H_

#include <iostream>
#include <vector>
#include "User.h"
#include "DataManager.h"

class App
{
	private:
        DataManager *dataManager = NULL;
        User        *user = NULL;
    public:
        App(string fileDirectoryRead, string fileDirectorySave);
        ~App();
        void LoginUser(string login, string password);
        void LogoutUser();
        void ChangeDataUser(string where, string change);
        bool IsLogin();
        bool ErrorOpenFile();
        bool CreateUser(string login, string password, string age, string text);
        bool DeleteUser();
        bool CheckLogin(string login);
        bool CheckUserIsRegister(string login, string password);
        vector <string> GetUser();
};

#endif // _APP_H_
