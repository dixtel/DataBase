#ifndef _DATAMANAGER_H_
#define _DATAMANAGER_H_

#include <iostream>
#include <vector>
#include "File.h"

using namespace std;

class DataManager
{
    private:
      File *file = NULL;
      vector<string> SplitUser(string user);
      string JoinUser(string login, string password, string age, string text);
    public:
      DataManager(string fileDirectoryRead, string fileDirectorySave);
      ~DataManager();
      bool ErrorOpenFile();
      bool ChangeDataUser(string login, vector <string> user);
      bool CreateUser(string login, string password, string age, string text);
      bool DeleteUser(string login, string password);
      bool CheckLogin(string login);
      bool CheckUserIsRegister(string login, string password);
      vector<string> GetUser(string login, string password);
};

#endif // __DATAMANAGER_H_
