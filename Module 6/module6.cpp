#include <iostream>
#include <fstream>
#include <iomanip> // for formatting money
using namespace std;

// 1. Item Class
class Item {
public:
    string name;
    double price;
    int quantity;

    double getTotalPrice() {
        return price * quantity;
    }
};

// Function to display menu
void showMenu() {
    cout << "\n===== SHOPPING CART MENU =====\n";
    cout << "1. Add item to cart\n";
    cout << "2. View checkout\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

// 3. Add Item to Cart (write to file)
void addItem() {
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;

    cout << "Enter item price: ";
    cin >> item.price;

    cout << "Enter item quantity: ";
    cin >> item.quantity;

    // Open file in append mode
    ofstream file("cart.txt", ios::app);

    // Save item in required format
    file << item.name << " " << item.price << " " << item.quantity << endl;

    file.close();

    cout << "Item added to cart.\n";
}

// 4. View Checkout (read from file)
void viewCheckout() {
    ifstream file("cart.txt");

    Item item;
    double total = 0;

    cout << "\n===== CHECKOUT =====\n";

    // Read until end of file
    while (file >> item.name >> item.price >> item.quantity) {
        double itemTotal = item.getTotalPrice();

        cout << item.name << " - $"
             << fixed << setprecision(2) << item.price
             << " x " << item.quantity
             << " = $" << itemTotal << endl;

        total += itemTotal;
    }

    cout << "------------------------\n";
    cout << "Total: $" << fixed << setprecision(2) << total << endl;

    file.close();
}

int main() {
    int option;

    do {
        showMenu();
        cin >> option;

        if (option == 1) {
            addItem();
        }
        else if (option == 2) {
            viewCheckout();
        }
        else if (option == 3) {
            cout << "Thank you for shopping!\n";
        }
        else {
            cout << "Invalid option.\n";
        }

    } while (option != 3);

    return 0;
}
