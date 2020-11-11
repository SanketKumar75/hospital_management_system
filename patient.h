//patient.h
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class patient{
    public:
        int id=12;
        char name;
        char cat;
        int in_time;
        int c;
        int i;
        
        int new_p();
        int list_p();
        int checkout();
        int bill();

        int init(){
    //cout<<"This too!"<<endl;
    cout<<"Enter your choice"<<endl; 
    cout<<"<1>New Patient Entry"<<endl
        <<"<2>List Of Patients"<<endl
        <<"<3>Patient Checking Out"<<endl
        <<"<4>Add to bill(Medical store bill)"<<endl
        <<"<9>Go Back TO Main Menu"<<endl
        <<"<0>To Exit"<<endl;
    cin>>c;
    switch(c){
        case 0:
            {
                exit(1);
                break;
            }
        case 1:
            {
                cout<<"New Patient Entry\n";
                i=new_p();
                break;
            }
        case 2:
            {
                cout<<"List Of Patients\n";
                i=list_p();
                break;
            }
        case 3:
            {
                cout<<"Patient Checking Out\n";
                i=checkout();
                break;
            }
        case 4:
            {
                cout<<"Add to bill(Medical store bill)\n";
                i=bill();
                break;
            }
        case 9:
            {
                return 1;
            }
        default : 
            {
                cout<<"invalid\n";
            }
        
    }
    return i;
}
};

int patient::new_p(){
    cout<<"new entry here"<<endl;
    fstream fin;
    fin.open("patient.csv",ios::out | ios::app);
    

    return 0;
}

int patient::list_p(){
    cout<<"List of present patient"<<endl;

    return 0;
}

int patient::checkout(){
    cout<<"patient checkout"<<endl;

    return 0;
}

int patient::bill(){
    cout<<"add to bill"<<endl;

    return 0;
}
