//
// Created by Moglan Calin-Stefan on 27-Dec-23.
//
#include <stdio.h>

void print_entry(){
    printf("------------Main Menu------------\n");
    printf("-----Welcome to Calin's app!-----\n");
    printf("Press 1 to log into the account!\n");
    printf("Press 2 to create an account!\n");
    printf("Press 3 to enter admin mode!\n");
    printf("Press 4 to save!\n");
    printf("Press 0 to exit the app!\n");
}
void print_authentication_account(){
    printf("Account authentication!\n");
    printf("Please input the username and password of your account!\n");
}
void print_account(){
    printf("Please choose what you want to do: \n");
    printf("Press 1 to edit the user!\n");
    printf("Press 2 to log into an financial account!\n");
    printf("Press 3 to create an financial account!\n");
    printf("Press 4 to see all the financial accounts!\n");
    printf("Press 5 to leave an review!\n");
    printf("Press 6 to see reviews!\n");
    printf("Press 0 to exit!\n");
}

void print_edit_user(){
    printf("___Edit user Menu___\n");
    printf("Please input what do you want to edit on the user!\n");
    printf("Press 1 to edit the username!\n");
    printf("Press 2 to edit the password!\n");
}

void print_edit_fin(){
    printf("___Edit financial account Menu___\n");
    printf("Please input what do you want to edit on the financial account!\n");
    printf("Press 1 to edit the first name!\n");
    printf("Press 2 to edit the last name!\n");
    printf("Press 3 to edit the password!\n");
}


void print_menu_user(){
    printf("Please choose what you want to do: \n");
    printf("Press 1 to edit the financial account!\n");
    printf("Press 2 to delete the financial account!\n");
    printf("Press 3 to add a new transaction!\n");
    printf("Press 4 to calculate the balance of the account!\n");
    printf("Press 5 to make a financial report!\n");
    printf("Press 0 to exit!\n");
}

void print_transaction_menu(){
    printf("___Transaction Menu___\n");
    printf("Please input the type of transaction you wish to make!\n");
    printf("Press 1 to make a deposit!\n");
    printf("Press 2 to make a withdraw!\n");
    printf("Press 3 to make a transfer!\n");
    printf("Press 4 to make a payment!\n");
}

void print_raports_menu(){
    printf("___Raports Menu___\n");
    printf("Press 1 to do an expense raport!\n");
    printf("Press 2 to do an income raport!\n");
    printf("Press 3 to do an account statement!\n");
    printf("Press 4 to do an transaction register!\n");
}

void print_admin_menu(){
    printf("___Welcome to admin Menu___\n");
    printf("Press 1 to show all accounts!\n");
    printf("Press 2 to show all financial accounts!\n");
    printf("Press 3 to show all transactions!\n");
    printf("Press 4 to show all the reviews!\n");
    printf("Press 0 to exit!\n");
}