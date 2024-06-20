/*Assignment 13: A Dictionary using STL map and Hashmap: Implement Dictionary 
(key and value pairs) using using STL map in C++ and Hashmap in 
Java and compare all dictionary implementation 
1. BST
2. AVL
3. User defined Hash table
4. STL Map 
5. Hashmap in Java
Use Visual C++*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

void searchDictionary(const map<string, string>& dict, const string& key) {
    auto it = dict.find(key);
    if (it != dict.end()) {
        cout << "Meaning of '" << key << "': " << it->second << endl;
    } else {
        cout << "Key not found in dictionary." << endl;
    }
}

void displayDictionary(const map<string, string>& dict) {
    if (dict.empty()) {
        cout << "Dictionary is empty." << endl;
        return;
    }

    cout << "Existing Dictionary:" << endl;
    for (const auto& pair : dict) {
        cout << "Meaning of '" << pair.first << "': " << pair.second << endl;
    }
}

int main() {
    map<string, string> dict;

    int choice;

    do {
        cout << "\n---------- Dictionary Management System ----------\n";
        cout << "1. Add Word\n";
        cout << "2. Search Word\n";
        cout << "3. Display Dictionary\n";
        cout << "4. Exit\n";
        cout << "--------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string key, meaning;
                cout << "Enter a word to add: ";
                cin >> key;
                cout << "Enter the meaning of '" << key << "': ";
                cin.ignore();
                getline(cin, meaning);
                dict[key] = meaning;
                cout << "Word added successfully!" << endl;
                break;
            }
            case 2: {
                string key;
                cout << "Enter the word to search: ";
                cin >> key;
                searchDictionary(dict, key);
                break;
            }
            case 3: {
                displayDictionary(dict);
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
