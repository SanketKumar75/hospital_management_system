//doctor.h
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class doctor{
    public:
        int id=123;
        int c;
        int i;
        char name;
        char cat;
        int list_doc();
        int avail();
        int add_doc();

    int init(){
    cout<<"This too!"<<endl;
    cout<<"Enter your choice"<<endl; 
    cout<<"<1>List Of Doctors"<<endl
        <<"<2>Check Availability"<<endl
        <<"<3>Add A New Doctor"<<endl
        <<"<9>Go Back TO Main Menu"
        <<endl<<"<0>To Exit"<<endl;
    cin>>c;
    switch(c){
        case 0:
            {
                exit(1);
                break;
            }
        case 1:
            {
                cout<<"list of doc\n";
                i=list_doc();
                break;
            }
        case 2:
            {
                cout<<"Check availability\n";
                i=avail();
                break;
            }
        case 3:
            {
                cout<<"add new\n";
                i=add_doc();
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

int doctor::list_doc(){
    cout<<"printing list of doctor\n";
    

    return 0;
}

int doctor::avail(){
    cout<<"checking availability";
    return 0;
}

int doctor::add_doc(){
    cout<<"adding doctor\n";
    fstream fin;

    fin.open("test.cvs", ios::out | ios::app);

    string dname,catagory;
    int id,r;
    cout<<"Enter doctor's first name: "<<endl;
    cin>>dname;
    cout<<"Enter doctors ID no. : "<<endl;
    cin>>id;
    cout<<"The doctor has specialisation in: "<<endl;
    cin>>catagory;

    fin<<id<<", "<<dname<<", "<<catagory<<"\n";
    cout<<"Updated successfully!!\n";
    
    cout<<"Do you want to add another doctor?< 1=yes & 0=no>\n";
    cin>>r;
    if(r==0)
        return r+1;
    else if(r==1)
        add_doc();
    




    return 0;
}
