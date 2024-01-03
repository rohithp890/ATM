ATM System
This is a ATM (Automated Teller Machine) system implemented in C and also with File handling. The system provides basic functionalities for both customers and employees, including creating an account, updating account information, cash withdrawal, cash deposit, and checking the account balance.

-Features-
Create Account: Employees can create new accounts by providing the customer's name, account number, mobile number, PIN code, and initial balance.

Update Account: Employees can update customer account information, specifically the mobile number.

Cash Withdrawal: Customers can withdraw cash from their accounts by providing their account number, PIN, and the withdrawal amount.

Cash Deposit: Customers can deposit cash into their accounts by providing their account number, PIN, and the deposit amount.

Balance Enquiry: Customers can check their account balance by providing their account number and PIN.

-How to Use-
Run the program.
Choose whether you are an employee (E) or a customer (C).
Follow the menu options to perform different operations.

-File Structure-
main.c: Contains the main program logic and user interface.
README.md: This file, providing information about the program.
ACCOUNT INFO.txt: Text file storing account information.
TEMPSAVING_ACCOUNT.txt: Temporary file used for account updates.

-Usage-
Compile the program using a C compiler.
Run the compiled executable.
Follow the on-screen instructions to perform different operations.

Example
Creating an Account (Employee)
ARE YOU AN EMPLOYEE(E) OR CUSTOMER(C)
E

1.CREATE AN ACCOUNT
2.UPDATE ACCOUNT
3.EXIT

Enter your choice
1

Enter your name
John Doe
Enter your ACCOUNT NUMBER
1234567890
Enter your MOBILE NUMBER
9876543210
Create your FOUR-DIGIT PIN CODE
1234
Enter your initial amount
1000
Account created successfully.

-Withdrawing Cash (Customer)-

ARE YOU AN EMPLOYEE(E) OR CUSTOMER(C)
C

1.CASH WITHDRAWAL
2.CASH DEPOSIT
3.BALANCE ENQUIRY
4.EXIT

Enter your choice
1

Enter the account number
1234567890
Enter the PIN
1234
Welcome to the ATM

Enter the amount to be withdrawn
500
Transaction completed
Thank you for using this ATM

-Notes-
Account information is stored in a text file named ACCOUNT INFO.txt.
Updates to account information are temporarily stored in TEMPSAVING_ACCOUNT.txt.
