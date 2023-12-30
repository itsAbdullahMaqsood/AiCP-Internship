#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

// Function prototypes
void displayMenu(int studentID);
void costSlab1(int matrix[ROWS][COLS]);
void costSlab2(int matrix[ROWS][COLS]);
void costSlab3(int matrix[ROWS][COLS]);

int main() {
    // Student ID
    int studentID;
    cout << "Enter student id: ";
    cin >> studentID;

    // Source data matrix
    int sourceMatrix[ROWS][COLS] = {
        {55, 65, 75},
        {120, 150, 170},
        {210, 230, 240}
    };

    // Display menu
    displayMenu(studentID);

    // User input
    int choice;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    // Menu loop
    while (choice >= 1 && choice <= 3) {
        switch (choice) {
        case 1:
            costSlab1(sourceMatrix);
            break;
        case 2:
            costSlab2(sourceMatrix);
            break;
        case 3:
            costSlab3(sourceMatrix);
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
            return 0;
        }

        // Ask the user if they want to continue
        char continueChoice;
        cout << "Do you want to continue? (y/n): ";
        cin >> continueChoice;

        if (continueChoice != 'y' && continueChoice != 'Y') {
            cout << "Exiting..." << endl;
            return 0;
        }

        // Display menu again
        displayMenu(studentID);

        // User input
        cout << "Enter your choice: " << endl;
        cin >> choice;
    }

    cout << "Exiting..." << endl;
    return 0;
}

// Function to display the menu
void displayMenu(int studentID) {
    cout << "Student ID: " << studentID << endl;
    cout << "1. Display bill of slab 1" << endl;
    cout << "2. Display bill of slab 2" << endl;
    cout << "3. Display bill of slab 3" << endl;
    cout << "4. Exit" << endl;
}

// Function to calculate and display cost for slab 1
void costSlab1(int matrix[ROWS][COLS]) {
    int units = matrix[0][2] - matrix[0][1];
    int cost = units * 10;
    cout << "Bill for slab 1: Rs. " << cost << endl;
}

// Function to calculate and display cost for slab 2
void costSlab2(int matrix[ROWS][COLS]) {
    int units = matrix[1][2] - matrix[1][1];
    int cost = units * 15;
    cout << "Bill for slab 2: Rs. " << cost << endl;
}

// Function to calculate and display cost for slab 3
void costSlab3(int matrix[ROWS][COLS]) {
    int units = matrix[2][2] - matrix[2][1];
    int cost = units * 20;
    cout << "Bill for slab 3: Rs. " << cost << endl;
}