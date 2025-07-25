#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:

    BankAccount(string accNum, string name, double initialBalance) 
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {
        cout << "Account created for " << ownerName << " with account number " 
             << accountNumber << endl;
        cout << "Initial balance: Rs" << balance << "\n" << endl;
    }

    BankAccount() : accountNumber(""), ownerName(""), balance(0.0) {
        cout << "Empty account created" << endl;
    }

    ~BankAccount() {
        cout << "\nAccount " << accountNumber << " belonging to " 
             << ownerName << " is being closed." << endl;
        cout << "Final balance: Rs" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs" << amount << ". New balance: Rs" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs" << amount << ". New balance: Rs" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    void display() const {
        cout << "\nAccount Information:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: Rs" << balance << endl;
    }
};

int main() {
    
    BankAccount account1("123456789", "Saad", 1000.00);
    account1.deposit(500.50);
    account1.withdraw(200.75);
    account1.display();

    BankAccount account2;
    account2.display();

    return 0;
}