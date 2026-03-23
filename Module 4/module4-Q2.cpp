#include <iostream>

using namespace std;

int main() {

    // Fixed: Added commas and semicolon to properly declare variables
    float n1, n2, n3;

    cout << "Enter three numbers: ";

    // Fixed: Corrected input operator (>> instead of >) and proper variables
    cin >> n1 >> n2 >> n3;

    // Fixed: Changed assignment (=) to comparison (>=) and added parentheses + opening brace
    if (n1 >= n2) {
        
        // Fixed: Nested if statement structure
        if (n1 >= n3) {
            cout << "Largest number: " << n1;
        } else {
            cout << "Largest number: " << n3;
        }

    } else {

        // Fixed: Nested if statement structure
        if (n2 >= n3) {
            cout << "Largest number: " << n2;
        } else {
            cout << "Largest number: " << n3;
        }
    }

    return 0;
}
