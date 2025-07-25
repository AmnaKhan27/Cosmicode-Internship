#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    istringstream iss(sentence);
    string word, longestWord;
    int maxLength = 0;
    
    while (iss >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
    }
    
    if (maxLength > 0) {
        cout << "The longest word is: \"" << longestWord << "\" with " 
             << maxLength << " characters." << endl;
    } else {
        cout << "No words found in the input." << endl;
    }
    
    return 0;
}