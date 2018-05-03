#include <iostream>
#include "users.h"
#include <windows.h>
#include "file.h"
#include "Markup.h"

using namespace std;

Users::Users()
{
    LoggedUserId = 0;
}

int Users::getLoggedUserId()
{
    return LoggedUserId;
}

User Users::giveNewUserData()
{
    int userId;
    string userLogin, userPassword, userName, userSurname;
    bool doesUserExist;
    bool isFileEmpty;
    User newUser;

    cout << "Podaj login uzytkownika: ";
    cin >> userLogin;

    doesUserExist = applicationUsersFile.doesUserExist(userLogin);

    while(doesUserExist == true)
    {
        cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
        cin >> userLogin;
        doesUserExist = applicationUsersFile.doesUserExist(userLogin);
    }


    cout << "Podaj haslo: ";
    cin >> userPassword;

    isFileEmpty = applicationUsersFile.isFileEmpty("users.xml");

    if ( isFileEmpty == 0)  // if the address book is empty
    {
        userId = 1;           // then the new friend has id = 1
    }
    else
    {
        userId = applicationUsersFile.getLastUserId() + 1; // otherwise, get the last person's id from the address book and increase the value by one.
    }

    cout << "Podaj imie: ";
    cin >> userName;
    cout << "Podaj nazwisko: ";
    cin >> userSurname;

    newUser.setUserId(userId);
    newUser.setUserLogin(userLogin);
    newUser.setUserPassword(userPassword);
    newUser.setUserName(userName);
    newUser.setUserSurname(userSurname);

    return newUser;
}

void Users::registerUser()
{
    bool isFileEmpty;
    bool isFileExists;

    isFileExists = applicationUsersFile.isFileExists("users.xml"); // funkcja sprawdzaj¹ca czy plik istnieje (zwraca true jeœli istnieje)
    cout << "isFileExists " << isFileExists << endl;

    if (isFileExists == true)
    {
        isFileEmpty = applicationUsersFile.isFileEmpty("users.xml"); // do porawki lub zmiany

    }
    else if (isFileExists == false)
    {
        cout <<"tak" <<endl;
        CMarkup xml;
        xml.AddElem("users");
        xml.IntoElem();
        xml.Save("users.xml");
    }

    User newUser = giveNewUserData();

    applicationUsersFile.addUserToFile(newUser);

    cout << endl << "Konto zalozone." << endl;
    Sleep(1000);
}


int Users::logInUser()
{
    string userLogin, userPassword;
    bool doesUserExist = 0;
    int attempts = 0;
    bool isFileEmpty;

    isFileEmpty = applicationUsersFile.isFileEmpty("users.xml");

    if (isFileEmpty == 1)
    {
        cout << "Podaj nazwe uzytkownika: ";
        cin >>  userLogin;

        doesUserExist = applicationUsersFile.doesUserExist(userLogin);
        if (doesUserExist == true)
        {
            user = applicationUsersFile.getUser(userLogin);

            for(int attemptsNumber = 0; attemptsNumber < 3; attemptsNumber++)
            {
                attempts = attemptsNumber + 1;
                cout << "Podaj haslo. Pozostalo prob " << 3 - attemptsNumber << ":";
                cin >> userPassword;
                if (user.getUserPassword() == userPassword)
                {
                    cout<< "Zalogowales sie." << endl;
                    LoggedUserId = user.getUserId();
                    return LoggedUserId;
                }
            }
            if( attempts == 3)
            {
                cout << "Podales 3 razy bledne haslo.Poczekaj przez 3 sekundy przed kolejna proba." << endl;
            }
        }


        else if (doesUserExist == false)
        {
            cout << "Nie ma uzytkownika z takim loginem." << endl;
        }
    }
    else
    {
        cout << "Plik jest pusty." << endl;
    }


    Sleep(1500);
    return 0;
}

void Users::passwordChange( )
{
    string userPassword;

    cout << "Podaj nowe haslo: ";
    cin >> userPassword;

 applicationUsersFile.changeUserPassword(getLoggedUserId(),userPassword);


    cout << "Haslo zostalo zmienione." << endl;
    Sleep(1500);


}

int Users::logoutUser()
{
    LoggedUserId = 0;
    return LoggedUserId;
}
