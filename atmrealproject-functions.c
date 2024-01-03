#include "atmrealproject-header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createaccount()
{
    struct Accounts newaccount;

    printf("Enter your name\n");
    scanf("%s", newaccount.NAME);

    printf("Enter your ACCOUNT NUMBER\n");
    scanf("%s", newaccount.ACCOUNT_NUMBER);

    printf("Enter your MOBILE NUMBER\n");
    scanf("%s", newaccount.MOBILE_NUMBER);

    printf("Creat your FOUR DIGIT PIN CODE\n");
    scanf("%d", &newaccount.PIN_NUMBER);
 
    printf("Enter yor initial amount\n");
    scanf("%lf", &newaccount.BALANCE);


    FILE *file= fopen("ACCOUNT INFO.txt", "a");

    if(file==NULL)
    {
        printf("Error obtained\n please try again\n");
        exit(1);
    }

        int accountExists = 0;

    while (fscanf(file, "%s %s %s %d %lf", newaccount.NAME, newaccount.ACCOUNT_NUMBER,  newaccount.MOBILE_NUMBER, &newaccount.PIN_NUMBER, &newaccount.BALANCE) != EOF)
     {
        if (strcmp(newaccount.ACCOUNT_NUMBER, newaccount.ACCOUNT_NUMBER) == 0) 
        {
            accountExists = 1;
            break;
        }
    }

    if (accountExists==1) 
    {
        printf("Account already exists.\n");
    }
    
     else
    {
        fprintf(file, "%s %s %s %d %lf\n", newaccount.NAME, newaccount.ACCOUNT_NUMBER, newaccount.MOBILE_NUMBER, newaccount.PIN_NUMBER, newaccount.BALANCE);
        printf("Account created successfully.\n");
    }

    //fprintf(file, "%s %d %lf", newaccount.NAME, newaccount.ACCOUNT_NUMBER,newaccount.BALANCE);
    fclose(file);


    //printf("Successfully created your account\n");

}

void updateAccount()
{
    char account_number[10];
    char new_mobile_number[15];
    int  pin;

    printf("Enter the Account number\n");
    scanf("%s", account_number);

    printf("Enter the pin\n");
    scanf("%d",&pin);

    FILE *file= fopen("ACCOUNT INFO.txt", "r");
    FILE *temp_file=fopen("TEMPSAVING_ACCOUNT.txt", "w");

    if(file==NULL || temp_file==NULL)
    {
        printf("Error occured\n");
        exit(1);
    }
 struct Accounts currentaccount;

    int account_updated=0;
    while (fscanf(file, "%s %s %s %d %lf", currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, &currentaccount.PIN_NUMBER, &currentaccount.BALANCE) != EOF)
    {
        if(strcmp(currentaccount.ACCOUNT_NUMBER, account_number)==0 &&(currentaccount.PIN_NUMBER==pin))
            {
                printf("Enter the new number\n");
                scanf("%s",new_mobile_number);

                strcpy(currentaccount.MOBILE_NUMBER,new_mobile_number);
                account_updated=1;
            }
   
        fprintf(temp_file,"%s %s %s %d %lf\n", currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, currentaccount.PIN_NUMBER, currentaccount.BALANCE);
    }
    fclose(file);
    fclose(temp_file);

    remove("ACCOUNT INFO.txt");
    rename( "TEMPSAVING_ACCOUNT.txt" , "ACCOUNT INFO.txt");

    if(account_updated==1)
    {
    printf("Account updated successfully\n");
    }
    else
    {
        printf("Account not found\n");
    }
}

