#include <iostream>
using namespace std;

// Using Pointers
void swapPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Using References
void swapReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5, num2 = 10;
    
    cout << "Original values: " << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl << endl;
    
    // using pointers
    swapPointers(&num1, &num2);
    cout << "After pointer swap: " << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl << endl;
    
    // using references
    swapReferences(num1, num2);
    cout << "After reference swap: " << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    
    return 0;
}