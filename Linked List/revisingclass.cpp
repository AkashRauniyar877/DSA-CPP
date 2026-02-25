#include<iostream>
#include<vector>
using namespace std;
class Student{
public:
    string name;
    int roll_no;
    float marks;
    Student(string name , int roll_no, float marks){ //if use same variable as declare then use this keyword
        this->name = name;
        this->roll_no = roll_no;
        this->marks = marks;

    }

};
void change(Student s){ // Use & to change 
    s.name = "Aman";
}

int main(){
    // Student s("Akash",72,97.87);
    // Student s;
    // s.name = "Akash Rauniyar";
    // s.roll_no = 23;
    // s.marks = 97.78;

   // cout<<s.name<<"\n";
    // s.name = "Ayush"; --> name change to ayush
    // cout<<s.name; 

    //  cout<<s.name<<"\n";
    // change(s);
    // cout<<s.name<<"\n"; // no change means--> pass by Value

    // CHANGE NAME THROUGH POINTER
     Student s("Akash",72,97.87);
     Student* ptr = &s;
     cout<<s.name<<"\n";
     (*ptr).name = "Ayush";
     ptr->marks = 95;
     cout<<s.name<<"\n";
     cout<<s.marks<<"\n";



}