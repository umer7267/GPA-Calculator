#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>
void line(void);
float gpa(int);
using namespace std;
int main()
{
	float sum, sam_gpa, CGPA, sub_gpa, crdt_hrs, multiply = 1, total_gpa, multiplay_sum = 0,sum_crdit = 0;
	float subject[80], percent[80], credit_hrs[80], gpa_sub[80];
	int percentage, samester, sub;
	char conti, select, again;
	string grade[10], total_grade, key;
	
	
	up:
	system("cls");
	system("cls");
	cout<<"\n\n\n\n\n\t\n\n\n\n\t\t\t\tLoading";
	Sleep(0700);
	cout<<".";
	Sleep(0700);
	cout<<".";
	Sleep(0700);
	cout<<".";
	Sleep(0700);
	
	
	system("cls");
	cout<<"\n\t\t\3\3*****Welcome To GPA & CGPA Calculator*****\3\3\t\t\n\n";
	cout<<"\t\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\t\t\n";
	
	abc:
	cout<<"\n1: Select 1 for GPA Calculation\n";
	cout<<"2: Select 2 for CGPA Calculation\n\n";
	cin>>select;
	system("cls");
	
	
	switch(select)
	{
		case '1':
		{
			cout<<"\nEnter Number of subjects: ";
			cin>>sub;
			for(int i=1; i<=sub; i++)
			{
				subject[i] = i;
			}
			for(int k = 1; k<=sub; k++)
			{
				line();
				cout<<"\nEnter Credit Hours of "<<k<<" Subject: ";
				cin>>crdt_hrs;
				sum_crdit = sum_crdit + crdt_hrs;
				cout<<"\nEnter Percentage of "<<k<<" Subject: ";
				cin>>percentage;
				
				for(int g=k; g <= k; g++)
				{
					if(percentage >= 85 && percentage <=100)
					grade[g] = "A";
					else if(percentage >= 80 && percentage <= 84)
					grade[g] = "A-";
					else if(percentage >= 75 && percentage <=79)
					grade[g] = "B+";
					else if(percentage >= 70 && percentage <= 74)
					grade[g] = "B";
					else if(percentage >= 65 && percentage <= 69)
					grade[g] = "C+";
					else if(percentage >= 60 && percentage <= 64)
					grade[g] = "C";
					else if(percentage >= 55 && percentage <= 59)
					grade[g] = "D+";
					else if(percentage >= 50 && percentage <= 54)
					grade[g] = "D";
					else if(percentage <= 49)
					grade[g] = "F";
					else
					cout<<"Incorrect marks";
				}
				
				cout<<"\n";
				sub_gpa = gpa(percentage);
				multiply = crdt_hrs * sub_gpa;
				multiplay_sum = multiplay_sum + multiply;
				gpa_sub[k] = sub_gpa;
				percent[k] = percentage;
				credit_hrs[k] = crdt_hrs;
			}
			total_gpa = multiplay_sum / sum_crdit;
			
			if(total_gpa > 3.75 && total_gpa <= 4.00)
			total_grade = "A";
			else if(total_gpa > 3.50 && total_gpa <= 3.75)
			total_grade = "A-";
			else if(total_gpa > 3.00 && total_gpa <= 3.50)
			total_grade = "B+";
			else if(total_gpa > 2.50 && total_gpa <= 3.00)
			total_grade = "B";
			else if(total_gpa > 2.00 && total_gpa <= 2.50)
			total_grade = "C+";
			else if(total_gpa > 1.50 && total_gpa <= 2.00)
			total_grade = "C";
			else if(total_gpa > 1.00 && total_gpa <= 1.50)
			total_grade = "D+";
			else if(total_gpa > 0.00 && total_gpa <= 1.00)
			total_grade = "D";
			else
			total_grade = "F";
			break;
		}
		
		
		case '2':
		{
			cout<<"\nEnter number of Samesters: ";
			cin>>samester;
			line();
			for(int i=1; i<=samester; i++)
			{
				cout<<"\nEnter GPA of "<<i<<" Samester: ";
				cin>>sam_gpa;
				sum = sum + sam_gpa;
				CGPA = sum / samester;
			}
			line();
			cout<<"\nYour total CGPA is \t"<<setprecision(2)<<fixed<<CGPA<<endl;
			goto label;	
			break;
		}
		
		default:
		{
			cout<<"\n\nYou Entered an Incorrect Command\n\n";
			goto label;
		}
	}
	// For Ouput
	system("cls");
	for(int j=1; j<=sub; j++)
	{
		if(j==1)
		{
			cout<<"\nSubjects  \tMarks\t     Credit Hours\tGPA\t\tGrade\n\n";
		}
		cout<<subject[j]<<"\t\t"<<percent[j]<<"\t     "<<credit_hrs[j]<<"    \t\t"<<gpa_sub[j]<<"\t\t"<<grade[j]<<"\n\n";
	}
	line();
	cout<<"\nYour Total GPA is \t\t\t\t\t\t"<<setprecision(2)<<fixed<<total_gpa;
	cout<<"\n\nYour Samester Grade is \t\t\t\t\t\t"<<setprecision(2)<<fixed<<total_grade<<endl;
	
	// For Continue
	label:
	line();
	cout<<"\n\t\t\t\tThank You!!\n\nCreated By: Muhammad Umer & Basit Shehzad";
	cout<<"\n\nDo You want to cotinue?\nPress Y for Yes and N for No: ";
	cin>>conti;
	
	
	system("cls");
	switch(conti)
	{
		case 'Y':
		case 'y':
		{
			goto abc;
			break;
		}
		case 'N': 
		case 'n':
		{
			return 0;
		}
	}
	
}


float gpa(int percentage)
{
	float result;
	if(percentage >= 85 && percentage <=100)
	result = 4.00;
	else if(percentage >= 80 && percentage <= 84)
	result = 3.75;
	else if(percentage >= 75 && percentage <=79)
	result = 3.50;
	else if(percentage >= 70 && percentage <= 74)
	result = 3.00;
	else if(percentage >= 65 && percentage <= 69)
	result = 2.50;
	else if(percentage >= 60 && percentage <= 64)
	result = 2.00;
	else if(percentage >= 55 && percentage <= 59)
	result = 1.50;
	else if(percentage >= 50 && percentage <= 54)
	result = 1.00;
	else if(percentage <= 49)
	result = 0.00;
	else
	cout<<"Incorrect marks";
	return result;
}

void line()
{
	cout<<"\n--------------------------------------------------------------------------------";
}
