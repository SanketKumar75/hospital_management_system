//patient.h
#include<iostream>
using namespace std;

class patient{
    public:
        int id=12;
        char name;
        char cat;
        int in_time;
        int init();

};

int patient::init(){
   cout<<"Works well n fine!"<<endl;
}

