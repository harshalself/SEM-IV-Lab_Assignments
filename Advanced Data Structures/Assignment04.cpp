/*Assignment 4: Binary search tree: Write a menu driven C++ program to construct a 
binary search tree by inserting the values in the order give, considering at 
the beginning with an empty binary search tree, After constructing a 
binary tree-
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Search a value
v. Print values in ascending and descending order*/


#include<iostream>
#include<algorithm> // for std::max
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int value) { // Insert a new node with the given value
        if (node == nullptr) {
            node = new Node;
            node->data = value;
            node->left = node->right = nullptr;
        } else if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    int getHeight(Node* node) { // Get the height of the tree
        if (node == nullptr)
            return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int findMinValue(Node* node) { // Find the minimum value in the tree
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    bool searchValue(Node* node, int value) { // Search for a value in the tree
        if (node == nullptr)
            return false;
        if (node->data == value)
            return true;
        else if (value < node->data)
            return searchValue(node->left, value);
        else
            return searchValue(node->right, value);
    }

    void printAscending(Node* node) { // Print the values in ascending order
        if (node != nullptr) {
            printAscending(node->left);
            cout << node->data << " ";
            printAscending(node->right);
        }
    }

    void printDescending(Node* node) { // Print the values in descending order
        if (node != nullptr) {
            printDescending(node->right);
            cout << node->data << " ";
            printDescending(node->left);
        }
    }

    void insertNode() { // Insert a new node
        int value;
        cout << "Enter the value to insert: ";
        cin >> value;
        root = insert(root, value);
        cout << "Node inserted successfully.\n";
    }

    void findLongestPath() {
        int height = getHeight(root);
        cout << "Number of nodes in the longest path from the root: " << height << endl;
    }

    void findMinValue() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
        } else {
            int minValue = findMinValue(root);
            cout << "Minimum data value found in the tree: " << minValue << endl;
        }
    }

    void searchValue() {
        int value;
        cout << "Enter the value to search: ";
        cin >> value;
        if (searchValue(root, value)) {
            cout << "Value found in the tree.\n";
        } else {
            cout << "Value not found in the tree.\n";
        }
    }

    void printValues() {
        cout << "Ascending Order: ";
        printAscending(root);
        cout << "\nDescending Order: ";
        printDescending(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert new node\n";
        cout << "2. Find number of nodes in longest path from root\n";
        cout << "3. Minimum data value found in the tree\n";
        cout << "4. Search a value\n";
        cout << "5. Print values in ascending and descending order\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bst.insertNode();
                break;
            case 2:
                bst.findLongestPath();
                break;
            case 3:
                bst.findMinValue();
                break;
            case 4:
                bst.searchValue();
                break;
            case 5:
                bst.printValues();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}