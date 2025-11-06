#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;

public:

    BankAccount(string name, double initialBalance) {
        accountHolderName = name;
        
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Initial balance cannot be negative. Balance set to 0." << endl;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful." << endl;
            cout << "New balance: $" << balance << endl;
        } else {

            cout << "Error: Deposit amount must be greater than 0." << endl;
            cout << "Transaction cancelled. Current balance remains: $" << balance << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
            cout << "New balance: $" << balance << endl;
        } else if (amount <= 0) {
            cout << "Error: Withdrawal amount must be greater than 0." << endl;
        } else { 
            cout << "Error: Insufficient funds." << endl;
            cout << "Transaction cancelled. Current balance remains: $" << balance << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void displayAccountHolderName() {
        cout << "Account Holder: " << accountHolderName << endl;
    }
};

int main() {

    BankAccount myAccount("Alex Johnson", 1000.00);
    
    int choice;
    double amount;

    do {

        cout << "\n--- CPP Bank Menu ---" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Check Account Holder Name" << endl;
        cout << "5. Exit" << endl;
        cout << "---------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;

            case 3:
                myAccount.checkBalance();
                break;

            case 4:
                myAccount.displayAccountHolderName();
                break;

            case 5:
                cout << "Thank you for using CPP Bank. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please select from 1-5." << endl;
        }

    } while (choice != 5);

    return 0;
}