#include <iostream>
#include "Markup.h"
#include <vector>
#include "users.h"
#include "expenses.h"
#include "incomes.h"


using namespace std;


int main()
{
    Users user1;
Expenses expense1(1);
Incomes income1(1);
//expense1.addExpense();
//expense1.getExpenseFromSelectedPeriod(20180101,20180511);
//income1.addIncome();
income1.getIncomesFromSelectedPeriod(20180101,20180511);

    //user1.registerUser();
    //user1.logInUser();
   //user1.passwordChange();


    return 0;
}
