#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
class info
{
	private:
		char name[30];
		char add[100];
		char sex[4];
		char dob[15];
		char no[9];
		char mail[30];
		char pro[10];


	public:
		void get();
		void disp();
		void wtf();
		void rff();
		void search();
		void del();
		void mod();
}c;
void info::get()
{
		cout<<"\nFull Name             : ";
		cin>>name;
		cout<<"Address               : ";
		cin>>add;
		cout<<"Gender (Male/Female)  : ";
		cin>>sex;
		cout<<"Date Of Birth         : ";
		cin>>dob;
		cout<<"Mobile Number         : ";
		cin>>no;
		cout<<"E-mail ID             : ";
		cin>>mail;
		cout<<"Profession            : ";
		cin>>pro;

}
void info::disp()
{

    cout<<"\nName of Person : "<<name;
    cout<<"\nAddress        : "<<add;
    cout<<"\nSex            : "<<sex;
    cout<<"\nDate Of Birth  : "<<dob;
    cout<<"\nMobile Number  : "<<no;
    cout<<"\nEmail Address  : "<<mail;
    cout<<"\nProfession     : "<<pro;

}
void info::wtf()
{
    ofstream ofile;
    ofile.open("text.txt", ios::app);
    get();
    ofile.write((char*)&c, sizeof(c));
    cout<<"\t\tData Inserted Successfully";
    ofile.close();
}
void info::rff()
{
    ifstream ifile;
    ifile.open("text.txt");
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
	disp();
	ifile.read ((char*)&c, sizeof(c));
    cout<<"\n\n";
    }
    ifile.close();
}
void info::search()
{
    char m[20];
    ifstream ifile("text.txt");
    puts("Enter Name Of Person To Search");
    gets(m);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
	if (strcmpi(m, name)==0)
	    {
	    disp();
	    ifile.read((char*)&c, sizeof(c));
	    }
	       else{
    cout<<"not search";}
    }

    ifile.close();
    cout<<"Data Serched Successfully";
}
void info::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("text.txt", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    puts("Enter The Name Of Person To Delete");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
	if (strcmpi(b, name))
	    ofile.write((char*)&c, sizeof(c));
	ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("text.txt");
    rename("new", "text.txt");
    cout<<"Data Deleted Successfully";
}
void info::mod()
{
    char d[20];
    int p;
    puts("\nEnter Name Of Person To Update");
    gets(d);
    fstream f;
    f.open("text.txt", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a=f.tellg();
    while(! f.eof())
    {
	if (!strcmpi(d, name))
	{
	    puts("Choose Option To Change\n 1. name\n 2 Address\n 3 Sex\n 4Date Of Birth\n 5 Mobile Number\n 6 Email Address\n 7 Profession\n");
	    cin>>p;
	    switch(p)
	    {
	    case 1:
		gets(name);
		break;
	    case 2:
		cin>>add;
		break;
	    case 3:
		gets(sex);
		break;
	    case 4:
		gets(dob);
		break;
	    case 5:
		gets(no);
		break;
	    case 6:
		gets(mail);
		break;
	    case 7:
		gets(pro);
		break;
	    }
	    f.seekg(a-sizeof(c), ios::beg);
	    f.write((char*)&c, sizeof(c));
	}
	f.read((char*)&c, sizeof(c));
	a=f.tellg();
    }
    f.close();
    cout<<"Data Updated Successfully";
}
int main ()
{
	clrscr();
	cout<<"\n\n\t\t\t\tWelcome To The PIMS";
	cout<<"\n\t\t\tPersonal Information Mangament System \n";

	struct date d;
	getdate(&d);
	int dy,mn,yr;
	dy=d.da_day;
	mn=d.da_mon;
	yr=d.da_year;
	cout<<"\t\t\t\t   date:"<<dy<<"/"<<mn<<"/"<<yr;

    int num;
    char choice;

	cout<<"\n1. Add Recods\n";
	cout<<"2. Display Records\n";
	cout<<"3. Search Record\n";
	cout<<"4. Update Record\n";
	cout<<"5. Delete Records\n";

	cout<<"\n\n Enter your choice: ";
	cin>>num;

  do{
    switch(num)
    {
    case 1:
	c.wtf();
	break;
    case 2:
	c.rff();
	break;
    case 3:
	c.search();
	break;
    case 4:
	c.mod();
	break;
    case 5:
	c.del();
	break;
    default:
	cout<<"\nInvalid Choice Please Re-Enter !";
	break;
    }
    cout<<"\ncontinue? (y/n)\n";
    cin>>choice;
    }while(choice=='y');
	getch();
	return 0;
}