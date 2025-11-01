#include <iostream>
using namespace std;

/*
    Intro to Object Oriented Programming
    Module 1 - Assignment #1
    Group Members:
    - Dain Thorpe
    - Shanique Wisdom
    - Joan Johnson-Brown

    Program:
    Simple ATM style console program for XYZ Bank.
    The user can:
      1. Check Balance
      2. Deposit
      3. Withdraw
      4. Exit

    The Account class stores the balance and handles
    deposits / withdrawals using functions.
*/

class Account {
private:
    double balance; // current account balance

public:
    // Constructor: set the starting balance.
    // If the starting balance is at least 1000,
    // we accept it. Otherwise, we set the balance to 0
    // and warn the user.
    Account(double initialBalance) {
        if (initialBalance >= 1000.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Invalid initial balance. Account set to $0." << endl;
        }
    }

    // Add money to the account
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Take money out of the account (if enough is there).
    // If not enough, show the required message:
    // "Debit amount exceeded account balance."
    void Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }

    // Return the current balance
    double GetBalance() {
        return balance;
    }
};

int main() {
    // ask user for starting money
    double start;
    cout << "Enter your initial balance: ";
    cin >> start;

    // make the user's bank account
    Account userAccount(start);

    int choice = 0;
    bool running = true;

    // loop until the user chooses Exit
    while (running) {
        cout << "\n======================================" << endl;
        cout << "            XYZ BANK ATM              " << endl;
        cout << "======================================" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            // Show balance
            cout << "\nYour Current Balance: $"
                 << userAccount.GetBalance() << endl;
        }
        else if (choice == 2) {
            // Deposit flow
            double amount;
            cout << "\nEnter amount to deposit: ";
            cin >> amount;
            userAccount.Deposit(amount);
        }
        else if (choice == 3) {
            // Withdraw flow
            double amount;
            cout << "\nEnter amount to withdraw: ";
            cin >> amount;
            userAccount.Withdraw(amount);
        }
        else if (choice == 4) {
            // Exit program
            cout << "\nThank you for using XYZ Bank ATM." << endl;
            running = false;
        }
        else {
            // Anything that isn't 1-4
            cout << "\nInvalid option. Please try again." << endl;
        }
    }

    return 0;
}