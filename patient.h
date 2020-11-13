//patient.h
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class patient{
    public:
        int id=12;
        int c;
        int i;
        int age;

        string phno;
        string in_date;
        string fname;
        string lname;
        string occupation;
        string dis;
        string qual;
        string city;
        
        int new_p();
        int p_info();
        int list_p();
        int discharge();
        int bill();
        int getDoctor();
        string getDept();

        int init(){
    //cout<<"This too!"<<endl;
    cout<<"Enter your choice"<<endl; 
    cout<<"<1>New Patient Entry"<<endl
        <<"<2>Display A Patient's Information"<<endl
        <<"<3>List Of All Patients"<<endl
        <<"<4>Patient Discharge"<<endl
        <<"<5>Add to bill(Medical store bill)"<<endl
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
                cout<<"Patient Information\n";
                i=p_info();
                break;
            }
        case 3:
            {
                cout<<"List of all the patients in hospital\n";
                i=list_p();
                break;
            }
        case 4:
            {
                cout<<"Discharge patient\n";
                i=discharge();
                break;
            }
        case 5:
            {
                cout<<"Add to bill(Medical store bills)\n";
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
                init();
            }
        
    }
    return i;
}
};

int patient::new_p(){
    cout<<"new entry here"<<endl;
    system("cls");
     cout<<"Fill up the following details"<<endl;
    cout<<"ID:"<<endl;
    cin>>id;
    cout<<"First Name:"<<endl;
    cin>>fname;
    cout<<"Last Name:"<<endl;
    cin>>lname;
    cout<<"Age:"<<endl;
    cin>>age;
    cout<<"Phone No.:"<<endl;
    cin>>phno;
    cout<<"Occupation:"<<endl;
    cin>>occupation;
    cout<<"City:"<<endl;
    cin>>city;
    cout<<"Disease/Symptoms:"<<endl;
    cin>>dis;
    cout<<"Admission date  (DD/MM/YYYY):"<<endl;
    cin>>in_date;
    cout<<"Select the Area Of Treatment:"<<endl;
    string dept=getDept();


		fstream patObj;   
		patObj.open("patient.txt",ios::app );
      //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept

        patObj.seekp (0, ios::end);
		patObj<<id<<endl<<fname<<endl<<lname<<endl<<age<<endl<<phno<<endl<<occupation<<endl<<city<<endl<<dis<<endl<<in_date<<endl<<dept<<endl;
		patObj.close();
	
	cout<<"\n\t\tNew Patient profile created successfully!"<<endl<<endl<<endl;
	cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  init();	 //backtoPatientMenu
	}
	  
	else
	  exit(0); 
}


int patient::p_info(){
    cout<<"patient info\n";
    int x;
    system("cls");
	cout<<"\nEnter the ID of the Patient whose profile you want to Display:"<<endl;
	cin>>x;									 
	fstream patObj("patient.txt");
	patObj.seekg(0);
													//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept
	string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int age,id,count=0;
	string phno;
	while(patObj>>id>>fname>>lname>>age>>phno>>occupation>>p_city>>dis>>addDate>>dept)
	{
		if(id==x){
		cout<<"1.ID:"<<id<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age"<<age<<endl<<"5.Phone No.:"<<phno<<endl<<"6.Occupation:"<<occupation<<endl<<"7.City:"<<p_city<<endl<<"8.Disease/Symptoms:"<<dis<<endl<<"9.Admission date(DD/MM/YYYY):"<<addDate<<endl<<"10.Kind of Specialization required:"<<dept<<endl;
		count++;
		break;
		}
	}
	
	patObj.close();
	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}
	
cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  init();
	}
	  
	else
	  exit(0);

    return 0;
}

int patient::list_p(){
    system("cls");
    cout<<"List of present patient"<<endl;

    fstream Obj("patient.txt");
	Obj.seekg(0);
	cout<<right<<setw(70)<<setfill(' ')<<"PATIENT DATABASE"<<endl<<endl;
	string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
    cout<<"S.no  "<<"ID\t"<<"Name\t"<<"\tAge(yr)\t"<<"Phone Number\t"
            <<"Occupation\t"<<"City\t"<<"disease\t"<<"In_Date\t"<<"Department"<<endl;
	while(Obj>>id>>fname>>lname>>age>>phno>>
            occupation>>city>>dis>>in_date>>dept)
	{   count++;
//		cout<<right<<setw(50)<<setfill(' ')<<"Patient Profile:"<<count<<endl;
//		cout<<"1.ID:  "<<id<<endl
//      <<"2.First Name:  "<<fname<<endl
//        <<"3.Last Name:  "<<lname<<endl
//        <<"4.Age"<<p_age<<endl
//        <<"5.Phone No.:  "<<phnumber<<endl
//        <<"6.Occupation:  "<<occupation<<endl
//        <<"7.City:  "<<p_city<<endl
//    <<"8.Disease/Symptoms:  "<<dis<<endl
//      <<"9.Admission date(DD/MM/YYYY):  "<<in_date<<endl
//        <<"12.Kind of Specialization required:  "<<dept<<endl
//        <<endl;
            cout<<count<<"\t"<<id<<"\t"<<fname<<" "<<lname<<"\t"<<age
                <<"\t"<<phno<<"\t"<<occupation<<"\t"<<city<<"\t"<<dis
                <<"\t"<<in_date<<"\t"<<dept<<endl;
		}
		
	Obj.close();
	
	if(count==0){
		cout<<"\nNo matching records found!"<<endl;
		exit(0);
	}
	
cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  init();
	}
	  
	else
	  exit(0);

    return 0;
}

int patient::discharge(){
    cout<<"patient checkout"<<endl;

    return 0;
}

int patient::bill(){
    cout<<"add to bill"<<endl;

    return 0;
}








string patient::getDept(){
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



int patient::getDoctor(){
	patient p;
	string dept;
	cout<<"\nEnter the kind of specialization you are looking for:"<<endl<<endl;
	dept=getDept();
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout<<"The doctors available with  "<<dept<<" specialization are:"<<endl<<endl;
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(spe==dept){
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
		count++;
		}
	}
	
	fileObj.close();
	if(count==0){
		cout<<"\nNo doctors with this specialization found!"<<endl;
		exit(0);
	}
	else
		cout<<"No of doctors with "<<dept<<" specialization:"<<count<<endl;
		
	cout<<"\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  init();	 //backtoPatientMenu
	}
	  
	else
	  exit(0); 
}
