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
      vector <string> type; // log, pass, age, text
      string data;
      string tmpdata;
      bool error;

    public:
      File(string dat, string tmp);
      ~File();
      void displayInfo();
      bool getError();
      bool DELETE( string log );
      bool CHECK( string log, string pas );
      bool ADD( string result );
      bool CHANGE( string lof, string res );
      string GET( string log, string pas );
};

#endif // _FILE_H_
