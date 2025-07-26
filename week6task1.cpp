#include <iostream>
#include <algorithm> 
using namespace std;

template <typename T>
void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int intArr[] = {5, 2, 9, 1, 5};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    cout << "Original integer array: ";
    printArray(intArr, intSize);
    
    sortArray(intArr, intSize);
    
    cout << "Sorted integer array: ";
    printArray(intArr, intSize);
    
    double doubleArr[] = {3.2, 1.5, 4.7, 2.1};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    
    cout << "\nOriginal double array: ";
    printArray(doubleArr, doubleSize);
    
    sortArray(doubleArr, doubleSize);
    
    cout << "Sorted double array: ";
    printArray(doubleArr, doubleSize);
    
    char charArr[] = {'z', 'a', 'c', 'b'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    
    cout << "\nOriginal char array: ";
    printArray(charArr, charSize);
    
    sortArray(charArr, charSize);
    
    cout << "Sorted char array: ";
    printArray(charArr, charSize);

    return 0;
}