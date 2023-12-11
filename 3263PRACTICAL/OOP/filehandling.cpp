#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // Creating and writing to the output file
    ofstream outFile("output.txt");

    if (outFile.is_open()) 
    {
        string poem;

        ofstream fout("poem.txt", ios::app);

        if (!fout.is_open())
        {
            cerr << "error in opening the file" << endl;
            return -1;
        }

        cout << "Enter your dasta here" << endl;

        while (true)
        {
            getline(cin, poem);

            if (poem == "endl")
            {
                break;
            }

            fout << poem << endl;
        }

        cout << "file writing completed" << endl;

        fout.close();
    } 

    else 
    {
        cout << "Unable to open the file for writing!\n";
        return 1;
    }
    // Reopening the file for reading
    ifstream inFile("output.txt");

    if (inFile.is_open()) 
    {
        cout << "Reading data from the file:\n\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << '\n';
        }
        inFile.close();
    } 

    else 
    {
        cout << "Unable to open the file for reading!\n";
        return 1;
    }
    return 0;
}
