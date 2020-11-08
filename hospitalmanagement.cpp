//hospitalmanagement.cpp
#include<iostream>
#include"doctor.h" 
#include"patient.h"//including header files which has class doctor and patient respectively
using namespace std;

int main(){
    doctor d;
    patient p;
    //cin>>d.id;ṇ
    //cout<<d.id;
    int i=1,j,choice;

    cout<<"Welcome to the Hospital Management System"<<endl;
    while(i=1){
    cout<<"Enter your choice: "<<endl;
    cout<<"<1> Patiet"<<endl<<"<2> Doctor"<<endl<<"<0> To exit"<<endl;
    cin>>choice;
    if(choice==1){
        cout<<p.id<<endl;
        i=p.init();
        }
    else if(choice==2){
        cout<<d.id<<endl;
        i=d.init();
        }
    else if(choice==0){
        exit(1);
    }
    else cout<<"Invalid input\n";
    }
    return 0;
}
