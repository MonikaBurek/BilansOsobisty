#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

/*
The class based on which the User is created (getters and setters)
*/

class User
{
    int userId;
    string login;
    string password;
    string name;
    string surname;

public:
    User();
    virtual ~User();

    int getUserId();
    string getUserLogin();
    string getUserPassword();
    string getUserName();
    string getUserSurname();

    void setUserId(int userId);
    void setUserLogin(string login);
    void setUserPassword(string password);
    void setUserName(string name);
    void setUserSurname(string surname);
};

#endif // USER_H
