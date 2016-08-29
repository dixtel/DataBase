#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <vector>

using namespace std;

class User
{
    private:
      string login;
      string password;
      string age;
      string text;
    public:
      User(string login, string password, string age, string text);
      ~User();
      void ChangeDataUser(string where, string change);
      vector <string> GetUser();
};

#endif
