#include <iostream>
using namespace std;

/*
    ============================================
      Introduction to Object Oriented Programming
           Module 1 - Assignment #1
           XYZ Bank ATM Program
    --------------------------------------------
    Group Members:
    - Dain Thorpe
    - Shanique Wisdom
    - Joan Johnson-Brown
    - Dante Graham
    Date: November 2025
    ============================================
*/

// =====================================
// Account Class Definition
// =====================================
class Account {
private:
    // --- Private attribute (encapsulation)
    double balance; // stores customer's account balance

public:
    // --- Constructor: validate and set initial balance
    Account(double init_balance) {
        if (init_balance >= 1000) {
            balance = init_balance;
        } else {
            balance = 0;
            cout << "Invalid initial balance. Account set to $0.\n";
        }
    }

    // --- Deposit function: add funds to the balance
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // --- Withdraw function: ensure sufficient funds before debiting
    bool Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Debit amount exceeded account balance.\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawal successful.\n";
        return true;
    }

    // --- GetBalance function: return the current balance
    double GetBalance() const {
        return balance;
    }
};

// =====================================
// Main Program - ATM Menu
// =====================================
int main() {
    double initial;
    cout << "Enter your initial balance: ";
    cin >> initial;

    // Create Account object
    Account acc(initial);

    int option;
    do {
        // --- Display ATM Menu
        cout << "\n===== XYZ BANK ATM =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "=========================\n";
        cout << "Choose an option: ";
        cin >> option;

        // --- Process user selection
        switch (option) {
            case 1:
                cout << "Your current balance is: $" << acc.GetBalance() << endl;
                break;

            case 2: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc.Deposit(amount);
                break;
            }

            case 3: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc.Withdraw(amount);
                break;
            }

            case 4:
                cout << "Thank you for using XYZ Bank ATM.\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (option != 4); // keep menu running until user chooses Exit

    return 0;
}
