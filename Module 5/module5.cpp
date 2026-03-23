#include <iostream>

using namespace std;

// Function for option 1
void addNumbers() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum: " << a + b << endl;
}

// Function for option 2
void viewMessage() {
    cout << "This is a simple menu program." << endl;
}

// Function to display menu
void showMenu() {
    cout << "\n1. Add\n2. View\n3. Exit\n";
}

int main() {

    int option;

    do {
        showMenu();
        cin >> option;

        // Call functions based on user choice
        if (option == 1) {
            addNumbers();
        }
        else if (option == 2) {
            viewMessage();
        }
        else if (option == 3) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }

    } while (option != 3);

    return 0;
}
