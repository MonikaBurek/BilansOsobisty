#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include "user.h"
#include "file.h"

using namespace std;

/*
The class responsible for operations on the file Users.txt
*/

class UsersFile :public File
{
    fstream file;

public:
    UsersFile();
    virtual ~UsersFile();

    void addUserToFile(User newUser);
    void changeUserPassword(int loggedInUserId , string password);
    bool doesUserExist(string userLogin);
    int getLastUserId();
    User getUser(string userLogin);
};

#endif // USERSFILE_H
