#include "File.h"

using namespace std;

File::File(string dat, string tmp) {
    error = false;
    data = dat;
    tmpdata = tmp;

    fstream file( data.c_str() );
    fstream tmpfile( tmpdata.c_str() );

    if(file.good() && tmpfile.good()) {
        string firstLine;
        getline(file, firstLine);

        string result;
        int counter=0;
        while(true) {

            if(counter > firstLine.size()-1) {
                type.push_back(result);
                break;
            }

            if(firstLine[counter] == ',') {
                type.push_back(result);
                result = "";
                counter++;
            }

            result += firstLine[counter];
            counter++;
        }
    } else  {
    	tmpfile.close();
    	file.close();
    	error = true;
    }
}

File::~File() {
    cout<<"Object file is daleted \n";
}

void File::displayInfo() {
    for(int i=0; i<type.size(); i++) {
        cout << type[i] << endl;
    }
}


bool File::getError() {
    return error;
}

string File::GET(string log, string pas) {
   fstream file( data.c_str() );

    if(file.good()) {
        string user;

        getline(file, user);

        while(getline(file, user)) {
			      string login;
            string password;

        	  int counter = 0;
            while(user[counter] != ' ') {
                login += user[counter];
                counter++;
            }

            counter++;
            while(user[counter] != ' ') {
                password += user[counter];
                counter++;
            }

            if((login == log) && (password == pas)) {
            	file.close();
              return user;
            }
        }
        file.close();
        return "false";
    }
    file.close();
    return "false";
}

bool File::ADD( string user ) {
    fstream file( data.c_str() );
    ofstream tmpfile( tmpdata.c_str() );

    if(file.good() && tmpfile.good()) {
   		string line;

   		getline(file, line);
   		tmpfile << line + "\n";

   		tmpfile << user + "\n";

   		while(getline(file, line)) {
   			tmpfile << line + "\n";
   		}

   		remove( data.c_str() );
   		int result = rename( tmpdata.c_str(), data.c_str() );

   		if(result == 0) cout<<"the file name has been chnged\n";
   		else {
   			cout<<"the file name has not chenged\n";
   			tmpfile.close();
   			file.close();
   			return false;
   		}

   		tmpfile.close();
   		file.close();
   		return true;
    }
    return false;
}

bool File::CHECK(string log, string pas) {
  fstream file( data.c_str() );

  if(file.good()) {
  	string user;

  	getline(file, user);

  	while(getline( file, user )) {
  		string login;
  		string password;

			int counter = 0;
      while(user[counter] != ' ') {
          login += user[counter];
          counter++;
      }

      counter++;
      while(user[counter] != ' ') {
          password += user[counter];
          counter++;
      }

      if((login == log) && (password == pas)) {
      	file.close();
      	return true;
      }

  	}
  }
  file.close();
  return false;
}

bool File::CHECK_LOGIN( string log ) {
    fstream file( data.c_str() );

    if(file.good()) {
      string user;

      getline(file, user);

      while(getline( file, user )) {
        string login;

          int counter=0;
          while(user[counter] != ' ') {
              login += user[counter];
              counter++;
          }

          if(login == log) {
            file.close();
            return true;
          }
      }
  }
  file.close();
  return false;
}

bool File::DELETE(string log) {
    fstream file( data.c_str() );
    ofstream tmpfile(tmpdata.c_str() );

    if(file.good() && tmpfile.good()) {
   		string line;

   		getline(file, line);
   		tmpfile << line + "\n";

   		while(getline(file, line)) {
   			string login;

   			int counter=0;
        while(line[counter] != ' ') {
            login += line[counter];
            counter++;
        }

        if(login != log) tmpfile << line + "\n";
   		}

   		remove( data.c_str() );
   		int result = rename( tmpdata.c_str(), data.c_str() );

   		if(result == 0) cout<<"the file name has been chnged\n";
   		else {
        cout<<"the file name has not chenged\n";
   			file.close();
   			return false;
   		}

   		file.close();
   		return true;
    }
    return false;
}

bool File::CHANGE(string log, string res) {
	  fstream file( data.c_str() );
    ofstream tmpfile( tmpdata.c_str() );

    if(file.good() && tmpfile.good()) {
   		string line;

   		getline(file, line);
   		tmpfile << line + "\n";

   		while(getline(file, line)) {
   			string login;

   			int counter = 0;
        while(line[counter] != ' ') {
            login += line[counter];
            counter++;
        }

        if(login == log) tmpfile << res + "\n";
        else tmpfile << line + "\n";
   		}

   		remove( data.c_str() );
   		int result = rename( tmpdata.c_str(), data.c_str() );

   		if(result == 0) cout<<"the file name has been chnged\n";
   		else {
   			cout<<"the file name has not chenged\n";
   			file.close();
   			return false;
   		}

   		file.close();
   		return true;
    }
    return false;
}