void cash_withdrawal()
{
    int pin;
    char account_number[20];
    double withdrawal_amount;

    FILE *file= fopen("ACCOUNT INFO.txt", "r");
    FILE *temp_file=fopen("TEMPSAVING_ACCOUNT.txt", "w");

    if(file==NULL || temp_file==NULL)
    {
        printf("Error occured\n");
        exit(1);
    }

    struct Accounts currentaccount;

    printf("Enter the account number\n");
    scanf("%s", account_number);

    printf("Enter the PIN\n");
    scanf("%d",&pin);
    while (fscanf(file, "%s %s %s %d %lf\n", currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, &currentaccount.PIN_NUMBER, &currentaccount.BALANCE) != EOF)
    {
        if ((strcmp(currentaccount.ACCOUNT_NUMBER,account_number)==0) &&(currentaccount.PIN_NUMBER==pin))
        {
            printf("Welcome to the ATM\n");

            printf("Enter the amount to be withdrawal\n");
            scanf("%lf", &withdrawal_amount);

            if (withdrawal_amount> currentaccount.BALANCE)
            {
                printf("Insufficent balance\n");
                fclose(file);
                fclose(temp_file);
                remove("TEMPSAVING_ACCOUNT.txt");
                exit(1);
            }
            else
            {
                currentaccount.BALANCE= currentaccount.BALANCE- withdrawal_amount;
                printf("Transaction completed\nThankyou for using this atm\n");
            }
            
        }

        fprintf(temp_file, "%s %s %s %d %lf\n", currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, currentaccount.PIN_NUMBER, currentaccount.BALANCE);

    }

    fclose(file);
    fclose(temp_file);

    remove("ACCOUNT INFO.txt");
    rename( "TEMPSAVING_ACCOUNT.txt","ACCOUNT INFO.txt");
}

void cash_deposit()
{
    char account_number[30];
    int pin;
    double deposited_amount=0;

    FILE *file= fopen("ACCOUNT INFO.txt", "r");
    FILE *temp_file=fopen("TEMPSAVING_ACCOUNT.txt", "w");

    if(file==NULL || temp_file==NULL)
    {
        printf("Error occured\n");
        exit(1);
    }

    struct Accounts currentaccount;

    int deposit_success =0;
    printf("Enter account number\n");
    scanf("%s",account_number);

    printf("Enter the PIN\n");
    scanf("%d",&pin);

    while (fscanf(file, "%s %s %s %d %lf", currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, &currentaccount.PIN_NUMBER, &currentaccount.BALANCE) != EOF)
    {
        if ((strcmp(currentaccount.ACCOUNT_NUMBER,account_number)==0) &&(currentaccount.PIN_NUMBER==pin))
        {
            printf("Welcome to the ATM\n");

            printf("Enter the amount to deposite\n");
            scanf("%lf", &deposited_amount);

            currentaccount.BALANCE=currentaccount.BALANCE+ deposited_amount;
            deposit_success=1;
            //printf("Transaction cmpleted successfully\n Thankyou for using the ATM\n");
        }

        fprintf(temp_file,"%s %s %s %d %lf\n",currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, currentaccount.PIN_NUMBER, currentaccount.BALANCE);
        
    }

    fclose(file);
    fclose(temp_file);

    remove("ACCOUNT INFO.txt");
    rename("TEMPSAVING_ACCOUNT.txt", "ACCOUNT INFO.txt");

    if (deposit_success==1)
    {
        printf("Depposit successfully");
    }
    else
    {
        printf("Account not found\n");
    }
}

void displayBalance()
{
    char account_number[30];
    int pin;

    printf("Ether the account number\n");
    scanf("%s",account_number);

    printf("Enter the PIN\n");
    scanf("%d",&pin);

    FILE *file= fopen("ACCOUNT INFO.txt", "r");
    //FILE *temp_file=fopen("TEMPSAVING_ACCOUNT.txt", "w");

     if(file==NULL)
    {
        printf("Error occured\n");
        exit(1);
    }

    struct Accounts currentaccount;

    int account_found=0;

    while (fscanf(file, "%s %s %s %d %lf", currentaccount.NAME, currentaccount.ACCOUNT_NUMBER, currentaccount.MOBILE_NUMBER, &currentaccount.PIN_NUMBER, &currentaccount.BALANCE) != EOF)
    {
        if ((strcmp(currentaccount.ACCOUNT_NUMBER,account_number)==0) &&(currentaccount.PIN_NUMBER == pin))
        {
            printf("Welcome to the ATM\n");
            printf("Hi %s, you have %lf RS in your account\n",currentaccount.NAME,currentaccount.BALANCE);
            account_found = 1;
            break;
        }
    }

    fclose(file);

    if (!account_found)
    {
        printf("Account not found\n");
        exit(1);
    }
    
}

void customer_menu()
{
    printf("1.CASH WITHDRAWAL\n");
    printf("2.CASH DEPOSIT\n");
    printf("3.BALANCE ENQUIRY\n");
    printf("4.EXIT\n");
}

void employee_menu()
{
    printf("1.CREAT AN ACCOUNT\n");
    printf("2.UPDATE ACCOUNT\n");
    printf("3.EXIT\n");
}