#include <iostream>
using namespace std;
// Function template for selection sort
template<typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
int main() {
    int intSize, floatSize;
    cout << "Enter the size of the integer array: ";
    cin >> intSize;
    int intArray[intSize];
    cout << "Enter " << intSize << " integers:\n";
    for (int i = 0; i < intSize; ++i) {
        cin >> intArray[i];
    }
    cout << "Enter the size of the float array: ";
    cin >> floatSize;
    float floatArray[floatSize];
    cout << "Enter " << floatSize << " floating-point numbers:\n";
    for (int i = 0; i < floatSize; ++i) {
        cin >> floatArray[i];
    }
    selectionSort(intArray, intSize);
    selectionSort(floatArray, floatSize);
    // Output sorted integer array
    cout << "\nSorted Integer Array:\n";
    for (int i = 0; i < intSize; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    // Output sorted float array
    cout << "\nSorted Float Array:\n";
    for (int i = 0; i < floatSize; ++i) {
        cout << floatArray[i] << " ";
    }
    cout << endl;
    return 0;
}
