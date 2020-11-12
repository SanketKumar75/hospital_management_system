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
        int age;
        int experience;
        string fname;
        string lname;
        string qual;
        string city;

        char cat;
        int doc_info();
        int avail();
        int add_doc();
        string getSpec();


    int init(){
    cout<<"This too!"<<endl;
    cout<<"Enter your choice"<<endl; 
    cout<<"<1>Information Of a Doctor"<<endl
        <<"<2>Check Availability"<<endl
        <<"<3>Add A New Doctor"<<endl
        <<"<4>List Of a All Doctor"<<endl
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
                cout<<"Info of doctor\n";
                i=doc_info();
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
        case 4:
            {
                cout<<"List of Doctor\n";
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

int doctor::doc_info(){
    cout<<"printing list of doctor\n";
    {
    int x;
    cout<<"\n\nEnter the ID of the Doctor whose profile you want to display:"<<endl;
    cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
	ifstream file;file.open("doctor.txt",ios::out|ios::in);
	file.seekg(0);
		
	int ID,age,exp,count=0;
	string fname,lname,ci,qua,spe;
	
//	 if (file.is_open())
// 		 cout << "File successfully open";
//	else
//    cout << "Error opening file";
  
	while(file >> ID >> fname >> lname >>age >>qua >> spe >>exp >> ci)   //!fileObj.eof()
	{
	
		if(ID==x)
		{
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
		count++;
		}
	}
	file.close();
	if (count==0)
			cout<<"\nNo matching records found!"<<endl;
			
	cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  init();
	}
	  
	else
	  exit(0);

}

    return 0;
}

int doctor::avail(){
    cout<<"checking availability";
    return 0;
}

int doctor::add_doc(){
    /*cout<<"adding doctor\n";
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
    




    return 0;*/

	    cout<<"Fill up the following details"<<endl;
	    cout<<"ID:"<<endl;
	    cin>>id;
   		cout<<"First Name:"<<endl;
   		cin>>fname;
   		cout<<"Last Name:"<<endl;
   		cin>>lname;
   		cout<<"Age:"<<endl;
   		cin>>age;
   		cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
   		int q;
   		cin>>q;
   		if(q==1)
   			qual="MBBS";
		else qual="MD";
		cout<<"Choose Specialization among the following:"<<endl;
		string spec=getSpec();
		cout<<"Experience (in Years):"<<endl;
		cin>>experience;
		cout<<"City:"<<endl;
		cin>>city;
		system("cls");
		
		
		fstream fileObj;   
		fileObj.open("doctor.txt",ios::in | ios::app );

        fileObj.seekp (0, ios::end);
		fileObj<<id<<endl<<fname<<endl<<lname<<endl<<age<<endl<<qual<<endl<<spec<<endl<<experience<<endl<<city<<endl;
		fileObj.close();
	
	//after completion
	cout<<"\n\t\tNew Doctor profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  init();
	}
	  
	else
	  exit(0);
}





 string doctor::getSpec(){
 	string sp;
	cout<<"1.GENERAL_MEDICINE"<<endl;
	cout<<"2.NEUROLOGY"<<endl;
	cout<<"3.ONCOLOGY"<<endl;
	cout<<"4.HAEMATOLOGY"<<endl;
	cout<<"5.GASTROENTEROLOGY"<<endl;
	cout<<"6.GYNAECOLOGY "<<endl;
	int s;
	cin>>s;
	switch(s){
		
		case 1:{
			sp= "GENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="NEUROLOGY";
			break;
		}
		case 3:{
		    sp="ONCOLOGY";
			break;
		}
		case 4:{
			sp= "HAEMATOLOGY";
			break;
		}
		case 5:{
			sp= "GASTROENTEROLOGY";
			break;
		}
		case 6:{
			sp= "GYNAECOLOGY ";
			break;
		}
		default:{
			cout<<"\nCome on!Enter a valid option."<<endl;
			
		}
	
	}
		return sp;
	
}

