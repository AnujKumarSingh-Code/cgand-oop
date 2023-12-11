#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string filename;

    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int letterCount = 0, wordCount = 0, lineCount = 0;

    while (getline(file, line)) 
    {
        ++lineCount;
        istringstream iss(line);
        string word;
        while (iss >> word) 
        {
            ++wordCount;
            for (char letter : word) 
            {
                if (isalpha(letter)) 
                {
                    ++letterCount;
                }
            }
        }
    }

    cout << "Number of letters: " << letterCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;
    file.close();
    return 0;
}
