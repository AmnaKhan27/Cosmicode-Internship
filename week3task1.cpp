#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int num, count;
    
    cout << "Enter the number of integers: ";
    cin >> count;
    
    cout << "Enter " << count << " integers:" << endl;
    for (int i = 0; i < count; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    
    cout << "Original array: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted array: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}