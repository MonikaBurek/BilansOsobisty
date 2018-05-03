#ifndef USERS_H
#define USERS_H

#include <iostream>
#include "usersfile.h"


using namespace std;

/*
The class responsible for logging in, registering, changing the password, logging out
*/

class Users
{
    int lastuserIdInFile;
    bool isUserLoggedIn;
    UsersFile applicationUsersFile;
    User user;
    int LoggedUserId;

public:
    Users();
    User giveNewUserData();
    int getLoggedUserId();
    void registerUser();
    int logInUser();
    void passwordChange();
    int logoutUser();


};

#endif
