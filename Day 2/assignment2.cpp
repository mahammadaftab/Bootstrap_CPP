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
             cout << "Warning: Initial balance cannot be negative. Set to $0." << endl;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\n✅ Success! Deposited: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
        } else {
            cout << "\n❌ Error: Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\n✅ Success! Withdrew: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "\n❌ Error: Insufficient funds." << endl;
        } else {
            cout << "\n❌ Error: Withdrawal amount must be positive." << endl;
        }
    }

    void checkBalance() {
        cout << "\n💰 Current Balance: $" << balance << endl;
    }

    void showAccountHolder() {
        cout << "\n👤 Account Holder Name: " << accountHolderName << endl;
    }
};

int main() {
    cout << "--- Welcome to CPP Bank ---" << endl;
    string name;
    cout << "Enter account holder name to create account: ";
    getline(cin, name); 

    BankAccount myAccount(name, 1000.00); // Opening with $1000
    cout << "Account created successfully!\n" << endl;

    int choice;
    double amount;

    do {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Show Account Holder" << endl; // <--- New Option Added
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                myAccount.checkBalance();
                break;
            case 4:
                myAccount.showAccountHolder();
                break;
            case 5:
                cout << "\nThank you for banking with us. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}