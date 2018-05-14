#include <iostream>
#include "Markup.h"
#include <vector>
#include "users.h"
#include "expenses.h"
#include "incomes.h"
#include "budgetManager.h"


using namespace std;


int main()
{
    Users usersList;

    char selectedMenuItem;

    while(1)
    {
        if(usersList.getLoggedUserId() == 0)
        {
            system("cls");
            cout << "Aplikacja do prowadzenia budzetu osobistego." << endl << endl;
            cout << "1.Rejestracja" << endl;
            cout << "2.Logowanie" << endl;
            cout << "9.Zamknij program" << endl;
            cin >> selectedMenuItem;

            switch(selectedMenuItem)
            {
            case '1':
                usersList.registerUser();

                break;
            case '2':
                usersList.logInUser();
                break;
            case '9':
                exit(0);
                break;
            }
        }
        else if(usersList.getLoggedUserId() > 0)
        {
            BudgetManager budgetUsers(usersList.getLoggedUserId());
            system("cls");
            cout<< "Aplikacja do prowadzenia budzetu osobistego." <<endl << endl;
            cout << "1.Dodaj przychod." << endl;
            cout << "2.Dodaj wydatek." << endl;
            cout << "3.Bilans z biezacego miesiaca." << endl;
            cout << "4.Bilans z poprzedniego miesiaca." << endl;
            cout << "5.Bilans z wybranego okresu." << endl;
            cout << "6.Zmien haslo." << endl;
            cout << "9.Wyloguj sie." << endl << endl;
            cin>> selectedMenuItem;

            switch(selectedMenuItem)
            {
            case '1':
                budgetUsers.addIncome();
                break;
            case '2':
                budgetUsers.addExpense();
                break;
            case '3':
                budgetUsers.showBalanceFromCurrentMonth();
                break;
            case '4':
                budgetUsers.showBalanceFromPreviousMonth();
                break;
            case '5':
                budgetUsers.showBalanceFromSelectedPeriod();
                break;
            case '6':
                usersList.passwordChange();
                break;
            case '9':
                usersList.logOutUser();
                break;
            }
        }
    }

    return 0;
}
