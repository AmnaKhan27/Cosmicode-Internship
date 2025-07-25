#include<iostream>
using namespace std;

int calculateGCD(int a, int b){
    while (b!=0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int num1, num2;
    cout<<"enter two numbers "<<endl;
    cin>>num1>>num2;

    int gcd=calculateGCD(num1,num2);
    cout<<"GCD of two numbers is:  "<<gcd;
}
    
