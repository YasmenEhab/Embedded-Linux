#include<iostream>
#include "Account.h"


int main()
{
    Account acc1(1000);
    

    acc1.makeDeposit(500);
    

    acc1.makeWithdrawal(200);
    

    acc1.displayStatus();
    

    Account::displayAccountsInfos();




    return 0 ;
}