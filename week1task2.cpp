#include<iostream>
using namespace std;

int addFunc(){
    int a=3, b=6;
    return a+b;
}

int subFunc(){
    int a=3, b=6;
    return a-b;
}

int multiplyFunc(){
    int a=3, b=6;
    return a*b;
}

int divideFunc(){
    int a=6, b=3;
    return a/b;
}

int main(){
    cout<<"Addition: "<<addFunc()<<endl;
    cout<<"Subtraction: "<<subFunc()<<endl;
    cout<<"Multiplication: "<<multiplyFunc()<<endl;
    cout<<"Division: "<<divideFunc();

    return 0;
}