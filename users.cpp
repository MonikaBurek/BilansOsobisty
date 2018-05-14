#include <iostream>
#include "users.h"
#include <windows.h>
#include "file.h"
#include "Markup.h"

using namespace std;

Users::Users()
{
    loggedUserId = 0;
}

int Users::getLoggedUserId()
{
    return loggedUserId;
}

void Users::registerUser()
{
    bool isFileExists;

    isFileExists = applicationUsersFile.isFileExists("users.xml"); // funkcja sprawdzaj¹ca czy plik istnieje (zwraca true jeœli istnieje)

    if (isFileExists == false)
    {
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
    bool doesUserExistIdOne = 0;

    doesUserExistIdOne = applicationUsersFile.isFirstItemInFile("users.xml", "user");

    if (doesUserExistIdOne == true)
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
                    loggedUserId = user.getUserId();
                    return loggedUserId;
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

int Users::logOutUser()
{
    loggedUserId = 0;
    return loggedUserId;
}

User Users::giveNewUserData()
{
    int userId;
    string userLogin, userPassword, userName, userSurname;
    string name, surname;
    bool doesUserExist;
    bool doesUserExistIdOneInFile;
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

    doesUserExistIdOneInFile = applicationUsersFile.isFirstItemInFile("users.xml", "user");

    if ( doesUserExistIdOneInFile == false)
    {
        userId = 1;           // then the new friend has id = 1
    }
    else
    {
        userId = applicationUsersFile.getLastUserId() + 1; // otherwise, get the last person's id from the address book and increase the value by one.
    }

    cout << "Podaj imie: ";
    cin >> name;
    userName = enterValue(name);
    cout << "Podaj nazwisko: ";
    cin >> surname;
    userSurname = enterValue(surname);

    newUser.setUserId(userId);
    newUser.setUserLogin(userLogin);
    newUser.setUserPassword(userPassword);
    newUser.setUserName(userName);
    newUser.setUserSurname(userSurname);

    return newUser;
}

string Users::enterValue(string word)
{
    string changeWord;

    changeWord = changeFirstLetterToUpperCaseAndRemaingLettersToLowerCase(word);

    return changeWord;
}

string Users::changeFirstLetterToUpperCaseAndRemaingLettersToLowerCase(string word)
{
    string changeWord = "";

    for (int i = 0; i < word.length(); i++)
    {
        if (i == 0 )
        {
            if (word[i] >= 97 && word[i] <= 122)  // 97-a 122-z  65 A 90-Z   97-65 = 32
            {
                word[i] = word[i] - 32 ;
                changeWord += word[i];
            }
            else if (word[i] >= 65 && word[i] <= 90)
            {
                changeWord += word[i];
            }
        }
        if (i > 0 )
        {
            if(word[i] >= 97 && word[i] <= 122)
            {
                changeWord += word[i];
            }
            else if (word[i] >= 65 && word[i] <= 90)
            {
                word[i] = word[i] + 32;
                changeWord += word[i];
            }
        }
    }
    return changeWord;
}
