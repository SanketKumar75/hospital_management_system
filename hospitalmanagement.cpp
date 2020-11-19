//hospitalmanagement.cpp
//driver
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include"doctor.h" 
#include"patient.h"//including header files which has class doctor and patient respectively
using namespace std;


int main(){
    doctor d;
    patient p;
    int i=1,j,choice; 
    system("cls");
    cout<<setw(100);
    cout<<"\t Welcome to the ABV-IIITM HOSPITAL"<<endl;
 
    while(i==1){
    
    cout<<"Are YOu A ?: "<<endl;
    cout<<"<1> Patiet"<<endl
        <<"<2> Doctor"<<endl
        <<"<0> To exit"<<endl;
    cin>>choice;
     

    if(choice==1){
        i=p.init();
        }
    else if(choice==2){
        i=d.init();
        }
    else if(choice==0){
        exit(1);
    }
    else cout<<"Invalid input\n";
    }

    return 0;
}
