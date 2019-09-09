/*
Project Title:Chat System
Version      :1.0
Developed By :Shivam Bairoliya, Samarthya Jha
*/


#include<dos.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int user,control;
struct date d;
struct time t;
char name1[20],name2[20];

void opening();
int size();
int nofEnters(char[]);
void nameInput1();
void nameInput2();
void box();
void credentials();
void clear();
void write();
char* read();
void run();
int fileNo();
void chatcopy(char[]);
void chatRecord();
void menu();

class Record
{
	int sNo;
	char nam1[20];
	char nam2[20];
	char filename[10];
	char date[15];
	char time[10];
	public:
	Record(int Serial,char filenamet[])
	{
		sNo=Serial;
		strcpy(nam1,name1);
		strcpy(nam2,name2);
		strcpy(filename,filenamet);
		getdate(&d);
		char days[2];
		itoa(d.da_day,days,10);
		strcpy(date,days);
		strcat(date,"-");
		char month[2];
		itoa(d.da_mon,month,10);
		strcat(date,month);
		strcat(date,"-");
		char year[4];
		itoa(d.da_year,year,10);
		strcat(date,year);
		gettime(&t);
		char hours[2];
		itoa(t.ti_hour,hours,10);
		strcpy(time,hours);
		strcat(time,":");
		char minute[2];
		itoa(t.ti_min,minute,10);
		strcat(time,minute);
		strcat(time,":");
		char second[2];
		itoa(t.ti_sec,second,10);
		strcat(time,second);
	}
	int RsNo()
	{
		return sNo;
	}
	char* Rnam1()
	{
		return nam1;
	}
	char* Rnam2()
	{
		return nam2;
	}
	char* Rdate()
	{
		return date;
	}
	char* Rtime()
	{
		return time;
	}
};
void opening()
{
	clrscr();
	textbackground(0);
	gotoxy(24,4);
	textcolor(4+128);
	cprintf("WELCOME TO THE HELLO CHAT!!!!!");
	gotoxy(4,7);
	textcolor(2);
	cprintf(".>YOU WILL HAVE TO ENTER A USER NO. WHICH CAN EITHER BE 1 OR         	          2.");
	gotoxy(4,8);
	cprintf(".>PLEASE NOTE THAT THE USER NO. CANNOT BE THE SAME FOR BOTH 		       USERS.");
	gotoxy(4,9);
	cprintf(".>EACH SINGLE MESSAGE CANNOT HAVE MORE THAN 80 CHARACTERS.");
	gotoxy(4,10);
	cprintf(".>THE FIRST MESSAGE HAS TO BE ENTERED BY USER 1 AND THEN BY USER 	          2");
	gotoxy(4,11);
	cprintf(".>A USER CANNOT WRITE A MESSAGE WHILE THE OTHER IS TYPING");
	gotoxy(4,12);
	cprintf(".>ONLY TEXT MESSAGES ARE ALLOWED");
	gotoxy(4,13);
	cprintf(".>PLEASE ENTER SHORT NAMES(<10 characters)");
	gotoxy(4,14);
	cprintf(".>TO EXIT, PRESS ESC KEY");
	gotoxy(18,15);
	textcolor(5);
	cprintf(".>BY CONTINUING YOU AGREE TO OUR PRIVACY POLICY:");
	gotoxy(4,16);
	cprintf(".>OUR POLICY STATES THAT:");
	gotoxy(6,17);
	textcolor(14);
	cprintf(".>The chats taken place will be stored by the programmer");
	gotoxy(6,18);
	cprintf(".>The programmer may reproduce the chats for further 	                    		   references");
	gotoxy(6,19);
	cprintf(".>The false reproduction of this code is illegal");
	gotoxy(36,22);
	textcolor(4+BLINK);
	cprintf("ENJOY!!!!");
	gotoxy(4,23);
	textcolor(15);
	cprintf(".>PRESS ANY OTHER KEY TO CONTINUE....");
	getch();
}
int size()
{
	ifstream file("R:\\PROJECT\\Chat.txt");
	int count=0;
	while(!file.eof())
	{
		count++;
		file.get();
	}
	file.close();
	return count;
}



int nofEnters(char fname[])
{
	ifstream file(fname);
	int count=0;
	char temp[80];
	while(!file.eof())
	{
		file.getline(temp,80);
		count++;
	}
	file.close();
	return count;
}
void nameInput1()
{
	ofstream file("R:\\PROJECT\\Names.txt");
	cprintf(".>Enter your name:\n");
	gotoxy(32,13);
	char name[20];
	gets(name);
	file<<name<<endl;
	file.close();
}
void nameInput2()
{
	ofstream file("R:\\PROJECT\\Names.txt",ios::app);
	cprintf(".>Enter your name:\n");
	gotoxy(32,13);
	char name[20];
	gets(name);
	int check=1;
	while(check)
	{
		if(nofEnters("R:\\PROJECT\\Names.txt")==2)
		{
			check=0;
			file<<name<<endl;
		}
	}
	file.close();
}
void box()
{
	for(int i=8;i<=16;i++)
	{
		cout<<endl;
		for(int j=29;j<=54;j++)
		{
			if(i==8||i==16||j==29||j==54)
		       {
				gotoxy(j,i);
				textbackground(14);
				cprintf("  ");
		       }
		}
	}
}



