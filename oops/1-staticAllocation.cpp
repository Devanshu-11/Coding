// Object Oriented Programming is a programming pattern where the software is designed using the objects which describes the real world entities and combine data(variables) and behavior(functions/methods) into a single unit
// Classes are the blueprint or user defined data types which contains variables and functions
// Objects are used to access the data and functions defined inside a class

#include<iostream>
using namespace std;

// Create class
class Student{
    public:
    string name;
    int age,roll_number;
    string grade;
};

int main(){
    Student s1; // object created(instance of class)
    s1.name="Devanshu";
    s1.age=10;
    s1.roll_number=1;
    s1.grade="A";
    cout<<"Name of s1 is: "<<s1.name<<endl;
    
    Student s2;
    s2.name="Mohit";
    s2.age=12;
    s1.roll_number=2;
    s1.grade="B";
    cout<<"Name of s2 is: "<<s2.name<<endl;
}