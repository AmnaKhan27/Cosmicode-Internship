#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <ctime>
using namespace std;

class LibraryItem {
protected:
    string title;
    int id;
public:
    LibraryItem(string t, int i) : title(t), id(i) {}
    virtual void display() = 0; 
    virtual ~LibraryItem() {}
    int getId() { return id; }  
    string getTitle() { return title; }  
};

class Book : public LibraryItem {
    string author;
public:
    Book(string t, string a, int i) : LibraryItem(t, i), author(a) {}
    void display() override {
        cout << "Book ID: " << getId() << "\nTitle: " << getTitle() 
             << "\nAuthor: " << author << endl;
    }
    string getAuthor() { return author; }  
};

class Member {
    int memberId;
    string name;
public:
    Member(int id, string n) : memberId(id), name(n) {}
    void display() {
        cout << "Member ID: " << memberId << "\nName: " << name << endl;
    }
    int getId() { return memberId; }
    string getName() { return name; }  
};

class Transaction {
    int bookId;
    int memberId;
    string date;
public:
    Transaction(int bId, int mId) : bookId(bId), memberId(mId) {
        time_t now = time(0);
        date = ctime(&now);
    }
    void display() {
        cout << "Transaction Details:\nBook ID: " << bookId 
             << "\nMember ID: " << memberId << "\nDate: " << date;
    }
};

class LibrarySystem {
    vector<shared_ptr<Book>> books;
    vector<Member> members;
    vector<Transaction> transactions;
    const string booksFile = "books.txt";
    const string membersFile = "members.txt";
    const string transactionsFile = "transactions.txt";
public:
    void addBook() {
        string title, author;
        int id;
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter book ID: ";
        cin >> id;
        cin.ignore();
        books.push_back(make_shared<Book>(title, author, id));
    }

    void addMember() {
        string name;
        int id;
        cout << "Enter member name: ";
        getline(cin, name);
        cout << "Enter member ID: ";
        cin >> id;
        cin.ignore();
        members.emplace_back(id, name);
    }

    void checkoutBook() {
        int bookId, memberId;
        cout << "Enter book ID to checkout: ";
        cin >> bookId;
        cout << "Enter member ID: ";
        cin >> memberId;
        cin.ignore();
        transactions.emplace_back(bookId, memberId);
    }

    void saveData() {
      
        ofstream bFile(booksFile);
        for (auto& book : books) {
            bFile << book->getTitle() << "," << book->getAuthor() << "," << book->getId() << "\n";
        }
        bFile.close();

        ofstream mFile(membersFile);
        for (auto& member : members) {
            mFile << member.getId() << "," << member.getName() << "\n";
        }
        mFile.close();

        cout << "Data saved successfully!\n";
    }

    void loadData() {
        
        ifstream bFile(booksFile);
        string line;
        while (getline(bFile, line)) {
            size_t comma1 = line.find(',');
            size_t comma2 = line.find(',', comma1+1);
            string title = line.substr(0, comma1);
            string author = line.substr(comma1+1, comma2-comma1-1);
            int id = stoi(line.substr(comma2+1));
            books.push_back(make_shared<Book>(title, author, id));
        }
        bFile.close();

        ifstream mFile(membersFile);
        while (getline(mFile, line)) {
            size_t comma = line.find(',');
            int id = stoi(line.substr(0, comma));
            string name = line.substr(comma+1);
            members.emplace_back(id, name);
        }
        mFile.close();

        cout << "Data loaded successfully!\n";
    }

    void displayAll() {
        cout << "\n=== Books ===\n";
        for (auto& book : books) book->display();
        
        cout << "\n=== Members ===\n";
        for (auto& member : members) member.display();
        
        cout << "\n=== Transactions ===\n";
        for (auto& trans : transactions) trans.display();
    }
};

int main() {
    LibrarySystem library;
    int choice;

    library.loadData(); 

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Add Member\n3. Checkout Book\n";
        cout << "4. Display All\n5. Save Data\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: library.addBook(); break;
            case 2: library.addMember(); break;
            case 3: library.checkoutBook(); break;
            case 4: library.displayAll(); break;
            case 5: library.saveData(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}