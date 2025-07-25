#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
  
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        ownerName = name;
        balance = initialBalance;
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

    void display() {
        cout << "\nAccount Information:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: Rs" << balance << endl;
    }
};

int main() {

    BankAccount myAccount("123456789", "Saad", 1000.00);

    myAccount.display();
    myAccount.deposit(500.50);
    myAccount.withdraw(200.75);
    myAccount.withdraw(2000.00); 
    myAccount.display();

    return 0;
}