#include <iostream>
using namespace std;

class SecretData {
private:
    int secretNumber = 42;
    string secretMessage = "Hello friend!";
    
    friend void revealSecret(SecretData);
    
    friend class TrustedFriend;
};

void revealSecret(SecretData s) {
    cout << "The secret number is: " << s.secretNumber << endl;
}

class TrustedFriend {
public:
    void showMessage(SecretData s) {
        cout << "The secret message is: " << s.secretMessage << endl;
    }
};

int main() {
    SecretData data;

    revealSecret(data);
    
    TrustedFriend buddy;
    buddy.showMessage(data);
    
    return 0;
}