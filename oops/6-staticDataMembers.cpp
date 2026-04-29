// Static Data Member-They are attributes of classes or class members
// It is declared using static keyword
// Only one copy of that member is created for the entire class and is shared by all objects
// It is initialized before any object is created

#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number,balance;
    
    // we want that only one copy is created for entire class and shared by all the objects
    static int total_customer;
    
    public:
    Customer(string name,int account_number,int balance){
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        total_customer++;
    }
    
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<total_customer<<endl;
    }
    
    void display_total(){
        cout<<total_customer<<endl;
    }
};

// initialized the static data member
int Customer::total_customer=0;

int main(){
    Customer A1("Rohit",1,1000);
    A1.display();
    Customer A2("Mohit",2,2000);
    A2.display();
    Customer A3("Devanshu",3,3000);
    A3.display();
}