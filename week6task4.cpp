#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    
    map<string, int> ageMap;

    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 35;
    ageMap.insert({"David", 40}); 

    cout << "Initial Map Contents:" << endl;
    for (const auto& pair : ageMap) {
        cout << pair.first << ": " << pair.second << " years" << endl;
    }
    cout << endl;

    cout << "Bob's age: " << ageMap["Bob"] << " years" << endl;
    cout << "Charlie's age: " << ageMap.at("Charlie") << " years" << endl << endl;

    string name = "Alice";
    if (ageMap.find(name) != ageMap.end()) {
        cout << name << " found in the map!" << endl;
    } else {
        cout << name << " not found in the map!" << endl;
    }

    ageMap["Alice"] = 26;
    cout << "Updated Alice's age to: " << ageMap["Alice"] << endl << endl;

    ageMap.erase("Bob");
    cout << "After removing Bob:" << endl;
    for (const auto& pair : ageMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    cout << "Current map size: " << ageMap.size() << endl;

    ageMap.clear();
    cout << "Map cleared. New size: " << ageMap.size() << endl;

    return 0;
}