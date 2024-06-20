/*A Dictionary using AVL: A Dictionary stores key and value pairs
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)
Write a menu driven C++ program to provide above standard operations
on dictionaries and provide a facility to display whole data sorted in
ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword.
Use Height balanced tree(AVL) and find the complexity for finding a
keyword*/

#include <iostream>
#include <string>
using namespace std;

class AVLNode {
public:
    string key;
    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(string k, string v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    AVLNode* insert(AVLNode* node, string key, string value) {
        if (node == nullptr)
            return new AVLNode(key, value);

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else {
            // Duplicate keys not allowed, you can modify as per your requirement
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* root, string key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr || root->right == nullptr) {
                AVLNode* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rotateRight(root);

        // Left Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return rotateLeft(root);

        // Right Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inOrder(AVLNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << "(" << root->key << ", " << root->value << ") ";
            inOrder(root->right);
        }
    }

    void reverseInOrder(AVLNode* root) {
        if (root != nullptr) {
            reverseInOrder(root->right);
            cout << "(" << root->key << ", " << root->value << ") ";
            reverseInOrder(root->left);
        }
    }

    AVLNode* findNode(AVLNode* root, string key, int& comparisons) {
        comparisons++;
        if (root == nullptr || root->key == key)
            return root;

        if (root->key < key)
            return findNode(root->right, key, comparisons);

        return findNode(root->left, key, comparisons);
    }

    int maxComparisons(AVLNode* root, string key) {
        int comparisons = 0;
        findNode(root, key, comparisons);
        return comparisons;
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(string key, string value) {
        root = insert(root, key, value);
    }

    void deleteKey(string key) {
        root = deleteNode(root, key);
    }

    void displayAscending() {
        cout << "Ascending Order: ";
        inOrder(root);
        cout << endl;
    }

    void displayDescending() {
        cout << "Descending Order: ";
        reverseInOrder(root);
        cout << endl;
    }

    int getMaxComparisons(string key) {
        return maxComparisons(root, key);
    }
};

int main() {
    AVLTree dictionary;
    int choice;
    string key, value;

    do {
        cout << "1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Delete\n";
        cout << "4. Display Ascending\n";
        cout << "5. Display Descending\n";
        cout << "6. Maximum Comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                if (dictionary.getMaxComparisons(key) > 0)
                    cout << "Key found\n";
                else
                    cout << "Key not found\n";
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.deleteKey(key);
                break;
            case 4:
                dictionary.displayAscending();
                break;
            case 5:
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Enter key to find maximum comparisons: ";
                cin >> key;
                cout << "Maximum comparisons required: " << dictionary.getMaxComparisons(key) << endl;
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}


