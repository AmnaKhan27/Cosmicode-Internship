#include <iostream>
using namespace std;

int main() {
    int numbers[] = {12, 45, 67, 23, 9, 54, 32};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    
    int *ptr = numbers;
    int min = *ptr;    
    int max = *ptr;     

    for(int i = 1; i < size; i++) {
        if(*(ptr + i) < min) min = *(ptr + i);
        if(*(ptr + i) > max) max = *(ptr + i);
    }
    
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    
    return 0;
}