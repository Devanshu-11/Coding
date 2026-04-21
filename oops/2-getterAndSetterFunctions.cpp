#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int age,roll_number;
    string grade;
    
    // Implementing the setter functions
    public:
    void setName(string s){
        if(s.size()==0){
            cout<<"Invalid name";
            return;
        }
        name=s;
    }
    
    void setAge(int a){
        if(a<=0){
            cout<<"Age cannot be less than or equals to zero";
            return;
        }
        age=a;
    }
    
    void setRoll_Number(int r){
        roll_number=r;
    }
    
    void setGrade(string s){
        grade=s;
    }
    
    // Implementing the getter functions
    void getName(){
        cout<<name<<endl;
    }
    
    void getAge(){
        cout<<age<<endl;
    }
    
    void getRoll_Number(){
        cout<<roll_number<<endl;
    }
    
    string getGrade(int pin){
        if(pin==123){
            return grade;
        }
        
        return "Invalid Pin";
    }
};

int main(){
    Student s1;
    s1.setName("Devanshu Kansal");
    s1.setAge(10);
    s1.setRoll_Number(21);
    s1.setGrade("A+");
    s1.getName();
    s1.getAge();
    s1.getRoll_Number();
    cout<<s1.getGrade(123);
}