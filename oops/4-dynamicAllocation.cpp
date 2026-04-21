#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int age,roll_number;
    string grade;
};

int main(){
    Student *s=new Student;
    (*s).name="Devanshu Kansal";
    s->age=10;
    s->roll_number=21;
    (*s).grade="A+";
    
    cout<<"The Name is: "<<s->name<<endl;
    cout<<"The Age is: "<<s->age<<endl;
    cout<<"The Roll Number is: "<<s->roll_number<<endl;
    cout<<"The Grade is: "<<s->grade<<endl;
}