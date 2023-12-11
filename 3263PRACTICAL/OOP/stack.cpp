#include <bits/stdc++.h>
using namespace std;
string addBinary(string binary1, string binary2) {
    stack<int> result;
    int carry = 0;
    int i = binary1.length() - 1;
    int j = binary2.length() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += binary1[i] - '0';
            --i;
        }
        if (j >= 0) {
            sum += binary2[j] - '0';
            --j;
        }
        result.push(sum % 2);
        carry = sum / 2;
    }
    string sumBinary = "";
    while (!result.empty()) {
        sumBinary += to_string(result.top());
        result.pop();
    }
    return sumBinary;
}
int main() {
    string binary1, binary2;
    cout << "Enter first binary number: ";
    cin >> binary1;
    cout << "Enter second binary number: ";
    cin >> binary2;
    string sum = addBinary(binary1, binary2);
    cout << "Sum of " << binary1 << " and " << binary2 << " is: " << sum << endl;
    return 0;
}
