/* Assignment 6: A Dictionary using BST: A Dictionary stores key and value pairs 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be 
comparable, Keys must be unique. 
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations 
on dictionaries and provide a facility to display whole data sorted in 
ascending/ Descending order. Also find how many maximum 
comparisons may require for finding any keyword. 
Use Binary Search Tree for implementation */

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* createNode(string key, string value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Memory error\n";
            return NULL;
        }
        newNode->key = key;
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    Node* insertNode(Node* root, string key, string value) {
        if (root == NULL) {
            root = createNode(key, value);
        } else if (key < root->key) {
            root->left = insertNode(root->left, key, value);
        } else {
            root->right = insertNode(root->right, key, value);
        }
        return root;
    }

    void printInOrder(Node* root) {
        if (root == NULL)
            return;
        printInOrder(root->left);
        cout << root->key << " : " << root->value << "\n";
        printInOrder(root->right);
    }

    void printReverseOrder(Node* root) {
        if (root == NULL)
            return;
        printReverseOrder(root->right);
        cout << root->key << " : " << root->value << "\n";
        printReverseOrder(root->left);
    }

    int searchKey(Node* root, string key, int count = 0) {
        if (root == NULL) {
            return -1;
        } else if (root->key == key) {
            return count;
        } else if (key < root->key) {
            return searchKey(root->left, key, count + 1);
        } else {
            return searchKey(root->right, key, count + 1);
        }
    }

    Node* deleteNode(Node* root, string key) {
        if (root == NULL)
            return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

public:
    BST() {
        root = NULL;
    }

    void insert(string key, string value) {
        root = insertNode(root, key, value);
    }

    void remove(string key) {
        root = deleteNode(root, key);
    }

    int search(string key) {
        return searchKey(root, key);
    }

    void printAscending() {
        printInOrder(root);
    }

    void printDescending() {
        printReverseOrder(root);
    }
};

int main() {
    BST bst;
    int choice;
    string key, value;
    while (true) {
        cout << "1. Insert\n"
             << "2. Delete\n"
             << "3. Search\n"
             << "4. Print (ascending)\n"
             << "5. Print (descending)\n"
             << "6. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter key and value to insert: ";
            cin >> key >> value;
            bst.insert(key, value);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            bst.remove(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            int result;
            result = bst.search(key);
            if (result != -1)
                cout << "Found with " << result << " comparisons\n";
            else
                cout << "Not found\n";
            break;
        case 4:
            bst.printAscending();
            break;
        case 5:
            bst.printDescending();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}