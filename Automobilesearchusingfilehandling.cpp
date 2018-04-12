#include<iostream>
#include<fstream>
#include<iomanip.>
#include<stdio.h>
#include<conio.h>

using namespace std;
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class workshop
{
	int carno;
	char name[50];
	int pnum;	//function to calculate grade
public:
	void getdata();		//function to accept data from user
	void showdata();	//function to show data on screen
	void show_tabular();
	int setcarno();
}; //class ends here


void workshop::getdata()
{
	cout<<"\nEnter The car number of workshop ";
	cin>>carno;
	cout<<"\nEnter the car name ";
	cin>>name;
	cout<<"\nEnter the phone number ";
	cin>>pnum;

}

void workshop::showdata()
{
 cout<<"\nThe car number is "<<carno;
cout<<"\nThe car name is "<<name;
cout<<"\nCustomer's number is "<<pnum;
}

void workshop::show_tabular()
{
	cout<<carno<<setw(6)<<" "<<name<<setw(10)<<pnum<<endl;
}

int  workshop::setcarno()
{
	return carno;
}
void write_workshop();	//write the record in binary file
void display_all();	//read all records from binary file
void display_sp(int);	//accept carno and read record from binary file
void intro();		//display welcome screen
void entry_menu();	//display entry menu on screen
int main()
{
	char ch;
	int rno;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	system("cls");
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. ENTRY/EDIT MENU";
		cout<<"\n\n\t02. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case '1': entry_menu();
				break;
			case '2':
				break;
			default :cout<<"\a";
		}
    	}while(ch!='3');
	return 0;
}
void write_workshop()
{
	workshop st;
	ofstream outFile;
	outFile.open("workshop.txt",ios::binary|ios::app);
	st.getdata();
	outFile.write((char *) &st, sizeof(workshop));
	outFile.close();
    	cout<<"\n\nworkshop record Has Been Created ";
	cin.ignore();
	getch();
}
void display_all()
{
	workshop st;
	ifstream inFile;
	inFile.open("workshop.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *) &st, sizeof(workshop)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	getch();
}
void display_sp(int n)
{
	workshop st;
	ifstream inFile;
	inFile.open("workshop.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}

	int flag=0;
	while(inFile.read((char *) &st, sizeof(workshop)))
	{
		if(st.setcarno()==n)
		{
			 st.showdata();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	getch();
}

void intro()
{
	cout<<"\n\n\n\t\tSIVA's WORKSHOP\t\t";
	getch();
}
void entry_menu()
{
	char ch;
	int num;
	system("cls");
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE workshop RECORD";
	cout<<"\n\n\t2.DISPLAY ALL workshopS RECORDS";
	cout<<"\n\n\t3.SEARCH workshop RECORD ";
	cout<<"\n\n\t4.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_workshop(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The Car number "; cin>>num;
			display_sp(num); break;
	case '4':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
