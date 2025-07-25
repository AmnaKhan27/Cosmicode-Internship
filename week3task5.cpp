#include <iostream>
using namespace std;

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge while both arrays have elements
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    
    // Add remaining elements from arr1
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    
    // Add remaining elements from arr2
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    // Example sorted arrays
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {2, 4, 6, 8, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    // Create result array
    int result[size1 + size2];
    
    // Merge the arrays
    mergeSortedArrays(arr1, size1, arr2, size2, result);
    
    // Print the results
    cout << "First array: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "Second array: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    cout << "Merged sorted array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}