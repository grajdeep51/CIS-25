#include <iostream>   // For input and output (cin, cout)
#include <fstream>    // For file handling (ifstream, ofstream)
#include <string>     // For using string type

using namespace std;

// Define a structure to store patient information
struct Patient {
    int id;             // Patient ID
    string name;        // Patient name
    int age;            // Patient age
    string gender;      // Patient gender
    string diagnosis;   // Patient diagnosis
};

// Function prototypes (declare functions before main)
void addPatient(Patient* patients, int& count);
void displayPatients(Patient* patients, int count);
int binarySearch(Patient* patients, int count, int id);
void updatePatient(Patient* patients, int count);
void saveToFile(Patient* patients, int count);
void loadFromFile(Patient* patients, int& count);
void sortPatients(Patient* patients, int count);

int main() {

    // Create a dynamic array of Patient objects (size 100)
    Patient* patients = new Patient[100];

    // Variable to track number of patients currently stored
    int count = 0;

    // Variable to store user's menu choice
    int choice;

    // Load existing patient data from file (if file exists)
    loadFromFile(patients, count);

    // Menu loop (runs until user chooses to exit)
    do {
        cout << "\n===== HOSPITAL MENU =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient (Binary Search)\n";
        cout << "4. Update Patient\n";
        cout << "5. Save to File\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Option 1: Add a new patient
        if (choice == 1) {
            addPatient(patients, count);
        }

        // Option 2: Display all patients
        else if (choice == 2) {
            displayPatients(patients, count);
        }

        // Option 3: Search for a patient using binary search
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            // Sort patients by ID before binary search (REQUIRED)
            sortPatients(patients, count);

            // Perform binary search
            int index = binarySearch(patients, count, id);

            // Check if patient was found
            if (index != -1) {
                cout << "Patient Found:\n";
                cout << "ID: " << patients[index].id << endl;
                cout << "Name: " << patients[index].name << endl;
                cout << "Age: " << patients[index].age << endl;
                cout << "Gender: " << patients[index].gender << endl;
                cout << "Diagnosis: " << patients[index].diagnosis << endl;
            } else {
                cout << "Patient not found.\n";
            }
        }

        // Option 4: Update patient information
        else if (choice == 4) {
            updatePatient(patients, count);
        }

        // Option 5: Save all patient data to file
        else if (choice == 5) {
            saveToFile(patients, count);
        }

        // Option 6: Exit program
        else if (choice == 6) {
            cout << "Good Bye!\n";
        }

        // Handle invalid input
        else {
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 6); // Loop until user chooses exit

    // Free dynamically allocated memory
    delete[] patients;

    return 0;
}

// Function to add a new patient
void addPatient(Patient* patients, int& count) {

    // Prompt user for patient details
    cout << "Enter ID: ";
    cin >> patients[count].id;

    cout << "Enter Name: ";
    cin >> patients[count].name;

    cout << "Enter Age: ";
    cin >> patients[count].age;

    cout << "Enter Gender: ";
    cin >> patients[count].gender;

    cout << "Enter Diagnosis: ";
    cin >> patients[count].diagnosis;

    // Increase count after adding patient
    count++;
}

// Function to display all patients
void displayPatients(Patient* patients, int count) {

    // Loop through all stored patients
    for (int i = 0; i < count; i++) {
        cout << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << endl;
    }
}

// Function to perform binary search on patient IDs
int binarySearch(Patient* patients, int count, int id) {

    int left = 0;
    int right = count - 1;

    // Continue searching while range is valid
    while (left <= right) {

        int mid = (left + right) / 2;

        // If ID is found, return index
        if (patients[mid].id == id)
            return mid;

        // If target ID is larger, search right half
        else if (patients[mid].id < id)
            left = mid + 1;

        // Otherwise search left half
        else
            right = mid - 1;
    }

    // Return -1 if not found
    return -1;
}

// Function to sort patients by ID (needed for binary search)
void sortPatients(Patient* patients, int count) {

    // Simple bubble sort
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {

            // Swap if out of order
            if (patients[i].id > patients[j].id) {
                Patient temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }
}

// Function to update patient information
void updatePatient(Patient* patients, int count) {

    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    // Search for patient by ID
    for (int i = 0; i < count; i++) {

        if (patients[i].id == id) {

            // Update fields
            cout << "Enter new name: ";
            cin >> patients[i].name;

            cout << "Enter new age: ";
            cin >> patients[i].age;

            cout << "Enter new diagnosis: ";
            cin >> patients[i].diagnosis;

            return;
        }
    }

    // If not found
    cout << "Patient not found.\n";
}

// Function to save patients to a file
void saveToFile(Patient* patients, int count) {

    ofstream file("patients.txt");

    // Write each patient to file
    for (int i = 0; i < count; i++) {
        file << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << endl;
    }

    file.close();

    cout << "Data saved to file.\n";
}

// Function to load patients from file
void loadFromFile(Patient* patients, int& count) {

    ifstream file("patients.txt");

    // If file doesn't exist, do nothing
    if (!file)
        return;

    // Read data until end of file
    while (file >> patients[count].id
                >> patients[count].name
                >> patients[count].age
                >> patients[count].gender
                >> patients[count].diagnosis) {

        count++;
    }

    file.close();
}
