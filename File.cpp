#include "File.h"

using namespace std;

File::File(string fileDirectoryRead, string fileDirectorySave) {
    this -> fileDirectorySave = fileDirectorySave;
    this -> fileDirectoryRead = fileDirectoryRead;

    error = false;

    ifstream fileRead( this -> fileDirectoryRead.c_str() );
    ofstream fileSave( this -> fileDirectorySave.c_str() );

    if(fileRead.good() && fileSave.good()) {
        string firstLine;
        getline(fileRead, firstLine);

        SetInformation(firstLine);
    } 
    else {
    	error = true;
    }
}

File::~File() {
    cout<<"Object file is daleted \n";
}

vector <string> File::GetLoginAndPassword(string line) {
    string login;
    string password;

    vector <string> userLoginAndPassword;

    int counter = 0;

    while(line[counter] != ' ') {
        login += line[counter];
        counter++;
    }

    counter++;

    while(line[counter] != ' ') {
        password += line[counter];
        counter++;
    }

    userLoginAndPassword.push_back(login);
    userLoginAndPassword.push_back(password);

    return userLoginAndPassword;
}

void File::SetInformation(string firstLine) {
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        string result;

        while(firstLine[counter] != ',') {
            if(firstLine[counter] == '\0') break;
            result += firstLine[counter];
            counter++;
        }

        dataBaseInfo.push_back(result);
        counter++;
    }
}

void File::DisplayDataBaseInfo() {
    for(int i = 0; i < dataBaseInfo.size(); i++) {
        cout << dataBaseInfo[i] << endl;
    }
}


bool File::ErrorOpenFile() {
    return error;
}

bool File::DeleteUser(string login, string password) {
    ifstream fileRead( fileDirectoryRead.c_str() );
    ofstream fileSave( fileDirectorySave.c_str() );

    if(fileRead.good() && fileSave.good()) {
        string line;

        getline(fileRead, line);
        fileSave << line + "\n";

        while(getline(fileRead, line)) {
            string user;

            vector<string> userdata = GetLoginAndPassword(line);

            if(userdata[0] != login) fileSave << line + "\n";
        }

        int removeOperation = remove( fileDirectoryRead.c_str() );
        int renameOperation = rename( fileDirectorySave.c_str(), fileDirectoryRead.c_str() );

        if( (removeOperation == 0) && (renameOperation == 0) ) {
            cout<<"the file is removed and renamed\n";
            return true;
        }
        else {
            cout<<"the file is not removed and renamed\n";
            return false;
        }
    }
    return false;
}

bool File::CheckLogin(string login) {
    ifstream fileRead( fileDirectoryRead.c_str() );

    if( fileRead.good() ) {
        string line;

        getline(fileRead, line);

        while( getline(fileRead, line) )  {
            vector <string> userData = GetLoginAndPassword(line);

            if(userData[0] == login) {
                return true;
            }
        }
        return false;
    }
    return false;
}


bool File::CheckUserIsRegister(string login, string password) {
    ifstream fileRead( fileDirectoryRead.c_str() );

    if( fileRead.good() ) {
        string line;

        getline(fileRead, line);

        while( getline(fileRead, line) )  {
            vector <string> userData = GetLoginAndPassword(line);

            if( (userData[0] == login) && (userData[1] == password) ) {
                return true;
            }
        }
        return false;
    }
    return false;
}

bool File::AddUser( string user ) {
    ifstream fileRead( fileDirectoryRead.c_str() );
    ofstream fileSave( fileDirectorySave.c_str() );

    if( fileRead.good() && fileSave.good() ) {
      string line;

      getline(fileRead, line);

      fileSave << line + "\n";

      fileSave << user + "\n";

      while( getline(fileRead, line) ) {
          fileSave << line + "\n";
      }

      int removeOperation = remove( fileDirectoryRead.c_str() );
      int renameOperation = rename( fileDirectorySave.c_str(), fileDirectoryRead.c_str() );

      if( (removeOperation == 0) && (renameOperation == 0) ) {
          cout<<"the file is removed and renamed\n";
          return true;
      }
      else {
          cout<<"the file is not removed and renamed\n";
          return false;
      }
    }
    return false;
}

bool File::ChangeDataUser(string login, string changedUser) {
    ifstream fileRead( fileDirectoryRead.c_str() );
    ofstream fileSave( fileDirectorySave.c_str() );

    if( fileRead.good() && fileSave.good() ) {
      string line;

      getline( fileRead, line) ;

      fileSave << line + "\n";

      while( getline(fileRead, line) ) {
        vector <string> userData = GetLoginAndPassword(line);

        if( (userData[0] == login) ) {
            fileSave << changedUser + "\n";
            continue;
        }

        fileSave << line + "\n";
      }

      int removeOperation = remove( fileDirectoryRead.c_str() );
      int renameOperation = rename( fileDirectorySave.c_str(), fileDirectoryRead.c_str() );

      if( (removeOperation == 0) && (renameOperation == 0) ) {
          cout<<"the file is removed and renamed\n";
          return true;
      }
      else {
          cout<<"the file is not removed and renamed\n";
          return false;
      }

      return true;
    }
    return false;
}


string File::GetUser(string login, string password) {
   ifstream fileRead( fileDirectoryRead.c_str() );

    if( fileRead.good() ) {
        string line;

        getline(fileRead, line);

        while( getline(fileRead, line) ) {
            vector <string> userData = GetLoginAndPassword(line); 

            if( (userData[0] == login) && (userData[1] == password) ) {
                return line;
            }
        }
        return "UserNoFound";
    }
    return "ErrorOpenFile";
}
