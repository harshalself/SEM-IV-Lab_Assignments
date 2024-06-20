/*Assignment 12: Min/max Heaps: Marks obtained by students of second year in an 
online examination of a particular subject are stored by the teacher. 
Teacher wants to find the minimum and maximum marks of the subject. 
Write a menu driven C++ program to find out maximum and minimum 
marks obtained in that subject using heap data structure. Analyze the 
algorithm*/


#include <iostream>
#include <algorithm> // Include the <algorithm> header to access the std::swap function
#include <climits>
using namespace std;

void buildMaxHeap(int arr[], int n) {
    int i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        int largest = i; // Declare and initialize the variable largest with the value of i
        int left = 2 * i + 1; // Initialize the variable left
        int right = 2 * i + 2; // Initialize the variable right
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            std::swap(arr[i], arr[largest]); // Use std::swap instead of swap
            buildMaxHeap(arr, n);
        }
    }
}

void buildMinHeap(int arr[], int n) {
    int i;
    for (i = (n / 2) - 1; i >= 0; i--) {
        int smallest = i;
        int left = 2 * i + 1; // Specify the namespace for the "left" variable
        int right = 2 * i + 2;
        if (left < n && arr[left] < arr[smallest]) // Specify the namespace for the "left" variable
            smallest = left; // Specify the namespace for the "left" variable
        if (right < n && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i) {
            std::swap(arr[i], arr[smallest]);
            buildMinHeap(arr, n);
        }
    }
}

int findMax(int arr[], int n) {
    if (n == 0)
        return INT_MIN;
    buildMaxHeap(arr, n);
    return arr[0];
}

int findMin(int arr[], int n) {
    if (n == 0)
        return INT_MAX;
    buildMinHeap(arr, n);
    return arr[0];
}

int main() {
    int max_size = 100; // Declare and initialize the variable max_size with the desired maximum size value
    int a[max_size];
    int size, choice;

    cout << "Enter the size of array:";
    cin >> size;

    int i; // Declare the variable "i"
    if (size <= 0 || size > max_size) {
        cout << "Invalid Size";
        return 1;
    }

    cout << "marks:";
    for (i = 0; i < size; i++) {
        cin >> a[i]; // Input marks into array 'a'
    }

    cout << "menu:";
    cout << "1.Max marks:";
    cout << "2.Min marks:";
    cout << "3.Exiting";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Maximum marks: " << findMax(a, size) << endl; // Pass the array 'a' instead of 'marks'
                break;
            case 2:
                cout << "Minimum marks: " << findMin(a, size) << endl; // Pass the array 'a' instead of 'marks'
                break;
            case 3:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
