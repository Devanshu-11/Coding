// Abstraction- display only essential information and hiding the internal implementation details

#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number,balance,age;
    
    public:
    Customer(string name,int account_number,int balance,int age){
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        this->age=age;
    }
    
    void deposit(int amount){
        if(amount>0){
            balance=balance+amount;
        }else{
            cout<<"Invalid Amount"<<endl;
            return;
        }
    }
    
    void Withdraw(int amount){
        if(amount<=balance&&amount>0){
            balance=balance-amount;
        }else{
            cout<<"Invalid Amount"<<endl;
            return;
        }
    }
    
    void updateAge(int age){
        if(age>0&&age<=100){
            this->age=age;
        }else{
            cout<<"Invalid Age"<<endl;
            return;
        }
    }
    
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<age<<endl;
    }
};

int main(){
    Customer A1("Rohit",1,1000,12);
    A1.updateAge(24);
    Customer A2("Mohit",2,2000,16);
    Customer A3("Devanshu",3,3000,34);
    A1.deposit(1000);
    A1.display();
}