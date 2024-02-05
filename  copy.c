#include <stdio.h>
#include <stdlib.h>

char name[20], email[20], age[20];
int accountNumber, create_password, enteredAccount, enteredPassword, value = 0, number, balance = 5000;
char choice;
FILE *detail;

void create_account()
{
    printf("\t******************************************\n");
    printf("\t\tCreate your Account here\n");
    printf("\t******************************************\n\n");

    detail = fopen("Details.txt", "w");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    printf("Enter your name : ");
    scanf("%s", name);
    fprintf(detail, "Name : %s\n", name);

    printf("Enter your email : ");
    scanf("%s", email);
    fprintf(detail, "Email : %s\n", email);

    printf("Create an account number : ");
    scanf("%d", &accountNumber);
    fprintf(detail, "Account Number : %d\n", accountNumber);

    printf("Enter your age: ");
    scanf("%s", age);
    fprintf(detail, "Age : %s\n", age);

    printf("Create a password : ");
    scanf("%d", &create_password);
    fprintf(detail, "Password : %d\n", create_password);

    fclose(detail);
}
void accountDetails()
{
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    fscanf(detail, "Name : %s\n", name);
    fscanf(detail, "Email : %s\n", email);
    fscanf(detail, "Account Number : %d\n", &accountNumber);
    fscanf(detail, "Age : %s\n", age);
    fscanf(detail, "Password : %d\n", &create_password);
    fclose(detail);
    printf("Details\n");
    printf("Name : %s\n", name);
    printf("Email : %s\n", email);
    printf("Account Number : %d\n", accountNumber);
    printf("Age : %s\n", age);
    printf("Password : %d\n", create_password);
}
void accountBalance()
{
    printf("Accouint Balance\n");
    printf("Your Balance is  : %d rs\n", balance);
}
void changePassword()
{
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }

    fscanf(detail, "Password : %d\n", &create_password);
    fclose(detail);
    printf("Password : %d\n", create_password);
    printf("Enter your new password : ");
    scanf("%d", &create_password);
    detail = fopen("Details.txt", "w");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
    }
    fprintf(detail, "Name : %s\n", name);
    fprintf(detail, "Email : %s\n", email);
    fprintf(detail, "Account Number : %d\n", accountNumber);
    fprintf(detail, "Age : %s\n", age);
    fprintf(detail, "Password : %d\n", create_password);
    fclose(detail);
}
int login()
{
    printf("\n\t**************************\n");
    printf("\t\tLogin\n");
    printf("\t**************************\n");

    FILE *detail;
    detail = fopen("Details.txt", "r");
    if (detail == NULL)
    {
        printf("Error opening file!!\n");
        return 0;
    }

    fscanf(detail, "Name : %s\n", name);
    fscanf(detail, "Email : %s\n", email);
    fscanf(detail, "Account Number : %d\n", &accountNumber);
    fscanf(detail, "Age : %s\n", age);
    fscanf(detail, "Password : %d\n", &create_password);

    fclose(detail);

    printf("Enter your account number : ");
    scanf("%d", &enteredAccount);

    printf("Enter your password : ");
    scanf("%d", &enteredPassword);
    system("cls");
    if (enteredAccount == accountNumber && enteredPassword == create_password)
    {
        printf("Account Login Successfully\n");
        value = 1;
    }
    else
    {
        printf("Login Failed. Incorrect account number or password.\n");
    }
}
void loginMenu()
{
    printf("**********************************************\n");
    printf("Welcome to banking management System\n");
    printf("**********************************************\n");
    printf("\n1.Withdraw a Money");
    printf("\n2.Transfer a money");
    printf("\n3.Check a balance");
    printf("\n4.Account details");
    printf("\n5.Change a password");
    printf("\n6.loan");
    printf("\n7.Exit\n");
    printf("\nEnter your choice : \n");
    scanf("%c", &choice);

    switch (choice)
    {
    case '1':
        // withdraw();
        printf("Money has been withdrawn");
        break;
    case '2':
        // transfer();
        printf("Money has been transferred");
        // transfer();
        break;
    case '3':
        accountBalance();
        //    printf("your balance: %d\n",balance);
        break;
    case '4':
        system("cls");
        accountDetails();
        break;
    case '5':
        changePassword();
        // printf("password");
        break;
    case '6':
        // loan();
        printf("amount has been added in your account");
        break;
    case '7':
        printf("exit");
    default:
        system("cls");
        loginMenu();
        break;
    }
    printf("Enter 1 to show main menu : ");
    scanf("%d", &number);
    if (number == 1)
    {
        loginMenu();
    }
    else
    {
        exit(0);
    }
}
void mainMenu()
{
    printf("\t**************************\n");
    printf("\t\tMenu\n");
    printf("\t**************************\n");
    printf("(1) Create an Account\n");
    printf("(2) Log in\n");
    printf("(3) Exit\n");
    printf("Enter your choice : ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
        system("cls");
        create_account();
        printf("\nYour Account has been created");
        login();
        break;
    case '2':
        system("cls");
        login();
        break;
    case '3':
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        mainMenu();
        break;
    }
}

int main()
{
    printf("hello how are you ");
    mainMenu();
    if (value == 1)
    {
        loginMenu();
    }

    return 0;
}
