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
    int lastUserIdInFile;
    bool isUserLoggedIn;
    UsersFile applicationUsersFile;
    User user;
    int LoggedUserId;

public:
    Users();

    int getLoggedUserId();
    void registerUser();
    int logInUser();
    void passwordChange();
    int logOutUser();

    User giveNewUserData();
    string enterValue(string word);
    string changeFirstLetterToUpperCaseAndRemaingLettersToLowerCase(string word);
};

#endif
