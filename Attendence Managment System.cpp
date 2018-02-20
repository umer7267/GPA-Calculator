#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<direct.h>
void line();
using namespace std;

int attendence()
{
	string option,clas,student,date,temp;
	int i,j=1,absent = 0,present = 0;
	char attendence;
	
	cout<<"\n\n";
	ifstream file;
	file.open("c:/Attendence/Classes.txt");
	file >> option;
	if(option.empty())
	{
		cout<<"\n\n\n\n\t\t\tThere is no Class \n\n\t\tPlease go and Choose Enter New Class";
		Sleep(2000);
		system("cls");
		return 0;
	}
	else
	{
		cout<<"  S.No\t\t\tClass\n";
		cout<<"\n------------------------------\n";
		ifstream file;
		file.open("c:/Attendence/Classes.txt");
		while(file >> option)
		{
			cout<<"\n  "<<j<<".\t\t\t"<<option;
			Sleep(0700);
			j++;
		}
		file.close();
		
		cout<<"\n\n------------------------------\n";
		cout<<"\n  Choose Class:\t\t";
		cin>>clas;
		
		cout<<"\n\nEnter Today's Date (e.g. 29-May-17) : ";
		cin>>date;
		system("cls");
		
		temp = clas;
		
		clas = "c:/Attendence/" + clas + "/" + clas + ".txt";
		date = "c:/Attendence/" + temp + "/" + date + ".txt";
		
		cout<<"\n  S.No\t\t\tStudent Name\t\t\tAbsent/Present\n\n";
		line();
		cout<<"\n";
		
		ofstream today;
		today.open( date.c_str() );
		ifstream studentnames;
		studentnames.open( clas.c_str() );
		while(studentnames >> i >> student)
		{
			cout<<"\n  "<<i<<".\t\t\t"<<student<<"\t\t\t\t";
			cin>>attendence;
			if(attendence == 'A' || attendence == 'a')
			{
				absent++;
			}
			else if(attendence == 'P' || attendence == 'p')
			{
				present++;
			}
			today << i <<"\t"<< student <<"\t"<< attendence <<"\n";
		}
		today.close();
		cout<<"\n";
		line();
		Sleep(1000);
		cout<<"\n\n  Total Student(s) \t\t"<<"Present \t\t"<<"Absent"<<endl;
		cout<<"\n       "<<i<<"\t\t\t  "<<present<<"\t\t\t  "<<absent<<"\n\n\n";
	}
	cout<<"<- Goto Menu (Press Any Key) ";
	getch();
	return 0;
}

int previous()
{
	string option,date,clas,temp,student;
	int i,j=1,absent = 0, present = 0;
	char attendence;
	
	ifstream file;
	file.open("c:/Attendence/Classes.txt");
	file >> option;
	if(option.empty())
	{
		cout<<"\n\n\n\n\t\t\tThere is no Class \n\n\t\tPlease go and Choose Enter New Class";
		Sleep(2000);
		system("cls");
		return 0;
	}
	else
	{
		ifstream file;
		file.open("c:/Attendence/Classes.txt");
		cout<<"\n\n";
		cout<<"  S.No\t\t\tClass\n";
		cout<<"\n------------------------------\n";
		while(file >> option)
		{
			cout<<"\n  "<<j<<".\t\t\t"<<option;
			Sleep(0700);
			j++;
		}
		
		cout<<"\n\n------------------------------\n";
		cout<<"\n  Choose Class:\t\t";
		cin>>clas;
		
		cout<<"\n\nEnter Date To Check Record (e.g. 29-May-17) : ";
		cin>>date;
		system("cls");
		
		date = "c:/Attendence/" + clas + "/" + date + ".txt";
		
		cout<<"\n  S.No\t\t\tStudent Name\t\t\tAbsent/Present\n\n";
		line();
		cout<<"\n";
		
		ifstream today;
		today.open( date.c_str() );
		while(today >> i >> student >> attendence)
		{
			cout<<"\n  "<<i<<".\t\t\t"<<student<<"\t\t\t\t"<<attendence<<"\n";
			if(attendence == 'A' || attendence == 'a')
			{
				absent++;
			}
			else if(attendence == 'P' || attendence == 'p')
			{
				present++;
			}
			Sleep(0700);
		}
		today.close();
		cout<<"\n";
		line();
		Sleep(1000);
		cout<<"\n\n  Total Student(s) \t\t"<<"Present \t\t"<<"Absent"<<endl;
		cout<<"\n       "<<i<<"\t\t\t  "<<present<<"\t\t\t  "<<absent<<"\n\n\n";
		
		cout<<"<- Goto Menu (Press Any Key) ";
		getch();
	}
	return 0;
}

int new_class()
{
	int length;
	string classname,temp,student_name;
	char choice;
	
	
	mkdir("c:/Attendence");
	
	cout<<"\n\nEnter Class name: ";
	cin>>classname;
	
	temp = classname;
	
	classname = "c:/Attendence/" + classname;
	mkdir( classname.c_str() );
	
	classname = temp;
	
	ofstream classes;
	classes.open("c:/Attendence/Classes.txt", ofstream::out | ofstream::app);
	classes << classname << "\n";
	classes.close();
	
	classname = "c:Attendence/" + temp + "/" + classname + ".txt";
	
	ofstream file;
	file.open( classname.c_str() );
	cout<<"\nEnter Class Strength: ";
	cin>>length;
	for(int i=1; i<=length; i++)
	{
		cout<<"\nEnter "<<i<<" Student name: \t\t";
		cin>>student_name;
		line();
		file << i <<"\t" << student_name <<"\n";
	}
	file.close();
	system("cls");
	cout<<"\n\nClass is Added! \n\nNow you can Mark Attendence \n\nMark Attendence Now? \n\nPress Y for 'Yes' N for 'No' ";
	cin>>choice;
	if(choice == 'n' || choice == 'N')
	{
		return 0;
	}
	else if(choice == 'Y' || choice == 'y')
	{
		system("cls");
		attendence();
	}
	else
	{
		cout<<"Invalid Choice!";
	}
}

void line()
{
	cout<<"---------------------------------------------------------------------------";
}

int main()
{
	int choice,retrn;
	
	up:
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Attendence Management System";
	cout<<"\n\t\t\t---------------------------------------";
	cout<<"\n\n\n1. Mark Today's Attendence.";
	cout<<"\n2. Check Previous Attendence.";
	cout<<"\n3. Enter New Class.";
	cout<<"\n4. Exit.";
	
	cout<<"\n\nEnter Your Choice: ";
	cin>>choice;
	system("cls");
	
	if(choice == 1)
	{
		retrn = attendence();
		if(retrn == 0)
		{
			goto up;
		}
	}
	
	else if(choice == 2)
	{
		previous();
		goto up;
	}
	
	else if(choice == 3)
	{
		new_class();
		goto up;
	}
	
	else if(choice == 4)
	{
		return 0;
	}
	
	else
	{
		cout<<"\n\n\n\n\t\t\t\tWrong Choice!";
		cout<<"\n\n\t\t\t\tChoose Again!";
		Sleep(1000);
		system("cls");
		goto up;
	}
}
