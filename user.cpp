#include <iostream>
#include "user.h"

using namespace std;

User::User()
{
    userId = 0;
    login = "";
    password = "";
    name = "";
    surname = "";
}

User::~User()
{
    ;
}

int User::getUserId()
{
    return userId;
}

string User::getUserLogin()
{
    return login;
}

string User::getUserPassword()
{
    return password;
}

string User::getUserName()
{
    return name;
}

string User::getUserSurname()
{
    return surname;
}

void User::setUserId(int userId)
{
    this -> userId = userId;
}

void User::setUserLogin(string login)
{
    this -> login = login;
}

void User::setUserPassword(string password)
{
    this -> password = password;
}

void User::setUserName(string name)
{
    this -> name = name;
}

void User::setUserSurname(string surname)
{
    this -> surname = surname;
}
