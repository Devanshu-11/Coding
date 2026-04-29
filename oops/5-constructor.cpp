// Constructor-It is a special function that is invoked automatically at the time of object creation
// Name of constructor should be named as class name 
// It does not have any return type not even void
// It is used to initialize the value 
// This Keyword- It is a pointer that points to the current object
// If you define any constructor, the compiler does not generate a default constructor automatically

// Types of Constructor-
// 1- Default Constructor-No arguments are passed
// 2- Parameterized constructor-arguments are passed

// Destructor-It is an instance member function that is invoked automatically whenever the object is going to be deleted 
// It is the last function that is going to be called before an object is destroyed
// Also destructor has same name that of class and it has no return type, not even void


#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number;
    int balance;
    
    // Note-This is example of constructor overloading which means we have multiple constructor of same class with the same name but having different parameters lists
    public:
    
    // Default constructor
    Customer(){
        cout<<"Default constructor is called"<<endl;    
    }
    
    // Parameterized constructor
    Customer(string name,int account_number,int balance){
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
    }
    
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<endl;
    }
    
    // Copy constructor
    Customer(Customer &B){
        name=B.name;
        account_number=B.account_number;
        balance=B.balance;
    }
    
    // Destructor and if i use dynamic memory,i need to delete it using delete Keyword, Destructor does not delete heap memory from itself
    ~Customer(){
        cout<<"Destructor is called"<<endl;
    }
};

int main(){
    Customer A1;
    Customer A2("Devanshu",1,30000);
    Customer A3;
    A2.display();
    Customer A4(A2);
    A4.display();
    
    // Assignment Operator
    Customer A5;
    A5=A2;
    A5.display();
}