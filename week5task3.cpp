#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
 
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs" << amount << ". New balance: Rs" << balance << endl;
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

class SavingsAccount : public BankAccount {
private:
    double interestRate; 

public:

    SavingsAccount(string accNum, string name, double initialBalance, double rate)
        : BankAccount(accNum, name, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest applied: Rs" << interest << endl;
        cout << "New balance after interest: Rs" << balance << endl;
    }

    void display() const {
        BankAccount::display(); 
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {

    SavingsAccount mySavings("SAV123456", "ALI", 1000.00, 2.5);

    mySavings.deposit(500.00);
    mySavings.withdraw(200.00);
    mySavings.applyInterest();
    mySavings.display();

    return 0;
}