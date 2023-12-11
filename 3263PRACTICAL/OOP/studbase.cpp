#include<bits/stdc++.h>
using namespace std;
class student{
    string name;
    int rollno;
    int year;
    string dob;
    string address;
    string bloodgrp;
    long long int teleph;
    int marks[3];
    static int totalstudents;
    public:
    student(): rollno(0), year(0), teleph(0) {
        marks[0] = marks[1] = marks[2] = 0;
        totalstudents++;
    }
    student(const string& n, int roll, int y,const string& date,const string& addr,const string& blood, long long int teleno,const int m[]): name(n), rollno(roll), year(y), dob(date), address(addr), bloodgrp(blood), teleph(teleno) {
        for(int i=0; i<3; i++){
            marks[i] = m[i];
        }
        totalstudents++;
    }
    student(const student& s) : name(s.name), rollno(s.rollno), year(s.year), dob(s.dob), address(s.address), bloodgrp(s.bloodgrp), teleph(s.teleph) {
        for(int i=0; i<3; i++){
            marks[i] = s.marks[i];
        }
        totalstudents++;
    }
    ~student(){
        totalstudents--;
    }
    friend class studentdatabase;
    static int gettotalstudents(){
        return totalstudents;
    }
    void displayInfo(){
        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<rollno<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Date of Birth: "<<dob<<endl;
        cout<<"Contact Address: "<<address<<endl;
        cout<<"Blood Group: "<<bloodgrp<<endl;
        cout<<"Telephone/Mobile Number: "<<teleph<<endl;
        cout<<"Marks: "<<marks[0]<< " "<<marks[1]<<" "<<marks[2]<< endl;
    }
};
int student::totalstudents = 0;
class studentdatabase{
    int size;
    student* students;
    public:
    studentdatabase(int n){
        students = new student[n];
        size = n;
    }
    void addstudent(const student& s, int index){
        if(index>=0 && index<size){
            students[index] = s;          
        } else{
            cout<<"Index out of range! "<<endl;
        }
    }
    void displayallstudents(){
        cout<<"-------------------------------------Displaying the information of all the students-----------------------------------"<<endl;
        for(int i=0; i<size; i++){
            cout<<"Student "<<i+1<<". Information: "<<endl;
            students[i].displayInfo();
            cout<<endl;
        }
    }
    ~studentdatabase(){
        delete[] students;
    }
};
int main(){
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    studentdatabase database(n);
    cout<<"-----------------------------------------Enter the details of the students---------------------------------------"<<endl;
    for(int i=0; i<n; i++){
        string name, dob, address, bloodgrp;
        int rollno, year;
        long long int teleph;
        int marks[3];
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        cout<<"Name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Roll Number: ";
        cin>>rollno;
        cout<<"Year: ";
        cin>>year;
        cout<<"Contact Address: ";
        cin.ignore();
        getline(cin, address);
        cout<<"Blood Group: ";
        cin>>bloodgrp;
        cout<<"Date of Birth: ";
        cin.ignore();
        getline(cin, dob);
        cout<<"telephone/mobile number: ";
        cin>>teleph;
        cout<<"Marks (3 values separated by space): ";
        for(int j=0; j<3; j++){
            cin>>marks[j];
        }
        student student1(name, rollno, year, dob, address, bloodgrp, teleph, marks);
        database.addstudent(student1,i);
    }
    database.displayallstudents();
    cout<<"Total Students in the database are: "<<student::gettotalstudents()<<endl;
    return 0;
}
