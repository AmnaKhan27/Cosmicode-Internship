#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;
    
    if (n < 2) {
        cout << "Not prime";
        return 0;
    }
    
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "Not prime";
            return 0;
        }
    }
    
    cout << "Prime";
    return 0;
}
