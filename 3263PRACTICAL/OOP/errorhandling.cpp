#include<bits/stdc++.h>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0f) {}
    void getData() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }
    virtual void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
    void reset() {
        title = "";
        price = 0.0f;
    }
};
class Book : public Publication {
    int pageCount;
public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData();

        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();
    }

    void displayData() const override {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }

    void reset() {
        Publication::reset();
        pageCount = 0;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    Tape() : playTime(0.0f) {}

    void getData() {
        Publication::getData();

        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
        cin.ignore();
    }

    void displayData() const override {
        Publication::displayData();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }

    void reset() {
        Publication::reset();
        playTime = 0.0f;
    }
};

int main() {
    try {
        Book book;
        Tape tape;

        cout << "Enter details for a book:\n";
        book.getData();

        cout << "\nEnter details for a tape:\n";
        tape.getData();

        cout << "\nDisplaying book details:\n";
        book.displayData();

        cout << "\nDisplaying tape details:\n";
        tape.displayData();
    } catch (...) {
        cout << "\nException caught. Resetting all data members to zero.\n";

        Book book;
        Tape tape;

        book.reset();
        tape.reset();

        cout << "\nDisplaying reset book details:\n";
        book.displayData();

        cout << "\nDisplaying reset tape details:\n";
        tape.displayData();
    }
    return 0;
}