void credentials()
{
	clrscr();
	box();
	gotoxy(32,10);
	textbackground(0);
	cprintf(".>Enter user no:\n");
	gotoxy(32,11);
	cin>>user;
	gotoxy(32,12);
	if(user==1)
		nameInput1();
	else
		nameInput2();
}
void clear()
{
	  ofstream file("R:\\PROJECT\\Chat.txt");
	  file<<"";
	  file.close();
}
void write()
{
	  ofstream file("R:\\PROJECT\\Chat.txt",ios::app);
	  char msg[80];
	  gets(msg);
	  file<<msg<<endl;
	  if(msg[0]==27)
	  control=0;
	  file.close();
}
char* read()
{
		 ifstream file("R:\\PROJECT\\Chat.txt");
		 int check=1;
		 int sizeTemp=size();
		 char msg[80];
		 int count=0;
		 if(size()!=1)
		 {
			while(count!=nofEnters("R:\\PROJECT\\Chat.txt")-1)
			{
				 file.getline(msg,80);
				 count++;
			}
		 }
		 while(check)
		 {
				  if(size()!=sizeTemp)
				  {
				    file.getline(msg,80);
					      check=0;
				  }
		 }
		 if(msg[0]==27)
		 control=0;
		 file.close();
		 return msg;
}

void run()
{
	  clrscr();
	  char message[80];
	  ifstream file("R:\\PROJECT\\Names.txt");
	  while(nofEnters("R:\\PROJECT\\Names.txt")!=3);
	  file.getline(name1,20);
	  file.getline(name2,20);
	  while(control)
	  {
		if(user==1)
		{
		  cout<<name1<<"\t>>";
		  write();
		  if(control)
		  {
			cout<<name2<<"\t>>";
			int x=wherex();
			int y=wherey();
			cprintf("%s",name2);
			cprintf(" is typing...");
			gotoxy(x,y);
			strcpy(message,read());
			cout<<"                                 ";
			gotoxy(x,y);
			cout<<message<<endl;

		  }
		}
		if(user==2)
		{
			cout<<name1<<"\t>>";
			int x=wherex();
			int y=wherey();
			cprintf("%s",name1);
			cprintf(" is typing...");
			gotoxy(x,y);
			strcpy(message,read());
			cout<<"                                 ";
			gotoxy(x,y);
			cout<<message<<endl;
			cout<<name2<<"\t>>";
			write();
		}
	  }
	  file.close();
}




int fileNo()
{
	fstream file("R:\\PROJECT\\Record.dat",ios::binary|ios::in);
	file.seekg(0,ios::end);
	int nor=file.tellg()/sizeof(Record);
	if(file.tellg()==0)
	{
		file.close();
		return 1;
	}
	Record R(999,"a");
	file.seekg(sizeof(Record)*(nor-1));
	file.read((char*)&R,sizeof(Record));
	cout<<endl;
	file.close();
	return (R.RsNo()+1);
}
void chatcopy(char filename[])
{
      ifstream file("R:\\PROJECT\\Chat.txt");
      ofstream file1(filename);
      char linecopy[80];
      int control=1;
      while(file.getline(linecopy,80))
      {
	    if(control==1)
	    file1<<name1<<"\t>>"<<linecopy<<endl;
	    if(control==-1)
	    file1<<name2<<"\t>>"<<linecopy<<endl;
	    control*=-1;
      }
      file.close();
      file1.close();
}
void chatRecord()
{
      if(user==1)
      {	    													  fstream file("R:\\PROJECT\\Record.dat",ios::binary|ios::app|ios::out);
	  int tno=fileNo();
	  char fname[15];
	  itoa(tno,fname,10);
	  strcat(fname,".txt");
	  char tfname[20]={"R:\\PROJECT\\"};
	  strcat(tfname,fname);
	  chatcopy(tfname);
	  Record tempRecord(tno,fname);
	  file.write((char*)&tempRecord,sizeof(tempRecord));
	  file.close();
      }
}






void menu()
{
	clrscr();
	box();
	textbackground(0);
	gotoxy(32,10);
	cprintf("S.no.   Option");
	gotoxy(32,11);
	cprintf("1.      Chat");
	gotoxy(32,12);
	cprintf("2.      Read Chats");
	gotoxy(32,13);
	cprintf("3.      Exit");
	gotoxy(32,14);
	cprintf(".>Enter your choice:");
}
void readChats()
{
    clrscr();
    ifstream file("R:\\PROJECT\\Record.dat",ios::binary);
    gotoxy(17,3);
    cprintf(".>Enter date of the chat to read((d or dd)-(m or mm)-yyyy)");
    gotoxy(17,4);
    char inpdate[10];
    gets(inpdate);
    Record R(0,"a");
    int count=0;
    cout<<"Sno.\tParticipant1\tParticipant2\tTime\n";
    while(file.read((char*)&R,sizeof(R)))
      if(strcmpi(inpdate,R.Rdate())==0)
      {
		count=1;
cout<<R.RsNo()<<"\t"<<R.Rnam1()<<"\t\t"<<R.Rnam2()<<"\t\t";
cout<<<<R.Rtime()<<endl;
      }
    if(count==0)
	cout<<"\n\n.>Invalid date. No chat found.";
    else
    {
	cout<<".>Enter Sno of the file to open\n";
	int tsno;
	cin>>tsno;
	char tSno[10];
	itoa(tsno,tSno,10);
	strcat(tSno,".txt");
	char tfname[20]={"R:\\PROJECT\\"};
	strcat(tfname,tSno);
	ifstream file1(tfname);
	clrscr();
	cout<<tfname<<endl<<endl;
	char line[80];
	while(file1.getline(line,80))
	  cout<<line<<endl;
	file1.close();
    }
    getch();
    file.close();
}
void main()
{
    opening();
    int ch;
    do
    {
	clrscr();
	control=1;
	menu();
	cin>>ch;
	switch(ch)
	{
	  case 1:clear();
		   credentials();
		   run();
		   chatRecord();
		   break;
	  case 2:readChats();
		   break;
	  case 3:break;
	  default:cout<<"\n\n\nInvalid choice. Enter again please.";
		  getch();
	}
    }while(ch!=3);
}

