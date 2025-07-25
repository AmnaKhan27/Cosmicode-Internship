#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Some animal sound" << endl;
    }
    
    virtual ~Animal() {
        cout << "Animal destroyed" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
    
    ~Dog() override {
        cout << "Dog destroyed" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
    
    ~Cat() override {
        cout << "Cat destroyed" << endl;
    }
};

int main() {
    Animal* myAnimal;
    
    myAnimal = new Dog();
    myAnimal->speak();
    delete myAnimal;
    
    myAnimal = new Cat();
    myAnimal->speak();  
    delete myAnimal;
    
    myAnimal = new Animal();
    myAnimal->speak();
    delete myAnimal;

    return 0; 
}