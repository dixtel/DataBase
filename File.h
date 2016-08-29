#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class File
{
    private:
      vector <string> dataBaseInfo; // login, password, age, text
      vector <string> GetLoginAndPassword(string line);
      string fileDirectoryRead;
      string fileDirectorySave;
      bool error;
    public:
      File(string fileDirectoryRead, string fileDirectorySave);
      ~File();
      void SetInformation(string firstLine);
      void DisplayDataBaseInfo();
      bool ErrorOpenFile();
      bool DeleteUser(string login, string password);
      bool CheckLogin(string login);
      bool CheckUserIsRegister(string login, string password);
      bool AddUser(string user);
      bool ChangeDataUser(string login, string changedUser);
      string GetUser(string login, string password);
};

#endif // _FILE_H_
