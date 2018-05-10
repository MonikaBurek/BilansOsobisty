#include <iostream>
#include "usersfile.h"
#include <windows.h>
#include <cstdlib>
#include "conversion.h"
#include "Markup.h"

using namespace std;

UsersFile::UsersFile()
{

}

UsersFile::~UsersFile()
{
    ;
}

void UsersFile::addUserToFile(User newUser)
{
    CMarkup xml;
    xml.Load("users.xml");
    xml.FindElem();
    xml.IntoElem(); //inside users

    xml.AddElem("user");
    xml.IntoElem(); // inside user
    xml.AddElem("id", newUser.getUserId());
    xml.AddElem("login", newUser.getUserLogin());
    xml.AddElem("password", newUser.getUserPassword());
    xml.AddElem("name", newUser.getUserName());
    xml.AddElem("surname", newUser.getUserSurname());

    xml.Save("users.xml");
    cout << "Dane zostaly zapisne." << endl;
    system("pause");
}

bool UsersFile::doesUserExist(string userLogin)
{
    CMarkup xml;
    xml.Load("users.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("user"))
    {
        xml.IntoElem();
        xml.FindElem("login");
        MCD_STR loginFile = xml.GetData();
        if ( userLogin == loginFile)
        {
            return true;
        }
        xml.OutOfElem();
    }
    return false;
}

int UsersFile::getLastUserId()
{
    CMarkup xml;
    int lastUserIdInFile;
    xml.Load("users.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem(); //inside in users

    while (xml.FindElem("user"))
    {
        xml.IntoElem(); //inside user
        xml.FindElem("id");
        lastUserIdInFile = atoi(MCD_2PCSZ(xml.GetData()));
        xml.OutOfElem();
    }
    return lastUserIdInFile;
}

User UsersFile::getUser(string userLogin)
{
    CMarkup xml;
    User user;
    xml.Load("users.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("user"))
    {
        xml.IntoElem();
        xml.FindElem("login");
        MCD_STR loginFile = xml.GetData();
        if ( userLogin == loginFile)
        {
            xml.ResetMainPos();
            xml.IntoElem(); //inside user
            xml.FindElem("id");
            user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.ResetMainPos();

            xml.FindElem("login");
            user.setUserLogin(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("password");
            user.setUserPassword(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("name");
            user.setUserName(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("surname");
            user.setUserSurname(xml.GetData());
            xml.ResetMainPos();
            return user;
        }
        xml.OutOfElem();
    }
}

void UsersFile::changeUserPassword(int loggedInUserId, string password)
{
    CMarkup xml;
    int idInFile;
    User user;
    xml.Load("users.xml");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("user"))
    {
        xml.IntoElem();
        xml.FindElem("id");
        idInFile= atoi(MCD_2PCSZ(xml.GetData()));

        if ( loggedInUserId == idInFile)
        {
            xml.ResetMainPos();
            xml.IntoElem(); //inside user
            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password",password);
            break;
        }
        xml.OutOfElem();
    }

    xml.Save("users.xml");
    cout << "Dane zostaly zapisne." << endl;
    system("pause");
}


