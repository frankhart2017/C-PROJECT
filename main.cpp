#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<iomanip>
#include<string>
#include<bits/stdc++.h>
using namespace std;
string Email="";
template<class T>
void write(T var)
{
	ofstream fout1("admin.txt",ios::out|ios::app);
	fout1<<var;
}
void thank_you()
{
	system("cls");
	cout<<"\t\t\t\tDREAM TRAVELS\n";
    cout<<"\t\t\t\t*************\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t<-THANK YOU->\n\n\n\n\n\n\n\n\n\n";
    exit(0);
}
int validate_email(string email)
{
	int checks=0;
	if(email[0]!='@' && email[0]!='.')
		checks++;
	int pa=email.find('@');
	int pd=email.find('.');
	if(email[pd-1]=='@')
		checks--;
	int ac=0,dc=0;
	for(int i=0;i<email.length();i++)
	{
		if(email[i]=='@')
			ac++;
		if(email[i]=='.')
			dc++;
	}
	if(ac==1 && dc==1)
		checks++;
	for(int i=0;i<pa;i++)
	{
		if(isalnum(email[i]) || email[i]=='_')
			continue;
		else
		{
			checks--;
			break;
		}
	}
	for(int i=pa+1;i<pd;i++)
	{
		if(isalpha(email[i]))
			continue;
		else
		{
			checks--;
			break;
		}
	}
	if(email[pd+1]=='c' && email[pd+2]=='o')
	{
		if(email[pd+3]=='m')
			checks++;
		else if(email[pd+4]=='.' && email[pd+5]=='i' && email[pd+6]=='n')
			checks++;
	}
	return checks;
}
int validate_password(string pass)
{
	if(pass.length()<10 || pass.length()>20)
        return 1;
    else
    	return 0;
}
int validate_mobile(char mobile[])
{
	int errors=0;
    for(int i=0;i<strlen(mobile);i++)
    {
        if(!isdigit(mobile[i]))
        {
        	errors++;
        	break;
		}

    }
    if(strlen(mobile)!=10)
        errors++;
    if(mobile[0]!='9' && mobile[0]!='8' && mobile[0]!='7' && mobile[0]!='6')
        errors++;
    return errors;
}
int validate_prod_key(string pkey)
{
	int errors=0;
	if(pkey.length()!=16)
		errors++;
	return errors;
}
int main_page();
void user_page(string);
void spaces(char a[])
{
	for(int i=0;i<strlen(a);i++)
	{
		if(isupper(a[i]))
		{
			a[i]=(char)32+a[i];
		}
	}
	cout<<a;
}
char* deblank(char* input)
{
    int i,j;
    char *output=input;
    for (i = 0, j = 0; i<strlen(input); i++,j++)
    {
        if (input[i]!=' ')
            output[j]=input[i];
        else
            j--;
    }
    output[j]=0;
    return output;
}
int get_user()
{
	int id;
	cout<<"\n\nEnter the id number to select (Eg. 1, 2): ";
	cin>>id;
	return id;
}
void payment_page()
{
	system("cls");
	int errors=0;
	struct card
    {
        string p1,p2,p3,p4;
    };
	struct expiry
	{
	    int month,year;
	};
    string str,c;
    card o;
    expiry p;
    cout<<"Name: ";
    cin>>str;
    cout<<endl<<"Card Number: ";
    cin>>o.p1>>o.p2>>o.p3>>o.p4;
    if(o.p1.length()!= 4 || o.p2.length()!= 4 || o.p3.length()!= 4 || o.p4.length()!= 4)
    {
        cout<<"Invalid card number\n";
        errors++;
    }
    cout<<"Enter CVV : \n";
    cin>>c;
    if (c.length()!=3)
    {
        cout<<"Invalid CVV\n";
        errors++;
    }
    cout<<"Enter the expiry date(mm yy):  "<<endl;
    cin>>p.month>>p.year;
    if(p.month>12)
    {
        cout<<"Invalid expiry\n";
        errors++;
    }
    if(errors>0)
    {
    	system("pause");
    	payment_page();
	}
}
void flight(string uname)
{
	int b;
    system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
    cout<<"Flights\n\n";
    cout<<"1) International Flights.\n";
    cout<<"2) Domestic Flights.\n";
    cout<<"3) Go back to main page.\n";
    cout<<"4) Go back to account home.\n\n";
    cout<<"Enter your choice(1-4): ";
    cin>>b;
    ifstream fin("flight.txt",ios::in);
    if(b==3)
    	main_page();
    if(b==4)
    	user_page(uname);
	system("cls");
    char s[30],d[30];
    int t;
    cout<<"Source: ";
    fflush(stdin);
    cin.getline(s,sizeof(s));
    strcpy(s,deblank(s));
	s[0]=toupper(s[0]);
    cout<<"\nDestination: ";
    cin.getline(d,sizeof(d));
    strcpy(d,deblank(d));
    d[0]=toupper(d[0]);
    cout<<"\nNo. of tickets: ";
    cin>>t;
    int id;
    char line[30];
    char airline[30],source[30],destination[30];
    int search=0,nos,i=0;
    float price;
    switch (b)
    {
    case 1:
        {
            system("cls");
            while(!fin.eof())
			{
				i++;
				fin>>id;
				fin>>line;
				if(strcmp(line,"int")==0)
				{
					fin>>airline;
					fin>>source;
					fin>>destination;
					fin>>nos;
					fin>>price;
					if(strcmp(source,s)==0 && strcmp(destination,d)==0 && nos>=t)
					{
						cout<<"\n\nId:"<<i<<"\nAirlines: "<<airline<<"\nSource: "<<source<<"\nDestination: "<<destination<<"\nNumber of seats available: ";
						cout<<nos<<"\nPrice: "<<price*t;
						search=1;
					}
				}
				else
				{
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no flights found matching your preference!";
			}

			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("flight.txt",ios::in);
				fstream foun("flight1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fout<<"1"<<endl;
						fout<<t<<endl;
						fout<<Email<<endl;
						fin>>line;
						fin>>airline;
						fout<<airline<<endl;
						fin>>source;
						fout<<source<<endl;
						fin>>destination;
						fout<<destination<<endl;
						fin>>nos;
						fin>>price;
						fout<<price*t<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<t<<endl;
						html<<"<br>Airline: "<<airline<<endl;
						html<<"<br>Source: "<<source<<endl;
						html<<"<br>Destination: "<<destination<<endl;
						html<<"<br>Price: "<<price*t<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>line;
						foun<<line<<endl;
						fin>>airline;
						foun<<airline<<endl;
						fin>>source;
						foun<<source<<endl;
						fin>>destination;
						foun<<destination<<endl;
						fin>>nos;
						foun<<nos-t<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				remove("flight.txt");
				rename("flight1.txt","flight.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				user_page(uname);
			}
			exit(0);
            break;
        }

    case 2:
        {
            system("cls");
            while(!fin.eof())
			{
				i++;
				fin>>id;
				fin>>line;
				if(strcmp(line,"dom")==0)
				{
					fin>>airline;
					fin>>source;
					fin>>destination;
					fin>>nos;
					fin>>price;
					if(strcmp(source,s)==0 && strcmp(destination,d)==0 && nos>=t)
					{
						cout<<"\n\nId:"<<i<<"\nAirlines: "<<airline<<"\nSource: "<<source<<"\nDestination: "<<destination<<"\nNumber of seats available: ";
						cout<<nos<<"\nPrice: "<<price*t;
						search=1;
					}
				}
				else
				{
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no flights found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("flight.txt",ios::in);
				fstream foun("flight1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fout<<"1"<<endl;
						fout<<t<<endl;
						fout<<Email<<endl;
						fin>>line;
						fin>>airline;
						fout<<airline<<endl;
						fin>>source;
						fout<<source<<endl;
						fin>>destination;
						fout<<destination<<endl;
						fin>>nos;
						fin>>price;
						fout<<price*t<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<t<<endl;
						html<<"<br>Airline: "<<airline<<endl;
						html<<"<br>Source: "<<source<<endl;
						html<<"<br>Destination: "<<destination<<endl;
						html<<"<br>Price: "<<price*t<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>line;
						foun<<line<<endl;
						fin>>airline;
						foun<<airline<<endl;
						fin>>source;
						foun<<source<<endl;
						fin>>destination;
						foun<<destination<<endl;
						fin>>nos;
						foun<<nos-t<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				remove("flight.txt");
				rename("flight1.txt","flight.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
	default:
		cout<<"\nIncorrect Choice!\n\n";
		system("pause");
		flight(uname);
    }
}
void hotel(string uname)
{
	int c;
    system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
    cout<<"Hotels\n\n";
    cout<<"1) Delux Room.\n";
    cout<<"2) Executive Room.\n";
    cout<<"3) Go back to main page.\n";
    cout<<"4) Go back to account home.\n\n";
    cout<<"Enter your choice(1-4): ";
    cin>>c;
    if(c==3)
    	main_page();
    if(c==4)
    	user_page(uname);
	int p;
    char d[100];
    system("cls");
    cout<<"Destination: ";
    fflush(stdin);
    cin.getline(d,sizeof(d));
    strcpy(d,deblank(d));
    d[0]=toupper(d[0]);
    int id;
    char type,name[30],location[30],line[30];
    int occupancy,rooms,search=0,i=0;
    float price;
    cout<<"No. of people: ";
    cin>>p;
    ifstream fin("hotel.txt",ios::in);
    switch (c)
    {
    case 1:
        {
        	system("cls");
        	while(!fin.eof())
        	{
        		i++;
        		fin>>id;
        		fin>>type;
        		if(type=='d')
        		{
        			fin>>occupancy;
	        		fin>>name;
	        		fin>>location;
	        		fin>>rooms;
	        		fin>>price;
					if(strcmp(location,d)==0 && rooms>=1 && occupancy==p)
					{
						cout<<"\n\nId: "<<i<<"\nHotel: "<<name<<"\nLocation: "<<location<<"\nOccupancy: "<<occupancy<<"\nNumber of rooms available: "<<rooms;
						cout<<"\nPrice: "<<price;
						search=1;
					}
				}
				else
        		{
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no hotels found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("hotel.txt",ios::in);
				fstream foun("hotel1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					fin>>type;
					fin>>occupancy;
					if(id==a)
					{
						fout<<"2"<<endl;
						fout<<"1"<<endl;
						fout<<Email<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>location;
						fout<<location<<endl;
						fin>>rooms;
						fin>>price;
						fout<<price<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: 1"<<endl;
						html<<"<br>Hotel: "<<name<<endl;
						html<<"<br>Location: "<<location<<endl;
						html<<"<br>Occupancy: "<<occupancy<<endl;
						html<<"<br>Price: "<<price<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>type;
						foun<<type<<endl;
						fin>>occupancy;
						foun<<occupancy<<endl;
						fin>>name;
						foun<<name<<endl;
						fin>>location;
						foun<<location<<endl;
						fin>>rooms;
						foun<<rooms-1<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				remove("hotel.txt");
				rename("hotel1.txt","hotel.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }

    case 2:
        {
            system("cls");
        	while(!fin.eof())
        	{
        		i++;
        		fin>>id;
        		fin>>type;
        		if(type=='e')
        		{
        			fin>>occupancy;
	        		fin>>name;
	        		fin>>location;
	        		fin>>rooms;
	        		fin>>price;
					if(strcmp(location,d)==0 && rooms>=1 && occupancy==p)
					{
						cout<<"\n\nId: "<<i<<"\nHotel: "<<name<<"\nLocation: "<<location<<"\nOccupancy: "<<occupancy<<"\nNumber of rooms available: "<<rooms;
						cout<<"\nPrice: "<<price;
						search=1;
					}
				}
				else
        		{
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no hotels found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("hotel.txt",ios::in);
				fstream foun("hotel1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					fin>>type;
					fin>>occupancy;
					if(id==a)
					{
						fout<<"2"<<endl;
						fout<<"1"<<endl;
						fout<<Email<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>location;
						fout<<location<<endl;
						fin>>rooms;
						fin>>price;
						fout<<price<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: 1"<<endl;
						html<<"<br>Hotel: "<<name<<endl;
						html<<"<br>Location: "<<location<<endl;
						html<<"<br>Occupancy: "<<occupancy<<endl;
						html<<"<br>Price: "<<price<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>type;
						foun<<type<<endl;
						fin>>occupancy;
						foun<<occupancy<<endl;
						fin>>name;
						foun<<name<<endl;
						fin>>location;
						foun<<location<<endl;
						fin>>rooms;
						foun<<rooms-1<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				remove("hotel.txt");
				rename("hotel1.txt","hotel.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
	default:
		cout<<"\nIncorrect Choice!\n\n";
		hotel(uname);
    }
}
void train(string uname)
{
	int e;
    system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
    cout<<"Trains\n\n";
    cout<<"1) Book.\n";
    cout<<"2) Go back to main page.\n";
    cout<<"3) Go back to account home.\n\n";
    cout<<"Enter your choice(1-2): ";
    cin>>e;
    if(e==2)
    	main_page();
    if(e==3)
    	user_page(uname);
	system("cls");
    char s[30],d[30];
    int t;
    cout<<"Source: ";
    fflush(stdin);
    cin.getline(s,sizeof(s));
    strcpy(s,deblank(s));
	s[0]=toupper(s[0]);
    cout<<"\nDestination: ";
    cin.getline(d,sizeof(d));
    strcpy(d,deblank(d));
    d[0]=toupper(d[0]);
    cout<<"\nNo. of tickets: ";
    cin>>t;
    ifstream fin("train.txt",ios::in);
    int id;
    float price;
    char type;
    char name[100],source[30],destination[30],line[30];
    int nos,search=0,i=0;
    switch (e)
    {
    case 1:
        {
        	system("cls");
            while(!fin.eof())
			{
				i++;
				fin>>id;
				fin>>type;
				if(type=='e')
				{
					fin>>name;
					fin>>source;
					fin>>destination;
					fin>>nos;
					fin>>price;
					if(strcmp(source,s)==0 && strcmp(destination,d)==0 && nos>=t)
					{
						cout<<"\n\nId: "<<i<<"\nTrain: "<<name<<"\nSource: "<<source<<"\nDestination: "<<destination<<"\nNumber of seats available: "<<nos;
						cout<<"\nPrice: "<<price*t;
						search=1;
					}
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no trains found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("train.txt",ios::in);
				fstream foun("train1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					fin>>type;
					if(id==a)
					{
						fout<<"3"<<endl;
						fout<<t<<endl;
						fout<<Email<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>source;
						fout<<source<<endl;
						fin>>destination;
						fout<<destination<<endl;
						fin>>nos;
						fin>>price;
						fout<<price*t<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<t<<endl;
						html<<"<br>Train: "<<name<<endl;
						html<<"<br>Source: "<<source<<endl;
						html<<"<br>Destination: "<<destination<<endl;
						html<<"<br>Price: "<<price*t<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>type;
						foun<<type<<endl;
						fin>>name;
						foun<<name<<endl;
						fin>>source;
						foun<<source<<endl;
						fin>>destination;
						foun<<destination<<endl;
						fin>>nos;
						foun<<nos-t<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				int st=remove("train.txt");
				int st1=rename("train1.txt","train.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
	default:
		cout<<"\nIncorrect Choice!\n\n";
		train(uname);

    }
}
void bus(string uname)
{
	int e;
    system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
    cout<<"Buses\n\n";
    cout<<"1) Sleeper.\n";
    cout<<"2) Semi-Sleeper.\n";
    cout<<"3) Go back to main page.\n";
    cout<<"4) Go back to account home.\n\n";
    cout<<"Enter your choice(1-4): ";
    cin>>e;
    if(e==3)
    	main_page();
    if(e==4)
    	user_page(uname);
	system("cls");
    char s[30],d[30];
    int t;
    cout<<"Source: ";
    fflush(stdin);
    cin.getline(s,sizeof(s));
    strcpy(s,deblank(s));
	s[0]=toupper(s[0]);
    cout<<"\nDestination: ";
    cin.getline(d,sizeof(d));
    strcpy(d,deblank(d));
    d[0]=toupper(d[0]);
    cout<<"\nNo. of tickets: ";
    cin>>t;
    ifstream fin("bus.txt",ios::in);
    int id;
    char type[2],name[30],source[30],destination[30],line[30];
    int nos,search=0,i=0;
    float price;
    switch (e)
    {
    case 1:
        {
            system("cls");
            while(!fin.eof())
			{
				i++;
				fin>>id;
				fin>>line;
				if(strcmp(line,"sl")==0)
				{
					fin>>name;
					fin>>source;
					fin>>destination;
					fin>>nos;
					fin>>price;
					if(strcmp(source,s)==0 && strcmp(destination,d)==0 && nos>=t)
					{
						cout<<"\n\nId: "<<i<<"\nBus Operator: "<<name<<"\nSource: "<<source<<"\nDestination: "<<destination<<"\nNumber of seats available: ";
						cout<<nos<<"\nPrice: "<<price*t;
						search=1;
					}
				}
				else
				{
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no buses found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("bus.txt",ios::in);
				fstream foun("bus1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fin>>type;
						fout<<"4"<<endl;
						fout<<t<<endl;
						fout<<Email<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>source;
						fout<<source<<endl;
						fin>>destination;
						fout<<destination<<endl;
						fin>>nos;
						fin>>price;
						fout<<price*t<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<t<<endl;
						html<<"<br>Bus: "<<name<<endl;
						html<<"<br>Source: "<<source<<endl;
						html<<"<br>Destination: "<<destination<<endl;
						html<<"<br>Price: "<<price*t<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>type;
						foun<<type<<endl;
						fin>>name;
						foun<<name<<endl;
						fin>>source;
						foun<<source<<endl;
						fin>>destination;
						foun<<destination<<endl;
						fin>>nos;
						foun<<nos-t<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				remove("bus.txt");
				rename("bus1.txt","bus.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }

    case 2:
        {
            system("cls");
            while(!fin.eof())
			{
				i++;
				fin>>id;
				fin>>line;
				if(strcmp(line,"se")==0)
				{
					fin>>name;
					fin>>source;
					fin>>destination;
					fin>>nos;
					fin>>price;
					if(strcmp(source,s)==0 && strcmp(destination,d)==0 && nos>=t)
					{
						cout<<"\n\nId: "<<i<<"\nBus Operator: "<<name<<"\nSource: "<<source<<"\nDestination: "<<destination<<"\nNumber of seats available: ";
						cout<<nos<<"\nPrice: "<<price*t;
						search=1;
					}
				}
				else
				{
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
					fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no buses found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("bus.txt",ios::in);
				fstream foun("bus1.txt",ios::out|ios::app);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fin>>type;
						fout<<"4"<<endl;
						fout<<t<<endl;
						fout<<Email<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>source;
						fout<<source<<endl;
						fin>>destination;
						fout<<destination<<endl;
						fin>>nos;
						fin>>price;
						fout<<price*t<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<t<<endl;
						html<<"<br>Bus: "<<name<<endl;
						html<<"<br>Source: "<<source<<endl;
						html<<"<br>Destination: "<<destination<<endl;
						html<<"<br>Price: "<<price*t<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				fin.seekg(0);
				int j=0;
				while(!fin.eof())
				{
					fin>>id;
					if(j>0)
						foun<<endl<<id<<endl;
					else
						foun<<id<<endl;
					if(id==a)
					{
						fin>>type;
						foun<<type<<endl;
						fin>>name;
						foun<<name<<endl;
						fin>>source;
						foun<<source<<endl;
						fin>>destination;
						foun<<destination<<endl;
						fin>>nos;
						foun<<nos-t<<endl;
						fin>>price;
						foun<<price;
					}
					else
					{
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line<<endl;
						fin>>line;
						foun<<line;
					}
					j++;
				}
				fin.close();
				foun.close();
				remove("bus.txt");
				rename("bus1.txt","bus.txt");
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
	default:
		cout<<"\nIncorrect Choice!\n\n";
		bus(uname);
    }
}
void holiday(string uname)
{
	int f;
	system("cls");
    cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
	cout<<"Travel Packages\n\n";
    cout<<"1) International Destinations.\n";
    cout<<"2) Exotic Indian Destinations .\n";
    cout<<"3) Destination Wedding Packages.\n";
    cout<<"4) Pilgrimage Tour Packages\n";
    cout<<"5) Go back to main page.\n";
    cout<<"6) Go back to account home.\n\n";
    cout<<"Enter your choice(1-6): ";
    cin>>f;
    if(f==5)
    	main_page();
    if(f==6)
    	user_page(uname);
	int p;
    char d[100];
    system("cls");
    cout<<"Destination: ";
    fflush(stdin);
    cin.getline(d,sizeof(d));
    strcpy(d,deblank(d));
    d[0]=toupper(d[0]);
    int id;
    char type[3],name[30],location[30],line[30];
    int nights,days,search=0,i=0;
    float price;
    cout<<"No. of people: ";
    cin>>p;
    ifstream fin("holiday.txt",ios::in);
    switch (f)
    {
    case 1:
        {
            system("cls");
        	while(!fin.eof())
        	{
        		i++;
        		fin>>id;
        		fin>>type;
        		if(strcmp(type,"int")==0)
        		{
        			fin>>location;
	        		fin>>name;
	        		fin>>days;
	        		fin>>nights;
	        		fin>>price;
					if(strcmp(location,d)==0)
					{
						cout<<"\n\nId: "<<i<<"\nName: "<<name<<"\nLocation: "<<location<<"\nDays: "<<days<<"\nNights: "<<nights;
						cout<<"\nPrice: "<<price*p;
						search=1;
					}
				}
				else
        		{
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
				}
			}
			fin.close();
			if(search==0)
			{
				cout<<"\nSorry no holiday packages found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("holiday.txt",ios::in);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fin>>type;
						fout<<"5"<<endl;
						fout<<p<<endl;
						fout<<Email<<endl;
						fin>>location;
						fout<<location<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>days;
						fout<<days<<endl;
						fin>>nights;
						fout<<nights<<endl;
						fin>>price;
						fout<<price*p<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<p<<endl;
						html<<"<br>Trip: "<<name<<endl;
						html<<"<br>Location: "<<location<<endl;
						html<<"<br>Days: "<<days<<endl;
						html<<"<br>Nights: "<<nights<<endl;
						html<<"<br>Price: "<<price*p<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }

    case 2:
        {
            system("cls");
        	while(!fin.eof())
        	{
        		i++;
        		fin>>id;
        		fin>>type;
        		if(strcmp(type,"ind")==0)
        		{
        			fin>>location;
	        		fin>>name;
	        		fin>>days;
	        		fin>>nights;
	        		fin>>price;
					if(strcmp(location,d)==0)
					{
						cout<<"\n\nId: "<<i<<"\nName: "<<name<<"\nLocation: "<<location<<"\nDays: "<<days<<"\nNights: "<<nights;
						cout<<"\nPrice: "<<price*p;
						search=1;
					}
				}
				else
        		{
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
				}
			}
			if(search==0)
			{
				cout<<"\nSorry no holiday packages found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("holiday.txt",ios::in);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fin>>type;
						fout<<"5"<<endl;
						fout<<p<<endl;
						fout<<Email<<endl;
						fin>>location;
						fout<<location<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>days;
						fout<<days<<endl;
						fin>>nights;
						fout<<nights<<endl;
						fin>>price;
						fout<<price*p<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<p<<endl;
						html<<"<br>Trip: "<<name<<endl;
						html<<"<br>Location: "<<location<<endl;
						html<<"<br>Days: "<<days<<endl;
						html<<"<br>Nights: "<<nights<<endl;
						html<<"<br>Price: "<<price*p<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
    case 3:
        {
            system("cls");
        	while(!fin.eof())
        	{
        		fin>>id;
        		fin>>type;
        		if(strcmp(type,"des")==0)
        		{
        			i++;
        			fin>>location;
	        		fin>>name;
	        		fin>>days;
	        		fin>>nights;
	        		fin>>price;
					if(strcmp(location,d)==0)
					{
						cout<<"\n\nId: "<<i<<"\nName: "<<name<<"\nLocation: "<<location<<"\nDays: "<<days<<"\nNights: "<<nights;
						cout<<"\nPrice: "<<price*p;
						search=1;
					}
				}
				else
        		{
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
				}
			}
			if(search==0)
			{
				cout<<"\nSorry no holiday packages found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("holiday.txt",ios::in);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fin>>type;
						fout<<"5"<<endl;
						fout<<p<<endl;
						fout<<Email<<endl;
						fin>>location;
						fout<<location<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>days;
						fout<<days<<endl;
						fin>>nights;
						fout<<nights<<endl;
						fin>>price;
						fout<<price*p<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<p<<endl;
						html<<"<br>Trip: "<<name<<endl;
						html<<"<br>Location: "<<location<<endl;
						html<<"<br>Days: "<<days<<endl;
						html<<"<br>Nights: "<<nights<<endl;
						html<<"<br>Price: "<<price*p<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
    case 4:
        {
            system("cls");
        	while(!fin.eof())
        	{
        		i++;
        		fin>>id;
        		fin>>type;
        		if(strcmp(type,"pil")==0)
        		{
        			fin>>location;
	        		fin>>name;
	        		fin>>days;
	        		fin>>nights;
	        		fin>>price;
					if(strcmp(location,d)==0)
					{
						cout<<"\n\nId: "<<i<<"\nName: "<<name<<"\nLocation: "<<location<<"\nDays: "<<days<<"\nNights: "<<nights;
						cout<<"\nPrice: "<<price*p;
						search=1;
					}
				}
				else
        		{
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
        			fin>>line;
				}
			}
			if(search==0)
			{
				cout<<"\nSorry no holiday packages found matching your preference!";
			}
			else if(search>0)
			{
				int a=get_user()+1000;
				ifstream fin("holiday.txt",ios::in);
				ofstream fout("ticket.txt",ios::out|ios::app);
				cout<<endl;
				payment_page();
				while(!fin.eof())
				{
					fin>>id;
					if(id==a)
					{
						fin>>type;
						fout<<"5"<<endl;
						fout<<p<<endl;
						fout<<Email<<endl;
						fin>>location;
						fout<<location<<endl;
						fin>>name;
						fout<<name<<endl;
						fin>>days;
						fout<<days<<endl;
						fin>>nights;
						fout<<nights<<endl;
						fin>>price;
						fout<<price*p<<endl;
						ofstream html("ticket.html",ios::out);
						html<<"<h2 style='text-align: center;'>Your ticket</h2>"<<endl;
						html<<"<br>Number of tickets: "<<p<<endl;
						html<<"<br>Trip: "<<name<<endl;
						html<<"<br>Location: "<<location<<endl;
						html<<"<br>Days: "<<days<<endl;
						html<<"<br>Nights: "<<nights<<endl;
						html<<"<br>Price: "<<price*p<<endl;
						ShellExecute(0, 0, "ticket.html", 0, 0, SW_SHOW);
					}
					else
					{
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
						fin>>line;
					}
				}
				cout<<"\nSuccessfully Booked.\n\n";
				system("pause");
				main_page();
			}
			exit(0);
            break;
        }
	default:
		cout<<"\nIncorrect Choice!\n\n";
		holiday(uname);
    }
}
void book_page(string uname)
{
	int a;
    system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
    cout<<"Our services\n";
    cout<<"1) Flights.\n";
    cout<<"2) Hotels.\n";
    cout<<"3) Trains.\n";
    cout<<"4) Buses.\n";
    cout<<"5) Holiday Packages.\n";
    cout<<"6) Go back to main page.\n";
    cout<<"7) Go back to user page.\n\n";
    cout<<"Enter your choice(1-7): ";
    cin>>a;
    switch (a)
    {
    case 1:
        {
            flight(uname);
            break;
        }

    case 2:
        {
            hotel(uname);
            break;
        }
    case 3:
        {
            train(uname);
            break;
        }
    case 4:
        {
            bus(uname);
            break;
        }
    case 5:
        {
            holiday(uname);
            break;
        }
    case 6:
    	{
    		main_page();
    		break;
		}
	case 7:
		{
			user_page(uname);
			break;
		}
    default:
    	cout<<"\nIncorrect choice!!";
    	book_page(uname);
    }
}
ofstream excel("myticket.csv",ios::out);
ofstream excel1("holiday.csv",ios::out);
void writeCSV(string s1, string s2, string s3, string s4, string s5, string s6)
{
	excel<<s1<<","<<s2<<","<<s3<<","<<s4<<","<<s5<<","<<s6<<endl;
}
void writeCSVHol(string s1, string s2, string s3, string s4, string s5, string s6,string s7)
{
	excel1<<s1<<","<<s2<<","<<s3<<","<<s4<<","<<s5<<","<<s6<<","<<s7<<endl;
}
void user_page(string fname)
{
	system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
    cout<<"User: "<<fname<<"\n";
    cout<<"1) Transaction History\n";
    cout<<"2) Book a new Ticket\n";
    cout<<"3) Go back to main page.\n";
    cout<<"4) Logout\n\n";
    cout<<"Enter your choice(1-4): ";
    int a;
    cin>>a;
    ifstream fin("ticket.txt",ios::in);
    switch (a) {

        case 1:
        	{
        		system("cls");
	        	writeCSV("Type", "Email", "Company", "Source", "Destination", "Price");
	        	writeCSVHol("Type", "Email", "Company", "Source", "Days", "Nights", "Price");
	        	string line,company,source,destination,price,type,days,nights;
	        	int i=0;
	        	while(!fin.eof())
	        	{
	        		fin>>type;
	        		if(type=="1" || type=="3" || type=="4")
	        		{
	        			fin>>line;
	        			fin>>line;
	        			if(line==Email)
	        			{
	        				fin>>company;
	        				fin>>source;
	        				fin>>destination;
	        				fin>>price;
						}
						else
						{
							fin>>line;
							fin>>line;
							fin>>line;
							fin>>line;
						}
						if(type=="1")
							type="Flight";
						else if(type=="3")
							type="Train";
						else if(type=="4")
							type="Bus";
						writeCSV(type,Email,company,source,destination,price);
					}
					else if(type=="2")
					{
						fin>>line;
						fin>>line;
						if(line==Email)
						{
							fin>>company;
							fin>>destination;
							fin>>price;
						}
						else
						{
							fin>>line;
							fin>>line;
							fin>>line;
						}
						type="Hotel";
						writeCSV(type,Email,company,"Nil",destination,price);
					}
					else if(type=="5")
					{
						fin>>line;
						fin>>line;
						if(line==Email)
						{
							fin>>source;
							fin>>company;
							fin>>days;
							fin>>nights;
							fin>>price;
						}
						else
						{
							fin>>line;
							fin>>line;
							fin>>line;
							fin>>line;
							fin>>line;
						}
						type="Holiday";
						writeCSVHol(type,Email,company,source,days,nights,price);
					}
				}
				cout<<"Successfully generated file. Open myticket and holiday file!\n\n";
				system("pause");
				user_page(fname);
	        	exit(0);
			}
            break;

        case 2:
        	book_page(fname);
            break;
        case 3:
        	main_page();
        	break;
        case 4:
        	thank_you();
        default:
        	cout<<"\nIncorrect choice!";
    }
}
void enter(int ch)
{
	system("cls");
	cout<<"\nDon't put spaces!!\n";
	string type,name,source,destination,nos,price,line;
	int id;
	cout<<"\nType: ";
	cin>>type;
	transform(type.begin(), type.end(), type.begin(), ::tolower);
	if(ch==1)
	{
		if(type=="dom" || type=="int")
		{
			cout<<"\nName of airlines: ";
			cin>>name;
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			name[0]=toupper(name[0]);
		}
		else
		{
			cout<<"\nIncorrect type. The types are dom- Domestic and int- International.\n\n";
			system("pause");
			enter(ch);
		}
	}
	else if(ch==2)
	{
		if(type=="se" || type=="sl")
		{
			cout<<"\nName of bus travels: ";
			cin>>name;
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			name[0]=toupper(name[0]);
		}
		else
		{
			cout<<"\nIncorrect type. The types are se-Semi Sleeper and sl-Sleeper\n\n";
			system("pause");
			enter(ch);
		}
	}
	else if(ch==3)
	{
		if(type=="e")
		{
			cout<<"\nName of train: ";
			cin>>name;
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			name[0]=toupper(name[0]);
		}
		else
		{
			cout<<"\nIncorrect type. The types are e-Express\n\n";
			system("pause");
			enter(ch);
		}
	}
	cout<<"\nSource: ";
	cin>>source;
	transform(source.begin(), source.end(), source.begin(), ::tolower);
	source[0]=toupper(source[0]);
	cout<<"\nDestination: ";
	cin>>destination;
	transform(destination.begin(), destination.end(), destination.begin(), ::tolower);
	destination[0]=toupper(destination[0]);
	cout<<"\nNumber of tickets: ";
	cin>>nos;
	cout<<"\nPrice: ";
	cin>>price;
	if(ch==1)
	{
		ifstream fin("flight.txt",ios::in);
		while(!fin.eof())
		{
			fin>>id;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
		}
		id=id+1;
		fin.close();
		ofstream fout("flight.txt",ios::out|ios::app);
		if(id>=1000 && id<=10000)
			fout<<endl<<id<<endl<<type<<endl<<name<<endl<<source<<endl<<destination<<endl<<nos<<endl<<price;
		else
			fout<<"1001"<<endl<<type<<endl<<name<<endl<<source<<endl<<destination<<endl<<nos<<endl<<price;
	}
	else if(ch==2)
	{
		ifstream fin("bus.txt",ios::in);
		while(!fin.eof())
		{
			fin>>id;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
		}
		id=id+1;
		fin.close();
		ofstream fout("bus.txt",ios::out|ios::app);
		if(id>=1000 && id<=10000)
			fout<<endl<<id<<endl<<type<<endl<<name<<endl<<source<<endl<<destination<<endl<<nos<<endl<<price;
		else
			fout<<"1001"<<endl<<type<<endl<<name<<endl<<source<<endl<<destination<<endl<<nos<<endl<<price;
	}
	else if(ch==3)
	{
		ifstream fin("train.txt",ios::in);
		while(!fin.eof())
		{
			fin>>id;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
			fin>>line;
		}
		id=id+1;
		fin.close();
		ofstream fout("train.txt",ios::out|ios::app);
		if(id>=1000 && id<=10000)
			fout<<endl<<id<<endl<<type<<endl<<name<<endl<<source<<endl<<destination<<endl<<nos<<endl<<price;
		else
			fout<<"1001"<<endl<<type<<endl<<name<<endl<<source<<endl<<destination<<endl<<nos<<endl<<price;
	}
}
void enter_hol()
{
	system("cls");
	string type,name,destination,days,nights,price,line;
	int id;
	cout<<"\nDon't put spaces!!\n";
	cout<<"\nType: ";
	cin>>type;
	transform(type.begin(), type.end(), type.begin(), ::tolower);
	if(type=="int" || type=="des" || type=="ind" || type=="pil")
	{
		cout<<"\nDestination: ";
		cin>>destination;
		transform(destination.begin(), destination.end(), destination.begin(), ::tolower);
		destination[0]=toupper(destination[0]);
	}
	else
	{
		cout<<"\nIncorrect type. The types are int-International, des-Destination Wedding, ind-India, pil-Pilgrimage.\n\n";
		system("pause");
		enter_hol();
	}
	cout<<"\nName of package: ";
	cin>>name;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	name[0]=toupper(name[0]);
	cout<<"\nDays: ";
	cin>>days;
	cout<<"\nNights: ";
	cin>>nights;
	cout<<"\nPrice: ";
	cin>>price;
	fstream fin("holiday.txt",ios::in);
	while(!fin.eof())
	{
		fin>>id;
		fin>>line;
		fin>>line;
		fin>>line;
		fin>>line;
		fin>>line;
		fin>>line;
	}
	id=id+1;
	fin.close();
	ofstream fout("holiday.txt",ios::out|ios::app);
	if(id>=1000 && id<=10000)
		fout<<endl<<id<<endl<<type<<endl<<destination<<endl<<name<<endl<<days<<endl<<nights<<endl<<price;
	else
		fout<<"1001"<<endl<<type<<endl<<destination<<endl<<name<<endl<<days<<endl<<nights<<endl<<price;
}
void enter_hot()
{
	system("cls");
	string type,occupancy,name,location,nos,price,line;
	int id;
	cout<<"\nDon't put spaces!!\n";
	cout<<"\nType: ";
	cin>>type;
	transform(type.begin(), type.end(), type.begin(), ::tolower);
	if(type=="d" || type=="e")
	{
		cout<<"\nOccupancy: ";
		cin>>occupancy;
	}
	else
	{
		cout<<"\nIncorrect type. The types are d-Delux and e-Executive.\n\n";
		system("pause");
		enter_hot();
	}
	cout<<"\nName of hotel: ";
	cin>>name;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	name[0]=toupper(name[0]);
	cout<<"\nLocation: ";
	cin>>location;
	transform(location.begin(), location.end(), location.begin(), ::tolower);
	location[0]=toupper(location[0]);
	cout<<"\nNumber of rooms: ";
	cin>>nos;
	cout<<"\nPrice: ";
	cin>>price;
	fstream fin("hotel.txt",ios::in);
	while(!fin.eof())
	{
		fin>>id;
		fin>>line;
		fin>>line;
		fin>>line;
		fin>>line;
		fin>>line;
		fin>>line;
	}
	id=id+1;
	fin.close();
	ofstream fout("hotel.txt",ios::out|ios::app);
	if(id>=1000 && id<=10000)
		fout<<endl<<id<<endl<<type<<endl<<occupancy<<endl<<name<<endl<<location<<endl<<nos<<endl<<price;
	else
		fout<<"1001"<<endl<<type<<endl<<occupancy<<endl<<name<<endl<<location<<endl<<nos<<endl<<price;
}
void admin_page(string fname)
{
	int a;
	system("cls");
    cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************";
	cout<<"\n\t\t\t\tADMIN ACCOUNT\n";
    cout<<"User: "<<fname<<"\n";
    cout<<"1) Add Flight\n";
    cout<<"2) Add Hotel\n";
    cout<<"3) Add Bus\n";
    cout<<"4) Add Train\n";
    cout<<"5) Add Holiday Package\n";
    cout<<"6) See Tickets Booked\n";
    cout<<"7) Go to main page\n\n";
    cout<<"Enter your choice(1-5)\n";
    cin>>a;
    switch (a){

        case 1:
			enter(1);
			cout<<"\nSuccessfully added to database!\n\n";
			system("pause");
			admin_page(fname);
            break;

        case 2:
			enter_hot();
			cout<<"\nSuccessfully added to database!\n\n";
			system("pause");
			admin_page(fname);
            break;
        case 3:
			enter(2);
			cout<<"\nSuccessfully added to database!\n\n";
			system("pause");
			admin_page(fname);
            break;
        case 4:
			enter(3);
			cout<<"\nSuccessfully added to database!\n\n";
			system("pause");
			admin_page(fname);
            break;
        case 5:
			enter_hol();
			cout<<"\nSuccessfully added to database!\n\n";
			system("pause");
			admin_page(fname);
			break;
		case 6:
			{
				writeCSV("Type", "Email", "Company", "Source", "Destination", "Price");
		        writeCSVHol("Type", "Email", "Company", "Source", "Days", "Nights", "Price");
		        string line,company,source,destination,price,type,days,nights;
		    	int i=0;
		    	ifstream fin("ticket.txt",ios::in);
		    	while(!fin.eof())
		    	{
		    		fin>>type;
		    		if(type=="1" || type=="3" || type=="4")
		    		{
		    			fin>>line;
		    			fin>>line;
	    				fin>>company;
	    				fin>>source;
	    				fin>>destination;
	    				fin>>price;
						if(type=="1")
							type="Flight";
						else if(type=="3")
							type="Train";
						else if(type=="4")
							type="Bus";
						writeCSV(type,"Nil",company,source,destination,price);
					}
					else if(type=="2")
					{
						fin>>line;
						fin>>line;
						fin>>company;
						fin>>destination;
						fin>>price;
						type="Hotel";
						writeCSV(type,"Nil",company,"Nil",destination,price);
					}
					else if(type=="5")
					{
						fin>>line;
						fin>>line;
						fin>>source;
						fin>>company;
						fin>>days;
						fin>>nights;
						fin>>price;
						type="Holiday";
						writeCSVHol(type,"Nil",company,source,days,nights,price);
					}
				}
				system("cls");
				cout<<"Successfully generated file. Open myticket and holiday file!\n\n";
				system("pause");
				admin_page(fname);
		    	exit(0);
			}
			break;
		case 7:
			main_page();
		default:
			cout<<"\nIncorrect choice!";
    }
}
class user
{
	public:
		char mobile[10];
		string pass,cpass,email,mail,fname,lname,pkey;
		void signup()
		{
			system("cls");
			cout<<"\n\t\t\t\tDREAM TRAVELS";
			cout<<"\n\t\t\t\t*************\n";
			cout<<"\nEnter first name: ";
			cin>>fname;
			fflush(stdin);
			cout<<"\nEnter last name: ";
			cin>>lname;
			fflush(stdin);
			cout<<"\nEnter email address: ";
			cin>>email;
			mail=email;
			validate_email(mail);
			cout<<"\nEnter mobile number: ";
			cin>>mobile;
			cout<<"\nEnter password: ";
			cin>>pass;
			cout<<"\nConfirm password: ";
			cin>>cpass;
			cout<<"\nEnter 16 character product key: ";
			cin>>pkey;
		}
		int login()
		{
			char line[30],name[30]="";
			int log=0;
			ifstream fin1("admin.txt",ios::in);
			ifstream fin2("users.txt",ios::in);
			system("cls");
			cout<<"\n\t\t\t\tDREAM TRAVELS";
			cout<<"\n\t\t\t\t*************\n";
			cout<<"\nEnter email address: ";
			cin>>email;
			Email=email;
			cout<<"\nEnter password: ";
			cin>>pass;
			int error=0;
			if(validate_email(email)!=3)
			{
				cout<<"\nInvalid email address.";
				error++;
				cout<<"\n\n";
				system("pause");
				login();
			}
			ifstream fin("file.txt",ios::in);
			if(!fin)
			{
				cout<<"\nPaste the file sent to you in the folder where you installed Dream Travels.";
			}
			string uname;
			if(error==0)
			{
				if(fin1)
				{
					while(!fin1.eof())
					{
						fin1>>line;
						if(email==line)
						{
							fin1>>line;
							uname=line;
							fin1>>line;
							fin1>>line;
							if(pass==line)
							{
								cout<<"\nWelcome back "<<uname;
								cout<<"\n\n";
								system("pause");
								log=1;
								admin_page(uname);
							}
							else
							{
								cout<<"\nWrong credentials";
								cout<<"\n\n";
								system("pause");
								log=1;
								login();
							}
						}
						else
						{
							log=0;
						}
					}	
				}
				if(log==0)
				{
					if(fin2)
					{
						while(!fin2.eof())
						{
							fin2>>line;
							if(email==line)
							{
								fin2>>line;
								uname=line;
								fin2>>line;
								fin2>>line;
								if(pass==line)
								{
									cout<<"\nWelcome back "<<uname;
									cout<<"\n\n";
									system("pause");
									log=1;
									user_page(uname);
								}
								else
								{
									cout<<"\nWrong credentials";
									cout<<"\n\n";
									system("pause");
									log=1;
									login();
								}
							}
							else
							{
								log=0;
							}
						}	
					}
				}
				if(log==0)
				{
					cout<<"\nAccount does not exist. Sign up first!";
					cout<<"\n\n";
					system("pause");
					main_page();
				}
			}
	}
};
void write(user nuser)
{
	if(nuser.pkey[0]=='a' && nuser.pkey[1]=='d' && nuser.pkey[2]=='m')
	{
		ofstream fout1("admin.txt",ios::out|ios::app);
		fout1<<nuser.mobile<<"\n"<<nuser.email<<"\n";
		fout1<<nuser.fname<<"\n"<<nuser.lname;
		fout1<<"\n"<<nuser.pass<<"\n"<<nuser.pkey;
	}
	else
	{
		ofstream fout2("users.txt",ios::out|ios::app);
		fout2<<nuser.mobile<<"\n"<<nuser.email<<"\n";
		fout2<<nuser.fname<<"\n"<<nuser.lname;
		fout2<<"\n"<<nuser.pass<<"\n"<<nuser.pkey;
	}

}
int main_page()
{
	int ch;
	user nuser;
	system("cls");
	cout<<"\n\t\t\t\tDREAM TRAVELS";
	cout<<"\n\t\t\t\t*************\n";
	cout<<"\n1)Login";
	cout<<"\n2)Signup";
	cout<<"\n3)Exit";
	cout<<"\n\nEnter your choice (1-3): ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			nuser.login();
			break;
		case 2:
			{
				nuser.signup();
				char url[100] = "http://newwebsite-com.stackstaging.com/index.php?email=";
				strcat(url,nuser.mail.c_str());
				int error=0;
				if(validate_email(nuser.mail)!=3)
				{
					cout<<"\nInvalid email address.";
					error++;
				}
				if(validate_mobile(nuser.mobile)>0)
				{
					cout<<"\nInvalid mobile number.";
					error++;
				}
				if(validate_password(nuser.pass)==1)
				{
					cout<<"\nPassword should be between 10 to 20 chars.";
					error++;
				}
				if(nuser.pass!=nuser.cpass)
				{
					cout<<"\nPasswords do not match.";
					error++;
				}
				if(validate_prod_key(nuser.pkey)>0)
				{
					cout<<"\nInvalid product key.";
					error++;
				}
				ifstream fin1("admin.txt",ios::in);
				ifstream fin2("users.txt",ios::in);
				char line[30];
				if(nuser.pkey[0]=='a' && nuser.pkey[1]=='d' && nuser.pkey[2]=='m')
				{
					if(fin1)
					{
						cout<<"\nOnly one admin account can be created.";
						error++;
					}
				}
				if(fin1 && fin2)
				{
					while(!fin1.eof())
					{
						fin1>>line;
						if(nuser.email==line)
						{
							cout<<"\nAccount already exists. You are an admin.";
							error++;
						}
						else if(strcmp(nuser.mobile,line)==0)
						{
							cout<<"\nAccount already exists.";
							error++;
						}
					}
					while(!fin2.eof())
					{
						fin2>>line;
						if(nuser.email==line)
						{
							cout<<"\nAccount already exists.";
							error++;
						}
						else if(strcmp(nuser.mobile,line)==0)
						{
							cout<<"\nAccount already exists.";
							error++;
						}
					}
				}
				if(error>0)
				{
					cout<<"\n\n";
					system("pause");
					nuser.signup();
				}
				else
				{
					ShellExecute(0, 0, url, 0, 0, SW_SHOW);
					write(nuser);
					exit(0);
				}
			}
			break;
		case 3:
			thank_you();
			break;
		default:
			cout<<"\nIncorrect choice!";
			main_page();
	}
	return ch;
}
int main()
{
	main_page();
	return 0;
}
