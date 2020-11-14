//doctor.h
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class doctor{
    private:
        int id=123;
        int c;
        int i;
        int age;
        int exp;
        string fname;
        string lname;
        string qual;
        string city;
		string spe;

	public:
			//Constructor for Default values
			doctor(){
					id=0;
					age=0;
					exp=0;
					fname="NoInput";
					lname="NoInput";
					qual="MBBS";
					city="Delhi";
					spe="GENRAL_MEDICINE";

					}
        char cat;
        int doc_info();
        int avail();
        int add_doc();
		int list_doc();
		int removedoc();
        string getSpec();


    int init(){
		system("cls");
    cout<<"Enter your choice"<<endl; 
    cout<<"<1>Information Of a Doctor"<<endl
        <<"<2>Check Availability"<<endl
        <<"<3>Add A New Doctor"<<endl
        <<"<4>List Of a All Doctor"<<endl
		<<"<5>Remove A Doctor"<<endl
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
				i=list_doc();
					return i;
            }
		case 5:
			{
				cout<<"Remove a doctor";
				i=removedoc();
				return i;
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
	system("cls");
    cout<<"printing list of doctor\n";
    {
    int x;
    cout<<"\n\nEnter the ID of the Doctor whose profile you want to display:"<<endl;
	cin>>x;
	ifstream file;file.open("doctor.txt",ios::out|ios::in);
	file.seekg(0);
		int count=0;
	//int ID,age,exp,count=0;
	//string fname,lname,ci,qua,spe;
	
//	 if (file.is_open())
// 		 cout << "File successfully open";
//	else
//    cout << "Error opening file";
  
	while(file >> id >> fname >> lname >>age >>qual >> spe >>exp >> city)   //!fileObj.eof()
	{
	
		if(id==x)
		{
		cout<<"\n\n1.ID:"<<id<<endl<<"2.First Name:"
		<<fname<<endl<<"3.Last Name:"<<lname<<endl
		<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qual<<endl
		<<"6.Spetyalization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<city<<endl<<endl;
		count++;
		}
	}
	file.close();
	if (count==0)
			cout<<"\nNo matching records found!"<<endl;
			
	cout<<"\n\nEnter \n<1>for previous menu \n<0>to Exit"<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  i=init();
	  return i;
	}
	  
	else
	  exit(0);

}

    return 0;
}

int doctor::avail(){
    cout<<"checking availability";
	string dept;
	cout<<"\nEnter the kind of specialization you are looking for:"<<endl<<endl;
	dept=getSpec();
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout<<"The doctors available with  "<<dept<<" specialization are:"<<endl<<endl;
	int age,exp,count=0;
	string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(spe==dept){
		cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl
			<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl
			<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl
			<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
		count++;
		}
	}
	
	fileObj.close();
	if(count==0){
		cout<<"\nNo doctors with this specialization found!"<<endl;

	}
	else
		cout<<"No of doctors with "<<dept<<" specialization:"<<count<<endl;
		
	cout<<"\n\n\n\nEnter <1> For previous Menu\nEnter <2> to Exit."<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  i=init();	 
	  return i;
	}
	  
	else
	  exit(0); 
}

int doctor::add_doc(){
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
   		cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<endl;
   		int q;
   		cin>>q;
   		if(q==1)
   			qual="MBBS";
		else qual="MD";
		cout<<"Choose Specialization among the following:"<<endl;
		string spec=getSpec();
		cout<<"Experience (in Years):"<<endl;
		cin>>exp;
		cout<<"City:"<<endl;
		cin>>city;
		system("cls");
		
		
		fstream fileObj;   
		fileObj.open("doctor.txt",ios::in | ios::app );

        fileObj.seekp (0, ios::end);
		fileObj<<id<<endl<<fname<<endl<<lname<<endl<<age<<endl<<qual<<endl<<spec<<endl<<exp<<endl<<city<<endl<<endl;
		fileObj.close();
	
	//after completion
	cout<<"\n\t\tNew Doctor profile created successfully!"<<endl<<endl;
	cout<<"\n\n\n\nEnter \n<1>for previous menu \n<0>to Exit"<<endl;
	int c;
	cin>>c;
	if(c==1){
	  system("cls");
	  i=init();
	  return i;
	}
	  
	else
	  exit(0);
	}


