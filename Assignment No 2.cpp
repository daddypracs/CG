/*Problem Statement:-
Develop a program in C++ to create a database of student’s information
system containing the following  information: Name, Roll number, Class,
Division, Date of Birth, Blood group, Contact address, Telephone number,
Driving license no. and other. Construct the database with suitable member
functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, in-line
code and dynamic memory allocation operators-new and delete as well as
exception handling.
*/
#include <iostream>
#include <string.h>
using namespace std;
class Student
{
	char* name;
	char* rollno;
	char* division;
	char* dob;
	char* bg;
	char* address;
	char* teleno;
	char* dln;

public:
	static int count;
	Student() //Default Constructor
	{
		this->name = new char;
		this->rollno = new char;
		this->division = new char;
		this->dob = new char;
		this->bg = new char;
		this->address = new char;
		this->teleno = new char;
		this->dln = new char;
	}
	Student(char* name, char* rollno, char* division, char* dob, char* bg, char* address, char* teleno, char* dln)
	{
		//PARAMETERIZED CONSTRUCTOR
		cout << "PARAMETERIZD CONSTRUCTOR CALLED" << endl;
		int length = strlen(name);
		this->name = new char[length];
		this->name = name;
		length = strlen(rollno);
		this->rollno = new char[length];
		this->rollno = rollno;
		length = strlen(division);
		this->division = new char[length];
		this->division = division;
		length = strlen(dob);
		this->dob = new char[length];
		this->dob = dob;
		length = strlen(bg);
		this->bg = new char[length];
		this->bg = bg;
		length = strlen(address);
		this->address = new char[length];
		this->address = address;
		length = strlen(teleno);
		this->teleno = new char[length];
		this->teleno = teleno;
		length = strlen(dln);
		this->dln = new char[length];
		this->dln = dln;

		cout << "NAME                    : " << name << endl;
		cout << "ROLL NUMBER             : " << rollno << endl;
		cout << "DIVISION                : " << division << endl;
		cout << "DATE OF BIRTH           : " << dob << endl;
		cout << "BLOOD GROUP             : " << bg << endl;
		cout << "ADDRESS                 : " << address << endl;
		cout << "TELEPHONE NUMBER        : " << teleno << endl;
		cout << "DRIVING LICENSE NUMBER  : " << dln << endl;
	}
	Student(Student& s2)//Copy Constructor
	{
		this->name = s2.name;
		this->rollno = s2.rollno;
		this->division = s2.division;
		this->dob = s2.dob;
		this->bg = s2.bg;
		this->address = s2.address;
		this->teleno = s2.teleno;
		this->dln = s2.dln;
		cout << "Copy Constructor Called" << endl;
	}
	~Student()//Destructor
	{
		delete name;
		delete rollno;
		delete division;
		delete dob;
		delete bg;
		delete address;
		delete teleno;
		delete dln;
		cout << "RECORDS DESTROYED SUCCESSFULLY" << endl;
	}
	static void counter()
	{
		cout << "No Of Records Entered: " << count << endl;
	}
	inline void addata();
	void display();
	friend class Student1;
};
class Student1
{
	float marks;
	float totalmarks;
public:
	void percentage(Student& s)
	{
		float per;
		cout << "Enter Marks: " << endl;
		cin >> marks;
		cout << "Enter Total Marks: " << endl;
		cin >> totalmarks;
		per = (marks / totalmarks);
		per = per * 100;
		cout << "Percentage of " << s.rollno << " is " << per << " % " << endl;
	}
};
void Student::addata()
{

	cout << "ENTER NAME OF STUDENT:" << endl;
	cin >> name;
	cout << "ENTER ROLL NUMBER:" << endl;
	try
	{
		cin >> rollno;
		if (strlen(rollno) != 5)
		{
			throw rollno;
		}
	}
	catch (char*)
	{
		cout << "Enter Valid Roll Number:" << endl;
		cin >> rollno;
	}
	cout << "ENTER DIVISION" << endl;
	cin >> division;
	cout << "ENTER DATE OF BIRTH" << endl;
	cin >> dob;
	cout << "ENTER BLOOD GROUP" << endl;
	cin >> bg;
	cout << "ENTER ADDRESS" << endl;
	cin >> address;
	cout << "ENTER TELEPHONE NUMBER" << endl;
	try
	{
		cin >> teleno;
		if (strlen(teleno) != 10)
		{
			throw teleno;
		}
	}
	catch (char*)
	{
		cout << "Enter Valid Phone Number:" << endl;
		cin >> teleno;
	}
	cout << "ENTER DRIVING LICENSE NUMBER" << endl;
	cin >> dln;

}
void Student::display()
{
	cout << "NAME                    : " << name << endl;
	cout << "ROLL NUMBER             : " << rollno << endl;
	cout << "DIVISION	               : " << division << endl;
	cout << "DATE OF BIRTH           : " << dob << endl;
	cout << "BLOOD GROUP             : " << bg << endl;
	cout << "ADDRESS                 : " << address << endl;
	cout << "TELEPHONE NUMBER        : " << teleno << endl;
	cout << "DRIVING LICENSE NUMBER  : " << dln << endl;

}
int Student::count = 0;
int main()
{
	char* name;
	name = new char;
	char* rollno;
	rollno = new char;
	char* division;
	division = new char;
	char* dob;
	dob = new char;
	char* bg;
	bg = new char;
	char* address;
	address = new char;
	char* teleno;
	teleno = new char;
	char* dln;
	dln = new char;
	cout << "ENTER NAME:" << endl;
	cin >> name;
	cout << "ENTER ROLL NUMBER:" << endl;
	try
	{
		cin >> rollno;
		if (strlen(rollno) != 5)
		{
			throw rollno;
		}
	}
	catch (char*)
	{
		cout << "Enter Valid Roll Number:" << endl;
		cin >> rollno;
	}
	cout << "ENTER DIVISION" << endl;
	cin >> division;
	cout << "ENTER DATE OF BIRTH" << endl;
	cin >> dob;
	cout << "ENTER BLOOD GROUP" << endl;
	cin >> bg;
	cout << "ENTER ADDRESS" << endl;
	cin >> address;
	cout << "ENTER TELEPHONE NUMBER" << endl;
	try
	{
		cin >> teleno;
		if (strlen(teleno) != 10)
		{
			throw teleno;
		}
	}
	catch (char*)
	{
		cout << "Enter Valid Phone Number:" << endl;
		cin >> teleno;
	}
	cout << "ENTER DRIVING LICENSE NUMBER" << endl;
	cin >> dln;
	Student s1(name, rollno, division, dob, bg, address, teleno, dln);
	Student s2 = s1;
	int choice;
	cout << "Enter No. Of Records To Be Entered:" << endl;
	cin >> choice;
	Student::count = choice;
	for (int i = 0; i < choice; i++)
	{
		Student s0;
		s0.addata();
		s0.display();
		Student1 s1;
		s1.percentage(s0);
	}
	Student::counter();
	return 0;
}
