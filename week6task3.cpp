#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName = "example.txt";
    string userInput;
    string fileContent;

    ofstream outFile(fileName); 

    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    cout << "Enter text to write to file (type 'exit' to stop):" << endl;
    
    while (true) {
        getline(cin, userInput);
        if (userInput == "exit") {
            break;
        }
        outFile << userInput << endl; 
    }

    outFile.close(); 
    cout << "Data written to file successfully!" << endl << endl;

    ifstream inFile(fileName); 

    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }

    cout << "Reading from file:" << endl;
    cout << "-----------------" << endl;

    while (getline(inFile, fileContent)) {
        cout << fileContent << endl;
    }

    inFile.close();

    return 0;
}