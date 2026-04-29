#include<iostream>
using namespace std;

class Customer{
    string name;
    int account_number,balance;
    static int total_customer;
    static int total_balance;
    
    public:
    Customer(string name,int account_number,int balance){
        this->name=name;
        this->account_number=account_number;
        this->balance=balance;
        total_customer++;
        total_balance=total_balance+balance;
    }
    
    // to access the private static data member using static member function and it cannot access non-static data members
    static void accessStatic(){
        cout<<total_customer<<endl;
        cout<<total_balance<<endl;
    }
    
    void deposit(int amount){
        if(amount>0){
            balance=balance+amount;
            total_balance=total_balance+amount;
        }
    }
    
    void Withdraw(int amount){
        if(amount<=balance&&amount>0){
            balance=balance-amount;
            total_balance=total_balance-amount;
        }
    }
    
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<total_customer<<endl;
    }
    
    void display_total(){
        cout<<total_customer<<endl;
    }
};

int Customer::total_customer=0;
int Customer::total_balance=0;

int main(){
    Customer A1("Rohit",1,1000);
    Customer A2("Mohit",2,2000);
    Customer A3("Devanshu",3,3000);
    Customer::accessStatic();
    A1.deposit(800);
    A2.Withdraw(500);
    Customer::accessStatic();
}