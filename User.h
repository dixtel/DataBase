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
      User( string log, string pas, int ag, string tex);
      User( string res );
      ~User();
      string getUser(); //for file
      string getUserLogin();
      string getUserPassword();
      string getUserAge();
      string getUserText();
};

#endif
