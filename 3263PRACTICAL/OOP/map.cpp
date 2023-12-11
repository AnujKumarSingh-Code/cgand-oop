#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> statePatientCount;
    // Inputting state names and patient counts
    int numStates;
    cout << "Enter the number of states: ";
    cin >> numStates;
    cin.ignore(); // Clear newline from input buffer
    for (int i = 0; i < numStates; ++i) {
        string stateName;
        int patientCount;
        cout << "Enter state name: ";
        getline(cin, stateName);
        cout << "Enter Covid19 patient count in " << stateName << ": ";
        cin >> patientCount;
        cin.ignore(); // Clear newline from input buffer

        statePatientCount[stateName] = patientCount;
    }
    string stateName;
    cout << "Enter the name of a state: ";
    getline(cin, stateName);
    // Finding the state in the map
    auto it = statePatientCount.find(stateName);
    if (it != statePatientCount.end()) {
        cout << "Covid19 Patient Count in " << stateName << " is: " << it->second << endl;
    } else {
        cout << "State not found in the record." << endl;
    }
    return 0;
}
