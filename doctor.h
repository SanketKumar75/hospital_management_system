//doctor.h
#include<iostream>
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
    cout<<"<1>List Of Doctors"<<endl<<"<2>Check Availability"<<endl<<"<3>Add A New Doctor"<<endl<<"<9>Go Back TO Main Menu"<<endl<<"<0>To Exit"<<endl;
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
    return 1;
}
};

int doctor::list_doc(){
    cout<<"printing list of doctor\n";
}

int doctor::avail(){
    cout<<"checking availability";
}

int doctor::add_doc(){
    cout<<"adding doctor";
}
