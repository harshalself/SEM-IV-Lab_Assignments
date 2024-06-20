#include <iostream>
using namespace std;

class Node {
public:
    int key;
    string value;
    Node* next;
    
    Node(int key, string value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class SeparateChaining {
public:
    static const int n = 10;
    Node* hashTable[n];
    
    SeparateChaining() {
        for (int i = 0; i < n; ++i)
            hashTable[i] = nullptr;
    }
    
    int hashFunction(int key) {
        return key % n;
    }
    
    void hashing(int key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        if (hashTable[index] == nullptr) {
            hashTable[index] = newNode;
        } else {
            newNode->next = hashTable[index];
            hashTable[index] = newNode;
        }
    }
    
    Node* search(int key) {
        int index = hashFunction(key);
        Node* temp = hashTable[index];

        while (temp != nullptr) {
            if (temp->key == key)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
    
    void display() {
        for (int i = 0; i < n; ++i) {
            cout << "Hash Table[ " << i << "] -> ";
            Node* temp = hashTable[i];
            while (temp != nullptr) {
                cout << "->(" << temp->key << ", " << temp->value << ")";
                temp = temp->next;
            }
            cout <<"->NULL"<<endl;
        }
    }
};


int main(){
    SeparateChaining sc;
    int ch;
    int key;
    string value;
    Node* found;
    do{
    cout<<"Menu.. "<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Search"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>ch;
    switch(ch){
        case 1:
          cout<<"Enter Key:"<<endl;
          cin>>key;
          cout<<"Enter Value: "<<endl;
          cin>>value;
          sc.hashing(key, value);
         break;
        case 2:
         cout<<"Enter Key to search:"<<endl;
         cin>>key;
         found = sc.search(key);
         if(found!=nullptr){
            cout<<"Key: "<<key<<"Value: "<<found->value<<" found!"<<endl;
         }
         else{
            cout<<key<<" not found!"<<endl;
         }
         break;
        case 3:
        sc.display();
         break;
        default:
         cout<<"Invalid Choice"<<endl;
    }
    }while(ch<=3);
}
