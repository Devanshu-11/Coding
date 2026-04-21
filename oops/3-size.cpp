#include<iostream>
using namespace std;

// if the class is empty,then size of empty class is 1 bytes and each system gives different different output according to systems
class A{
    public:
    char c;
    int b;
    char d;
    double e;
    // c p p p b b b b d p p p p p p p e e e e e e e e, here p represents the padding
};

int main(){
    A obj1;
    cout<<"The size of int obj is: "<<sizeof(obj1)<<endl; // it would gives output as 8
}