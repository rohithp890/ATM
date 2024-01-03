#include "atmrealproject-header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {
        char usertype;
        printf("ARE YOU AN EMPLOYEE(E) OR CUSTOMER(C)\n");
        scanf(" %c",&usertype);

    if (usertype=='e' || usertype == 'E')
    {
        employee_menu();

        int choice;

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: 
                createaccount();
               // exit(0);
                break;
        
        case 2:
                updateAccount();
               // exit(0);
                break;
        
        case 3:
                exit(0);
        
        default:
                printf("invalid choice\n");
               // exit(0);
                break;
        }
    }

    else if (usertype =='c' || usertype == 'C')
    {
      customer_menu();

      int choice;

      printf("Enter your choice\n");
      scanf("%d",&choice);

      switch (choice)
      {
        case 1:
                    cash_withdrawal();
                   // exit(0);
                    break;
    
        case 2:
                    cash_deposit();
                   // exit(0);
                    break;

        case 3:
                    displayBalance();
                   // exit(0);
                    break;

        case 4:
                    exit(0);

        default:
                    printf("Invalid choice\n");
                    break;
      }  
    }

    else
    {
        printf("Invalid usertype, Enter 'E' or 'C'\n");
    }
    
    }

    return 0;
    
}

