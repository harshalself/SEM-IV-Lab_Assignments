/*Assignment 11: Sequential File: The students’ club members (MemberID, name, phone, 
email) list is to be maintained. The common operations performed 
include these: add member, search member, delete member, and update 
the information. Write a menu driven C++ program that uses file 
operation to implement the same and perform all operations*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Member {
    int MemberID;
    char name[50];
    char phone[15];
    char email[50];
};

void addMember() {
    ofstream file("members.dat", ios::binary | ios::app);
    Member member;

    cout << "Enter Member ID: ";
    cin >> member.MemberID;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(member.name, 50);
    cout << "Enter Phone: ";
    cin.getline(member.phone, 15);
    cout << "Enter Email: ";
    cin.getline(member.email, 50);

    file.write(reinterpret_cast<char*>(&member), sizeof(Member));
    file.close();
    cout << "Member added successfully." << endl;
}

void searchMember() {
    ifstream file("members.dat", ios::binary);
    if (!file) {
        cout << "File not found." << endl;
        return;
    }

    int searchID;
    cout << "Enter Member ID to search: ";
    cin >> searchID;

    Member member;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&member), sizeof(Member))) {
        if (member.MemberID == searchID) {
            found = true;
            cout << "Member found:" << endl;
            cout << "Member ID: " << member.MemberID << endl;
            cout << "Name: " << member.name << endl;
            cout << "Phone: " << member.phone << endl;
            cout << "Email: " << member.email << endl;
            break;
        }
    }

    if (!found) {
        cout << "Member not found." << endl;
    }

    file.close();
}

void deleteMember() {
    ifstream inFile("members.txt", ios::binary);
    ofstream outFile("temp.txt", ios::binary);

    int deleteID;
    cout << "Enter Member ID to delete: ";
    cin >> deleteID;

    Member member;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&member), sizeof(Member))) {
        if (member.MemberID != deleteID) {
            outFile.write(reinterpret_cast<char*>(&member), sizeof(Member));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("members.dat");
    rename("temp.dat", "members.dat");

    if (found) {
        cout << "Member deleted successfully." << endl;
    } else {
        cout << "Member not found." << endl;
    }
}

void updateMember() {
    fstream file("members.dat", ios::binary | ios::in | ios::out);

    int updateID;
    cout << "Enter Member ID to update: ";
    cin >> updateID;

    Member member;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&member), sizeof(Member))) {
        if (member.MemberID == updateID) {
            found = true;
            
            cout << "Enter updated Name: ";
            cin.ignore();
            cin.getline(member.name, 50);
            cout << "Enter updated Phone: ";
            cin.getline(member.phone, 15);
            cout << "Enter updated Email: ";
            cin.getline(member.email, 50);

            file.seekp(file.tellg() - sizeof(Member));
            file.write(reinterpret_cast<char*>(&member), sizeof(Member));

            cout << "Member updated successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Member not found." << endl;
    }

    file.close();
}

int main() {
    char choice;
    do {
        cout << "\n1. Add Member\n";
        cout << "2. Search Member\n";
        cout << "3. Delete Member\n";
        cout << "4. Update Member\n";
        cout << "5. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                addMember();
                break;
            case '2':
                searchMember();
                break;
            case '3':
                deleteMember();
                break;
            case '4':
                updateMember();
                break;
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
