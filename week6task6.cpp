#include <iostream>
#include <memory>
using namespace std;

class Dog {
public:
    Dog(string name) : name(name) {
        cout << name << " says Woof!\n";
    }
    ~Dog() {
        cout << name << " goes to sleep\n";
    }
    void bark() {
        cout << name << " barks: Woof woof!\n";
    }
private:
    string name;
};

int main() {
    
    unique_ptr<Dog> dog1 = make_unique<Dog>("Rex");
    dog1->bark();
    
    shared_ptr<Dog> dog2 = make_shared<Dog>("Buddy");
    shared_ptr<Dog> alsoDog2 = dog2; 
    dog2->bark();
    alsoDog2->bark();
    
    weak_ptr<Dog> weakDog = dog2;
    
    cout << "End of main\n";
   
}