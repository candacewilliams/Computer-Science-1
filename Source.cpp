
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std; 

void heading(); // this is a prototype

int main()
{
	heading();
	string first_name;
	string last_name;
	char classification;
	int quality_points;
	int num_credits;
	float GPA;

	cout << setw(6) << "GPA Report" << endl;
	cout << setw(3) << "Name";
	cout << setw(5) << "Class";
	cout << setw(7) << "Credits";
	cout << setw(9) << "GPA";

	ifstream myfile;//Declare file input object 
	myfile.open("infile.txt");//Open file
	myfile >> first_name >> last_name >> classification >> quality_points >> num_credits;
	GPA = float(quality_points) / float(num_credits);
	cout << first_name << " " << last_name << '\t' << setw(2) << classification 
		<< setw(6) << quality_points << setw(9) << num_credits << setw(11) << setprecision(2) << GPA << endl;
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
	cout << "*****************************************" << endl;
}