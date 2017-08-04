#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//struct declaration for Address Type
struct Address_type
{
	//variable declarations
	int street_no;
	string street_name;
	string street_main;
	string street_direction;
	string city;
	string state;
	int zip;
};
//struct declaration for Student Type
struct student_type
{
	//variable declarations
	string lname;
	string fname;
	int ID;
	float GPA;
	char classification;
	float account_balance;
	Address_type student_address;
};
//prototype functions
void print_students(student_type students[]);
int main()

{
	//variable declarations
	student_type students[5];
	ifstream myfile;
	myfile.open("infile.txt");
	//gathers data from infile and stores it in array
	//also contains lines to ignore excess end of line characters
	for (int i = 0; i < 5; i++)
	{
		myfile >> students[i].lname;
		myfile.ignore(100, '\n');
		myfile >> students[i].fname;
		myfile.ignore(100, '\n');
		myfile >> students[i].ID;
		myfile.ignore(100, '\n'); 
		myfile >> students[i].GPA;
		myfile.ignore(100, '\n');
		myfile >> students[i].classification;
		myfile.ignore(100, '\n');
		myfile >> students[i].account_balance;
		myfile.ignore(100, '\n'); 
		myfile >> students[i].student_address.street_no;
		myfile.ignore(100, '\n');
		myfile >> students[i].student_address.street_name;
		myfile >> students[i].student_address.street_main;
		myfile >> students[i].student_address.street_direction;
		myfile >> students[i].student_address.city;
		myfile.ignore(100, '\n'); 
		myfile >> students[i].student_address.state;
		myfile.ignore(100, '\n');
		myfile >> students[i].student_address.zip;
	}
	//function call to display data for each student
	print_students(students);
	return 0;
}
//displays data for each student
void print_students(student_type students[])
{
	//prints header
	cout << "Student Name" << '\t' << "ID Number" << '\t' << "GPA" << '\t'
		<< "Classification" << '\t' << "Account Balance" << '\t' << '\t' << "Address" << endl << endl;
	//prints out each student's data in the students array
	for (int i = 0; i < 5; i++)
	{
		cout << fixed << showpoint;
		cout << students[i].fname << " " << students[i].lname << '\t';
		cout << students[i].ID << '\t' << '\t';
		cout << setprecision(2) << students[i].GPA << '\t';
		cout << students[i].classification << '\t' << '\t';
		cout << "$" << students[i].account_balance << '\t' << '\t';
		cout << students[i].student_address.street_no << " " << students[i].student_address.street_name << " "
			<< students[i].student_address.street_main << " " << students[i].student_address.street_direction << " ";
		cout << students[i].student_address.city << " " << students[i].student_address.state << " "
			<< students[i].student_address.zip << endl;
	}
}
/*Student Name    ID Number       GPA     Classification  Account Balance         Address

John Smith      123456          3.40    J               $1750.40                302 Fairmont St NW Washington DC 20059
Frank Smitty    789105          2.70    F               $1940.70                302 Sixth St SW Washington DC 20059
Paul Dale       542312          3.40    S               $5623.10                636 Fourth St SW Washington DC 20231
Larry Allen     348798          2.60    S               $3600.70                589 Third St NW Washington DC 20059
Josephine Baker 455903          3.80    F               $2056.80                280 Sixth St SW Washington DC 20059
Press any key to continue . . .*/