#ifndef ATMREALPROJECT_HEADER_H
#define ATMREALPROJECT_HEADER_H

struct Accounts
{
    char     NAME[20];
    char     ACCOUNT_NUMBER[30];
    char     MOBILE_NUMBER[15];
    int      PIN_NUMBER; 
    double   BALANCE; 
      
};

void createaccount();
void updateAccount();
void cash_withdrawal();
void cash_deposit();
void displayBalance();
void customer_menu();
void employee_menu();

#endif 