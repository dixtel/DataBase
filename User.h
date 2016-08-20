#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <sstream>

using namespace std;

class User
{
    private:
      string login;
      string password;
      int age;
      string text;
    public:
      User( string log, string pas, string ag, string tex);
      User( string res );
      ~User();
      void change(string where, string change);
      string getUser(); //for file
      string getUserLogin();
      string getUserPassword();
      int getUserAge();
      string getUserText();
};

#endif
