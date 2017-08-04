
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void heading(); // this is a prototype

int main()
{
	heading();
	string first_name;   // (1) Declare variables
	string last_name;
	char classification;
	int quality_points;
	int num_credits;
	float GPA;
	

	ifstream myfile;//Declare file input object //(2) Declare file input object
	
	myfile.open("infile.txt");//Open file //(3) Open file
	cout << " " << endl;
	cout << setw(40) << "GPA Report" << endl; //(4) Print report heading
	cout << "  " << endl;
	cout << setw(7) << "Name";
	cout << setw(11) << "Class";
	cout << setw(16) << "Quality Points";
	cout << setw(14) << "Credits";
	cout << setw(14) << "GPA" << endl;;

	myfile >> first_name >> last_name >> classification >> quality_points >> num_credits; //(5) Read the data for first student from the file.
		
	GPA = float(quality_points) / float(num_credits); //(6) compute GPA
	cout << fixed << showpoint;
	cout << first_name << " " << last_name << setw(7) << classification //(7) Display first student data
		<< setw(10) << quality_points << setw(19) << num_credits << setw(18) << setprecision(2) << GPA << endl;

	myfile >> first_name >> last_name >> classification >> quality_points >> num_credits; //(8) Read the data for second student from the file.
		
	GPA = float(quality_points) / float(num_credits); //(9) compute GPA
	cout << fixed << showpoint;
	cout << first_name << " " << last_name << setw(6) << classification //(10) Display second student data
		<< setw(10) << quality_points << setw(19) << num_credits << setw(18) << setprecision(2) << GPA << endl;

	myfile >> first_name >> last_name >> classification >> quality_points >> num_credits; //(11) Read the data for third student from the file.
	GPA = float(quality_points) / float(num_credits); //(12) compute GPA
	cout << fixed << showpoint;
	cout << first_name << " " << last_name << setw(4) << classification
		<< setw(10) << quality_points << setw(19) << num_credits << setw(18) << setprecision(2) << GPA << endl; //(13) Display third student data
	cout << "**************************************************************" << endl;

	myfile.close();
	return 0;
}

void heading()
{
	cout << "Candace Williams" << endl;
	cout << "ID @02823097" << endl;
	cout << "SYCS-135 Computer Science I" << endl;
	cout << "Lab 4" << endl;
	cout << "February 2, 2017" << endl;
	cout << "**************************************************************" << endl;
}
 /* 
 Candace Williams
ID @02823097
SYCS-135 Computer Science I
Lab 4
February 2, 2017
**************************************************************

                              GPA Report

   Name      Class  Quality Points       Credits           GPA
Joe Smith      S        40                 12              3.33
Fred Davis     F        35                 14              2.50
June Freeman   J        40                 10              4.00
**************************************************************
Press any key to continue . . .
 */