int doctor::list_doc(){
	system("cls");
	cout<<"list of doctors"<<endl;
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	//cout<<right<<setw(70)<<setfill(' ')<<"DOCTOR DATABASE"<<endl<<endl;
	cout<<"\t\t\tDOCTORS LIST"<<endl<<endl;
	//int age,exp;
	int count=0;
	//string ID,fname,lname,ci,qua,spe;
	cout<<"Serial.no  "<<"ID\t"<<"Name\t"<<"\tAge(years)\t"<<"Qualification\t"<<"Specialisation\t"<<"Experience(years)\t"<<"City"<<endl<<endl;
	while(fileObj>>id>>fname>>lname>>age>>qual>>spe>>exp>>city)
	{	count++;
		//cout<<right<<setw(50)<<setfill(' ')<<"Doctor Profile:"<<count<<endl;
		//cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
		cout<<count<<"\t"<<id<<"\t"<<fname<<" "<<lname<<"\t"<<age<<"\t"<<"\t"<<qual<<"\t"<<"\t"<<spe<<"\t"<<"\t"<<exp<<"\t"<<"\t"<<city;
		cout<<endl;
	}
	
	if(count==0)
	{cout<<"\nNo matching records found!"<<endl;
 	 exit(0);
	}
	
	cout<<"\n\nEnter \n<1>for previous menu \n<0>to Exit"<<endl;
	int c;
	cin>>c;
	if(c==1)
	{
	  system("cls");
	  i=init();
	  return i;
	} 
	else
	  exit(0);
}

int doctor::removedoc(){
			system("cls");
		cout<<"removeing a doctor";
		string x;
			cout<<"\nEnter the ID of the Doctor whose profile you want to Delete:"<<endl;
		cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
		fstream fileObj("doctor.txt");
		fileObj.seekg(0);
		
		int age,exp,count=0;
		string ID,fname,lname,ci,qua,spe;
		while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
		{
			if(ID==x){
			cout<<"\n\n1.ID:"<<ID<<endl<<"2.First Name:"<<fname<<endl
				<<"3.Last Name:"<<lname<<endl<<"4.Age:"<<age<<endl
				<<"5.Qualification:"<<qua<<endl<<"6.Specialization:"<<spe<<endl
				<<"7.Experience:"<<exp<<endl<<"8.City:"<<ci<<endl<<endl;
			count++;
			break;
			}
		}
		
		fileObj.close();
		if(count==0){
			cout<<"\nNo matching records found!"<<endl;
			exit(0);
		}
		cout<<"Are you sure you want to delete this profile?\n1.YES\n2.NO"<<endl;
		int n;cin>>n;
		if(n==1){
		fstream file("doctor.txt");
		file.seekg (0, ios::beg);
		file.seekg(0);
		string line;
		ofstream tempObj;
		tempObj.open("copy.txt");
		tempObj.seekp(0);
	int skip = 0;
	int age1,exp1;
		string fname1,lname1,ci1,qua1,spe1;
		file.seekg(0);file.seekg(0,ios::cur); //setting the pointer to beginning of file
			
	//	 if (tempObj.is_open())
	// 		 cout << "File successfully open";
	//	else
	//    	cout << "Error opening file";
		while(file>>line>>fname1>>lname1>>age1>>qua1>>spe1>>exp1>>ci1)
		{
			if(line!=x){
				tempObj<<line<<endl<<fname1<<endl<<lname1<<endl<<age1<<endl<<qua1<<endl<<spe1<<endl<<exp1<<endl<<ci1<<endl;
			}			
		}

	file.close();
	tempObj.close();
	remove("doctor.txt");
	int result;
	char oldname[] ="copy.txt";
	char newname[] ="doctor.txt";
	result= rename( oldname , newname );
	system("cls");
	cout<<"\n\t\tFile successfully deleted"<<endl;
	
	}
		cout<<"\n\nEnter 1 to return to previous menu\nEnter 2 to Exit."<<endl;
		int c;
		cin>>c;
		if(c==1){
		system("cls");
		i=init();

			return i;
		}
		
		else
		exit(0);
}
	







string doctor::getSpec(){
 	string sp;
	 system("cls");
	cout<<"1.GENERAL_MEDI"<<endl;
	cout<<"2.NEUROLOGY"<<endl;
	cout<<"3.ONCOLOGY"<<endl;
	cout<<"4.HAEMATOLOGY"<<endl;
	cout<<"5.GASTROENTEROLOGY"<<endl;
	cout<<"6.GYNAECOLOGY "<<endl;
	int s;
	cin>>s;
	switch(s){
		
		case 1:{
			sp= "GENERAL_MEDI";
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
