#include <iostream>
#include <stdexcept>

using namespace std;

double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed!");
    }
    return numerator / denominator;
}

int main() {
    double num1, num2, result;
    
    cout << "Enter the numerator: ";
    cin >> num1;
    
    cout << "Enter the denominator: ";
    cin >> num2;
    
    try {
        result = divideNumbers(num1, num2);
        cout << "Result of division: " << result << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    cout << "Program continues after exception handling." << endl;
    
    return 0;
}