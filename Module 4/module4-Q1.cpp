#include <iostream>

using namespace std;

int main() {

    int choice;

    cout << "===== MENU =====" << endl;
    cout << "1. Say Hello" << endl;
    cout << "2. Add Two Numbers" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    // Option 1
    if (choice == 1) {
        cout << "Hello! Welcome to the program." << endl;
    }

    // Option 2
    else if (choice == 2) {
        int a, b;

        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Sum: " << a + b << endl;
    }

    // Option 3
    else if (choice == 3) {
        cout << "Exiting program..." << endl;
    }

    // Invalid input
    else {
        cout << "Invalid choice. Try again." << endl;
    }

    return 0;
}
