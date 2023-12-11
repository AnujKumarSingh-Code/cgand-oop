#include <bits/stdc++.h>
using namespace std;
struct PersonalRecord {
    string name;
    string dob;
    string phoneNumber;
};
bool compareByName(const PersonalRecord &a, const PersonalRecord &b) {
    return a.name < b.name;
}
int main() {
    vector<PersonalRecord> records;
    // Inputting personal records
    cout << "Enter personal records (Name, DOB, Phone Number), type 'exit' to stop:\n";
    while (true) {
        PersonalRecord record;
        cout << "Name: ";
        getline(cin, record.name);
        if (record.name == "exit") {
            break;
        }
        cout << "DOB: ";
        getline(cin, record.dob);
        cout << "Phone Number: ";
        getline(cin, record.phoneNumber);
        records.push_back(record);
    }
    // Sorting records by name using STL sort
    sort(records.begin(), records.end(), compareByName);
    // Displaying sorted records
    cout << "\nSorted Records by Name:\n";
    for (const auto &record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob
             << ", Phone Number: " << record.phoneNumber << "\n";
    }
    // Searching for a specific record by name using binary search
    string searchName;
    cout << "\nEnter a name to search for: ";
    getline(cin, searchName);

    auto it = lower_bound(records.begin(), records.end(), searchName,
                           [](const PersonalRecord &rec, const string &name) {
                               return rec.name < name;
                           });
    if (it != records.end() && it->name == searchName) {
        cout << "Record found:\n";
        cout << "Name: " << it->name << ", DOB: " << it->dob
             << ", Phone Number: " << it->phoneNumber << "\n";
    } else {
        cout << "Record not found.\n";
    }
    return 0;
}
