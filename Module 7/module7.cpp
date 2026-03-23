#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Class to represent one row of data
class DataEntry {
public:
    string country;
    int year;
    double povertyRate;
    double gdp;
    long population;

    // Function to display the data
    void display() {
        cout << "Country: " << country
             << " | Year: " << year
             << " | Poverty Rate: " << povertyRate
             << " | GDP: " << gdp
             << " | Population: " << population << endl;
    }
};

int main() {

    // Open the CSV file
    ifstream file("disuguaglianza-economica-globale-e-povert-1980-2024.csv");

    // Check if file opened successfully
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    vector<DataEntry> dataList;
    string line;

    // Skip header row (first line)
    getline(file, line);

    int count = 0;

    // Read each line from the file
    while (getline(file, line) && count < 10) {

        stringstream ss(line);
        string value;

        DataEntry entry;

        // Extract each column (adjust indices if needed)
        
        // Column 1: Country
        getline(ss, entry.country, ',');

        // Column 2: Year
        getline(ss, value, ',');
        entry.year = stoi(value);

        // Column 3: Poverty Rate
        getline(ss, value, ',');
        entry.povertyRate = stod(value);

        // Column 4: GDP
        getline(ss, value, ',');
        entry.gdp = stod(value);

        // Column 5: Population
        getline(ss, value, ',');
        entry.population = stol(value);

        // Add to vector
        dataList.push_back(entry);

        count++;
    }

    file.close();

    // Display the loaded data
    cout << "===== DATA OUTPUT =====" << endl;

    for (int i = 0; i < dataList.size(); i++) {
        dataList[i].display();
    }

    return 0;
}
