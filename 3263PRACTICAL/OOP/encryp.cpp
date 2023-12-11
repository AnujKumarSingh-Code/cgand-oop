#include<bits/stdc++.h>
using namespace std;

string xorCipher(const string& text, char key) 
{
    string result = text;

    for (char& c : result) 
    {
        c ^= key;
    }
    return result;
}


void encryptFile(const string& inputFileName, const string& outputFileName, char key) 
{
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile || !outputFile) 
    {
        cerr << "Error opening files!" << endl;
        return;
    }

    string line;

    while (getline(inputFile, line)) 
    {
        string encryptedLine = xorCipher(line, key);
        outputFile << encryptedLine << endl;
    }

    inputFile.close();
    outputFile.close();
    cout << "File encrypted successfully." << endl;
}

void decryptFile(const string& inputFileName, const string& outputFileName, char key) 
{
    encryptFile(inputFileName, outputFileName, key); 
}

int main() 
{
    char choice;
    string inputFileName, outputFileName;
    char key;
    cout << "Menu:\n";
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter your choice (1/2): ";
    cin >> choice;
    
    switch (choice) 
    {
        case '1':
            cout << "Enter the name of the input file: ";
            getline(cin, inputFileName);
            cout << "Enter the name of the output file (encrypted): ";
            getline(cin, outputFileName);
            cout << "Enter encryption key character: ";
            cin >> key;
            encryptFile(inputFileName, outputFileName, key);
            break;

        case '2':
            cout << "Enter the name of the input file (encrypted): ";
            getline(cin, inputFileName);
            cout << "Enter the name of the output file (decrypted): ";
            getline(cin, outputFileName);
            cout << "Enter decryption key character: ";
            cin >> key;
            decryptFile(inputFileName, outputFileName, key);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    
    return 0;
}
