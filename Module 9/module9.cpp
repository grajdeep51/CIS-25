#include <iostream>
#include <string>

using namespace std;

// Base class
class User {
protected:
    string username; // stores the user's name

public:
    // Constructor to initialize username
    User(string name) {
        username = name;
    }

    // Virtual function to be overridden
    virtual void accessLevel() {
        cout << username << ": Basic user access\n";
    }
};

// Derived class: Employee
class Employee : public User {
public:
    // Constructor calls base class constructor
    Employee(string name) : User(name) {}

    // Override accessLevel function
    void accessLevel() override {
        cout << username << ": View inventory\n";
    }
};

// Derived class: Manager
class Manager : public User {
public:
    Manager(string name) : User(name) {}

    void accessLevel() override {
        cout << username << ": View and update inventory\n";
    }
};

// Derived class: Admin
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void accessLevel() override {
        cout << username << ": Full access - add, update, delete inventory\n";
    }
};

int main() {

    // Create objects of each role
    User* user1 = new Employee("Alice");
    User* user2 = new Manager("Bob");
    User* user3 = new Admin("Charlie");

    // Demonstrate polymorphism
    user1->accessLevel();
    user2->accessLevel();
    user3->accessLevel();

    // Free memory
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
