#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers; 
    
    cout << "Array elements accessed via pointer:\n";
 
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }
    
    cout << "\nArray elements accessed by moving pointer:\n";
  
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *ptr << endl;
        ptr++; 
    }
    
    return 0;
}