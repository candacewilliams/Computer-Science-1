#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void heading(); //prototype function
float find_class_average(float); //prototpye function

int main()
{
	float grade_1;
	float grade_2;
	float grade_3;
	float grade_4;
	float sum;
	float average;
	float angela_sum = 0.0;
	float langston_sum = 0.0;
	float maya_sum = 0.0;
	float malcolm_sum = 0.0;
	float angela_average;
	float langston_average;
	float maya_average;
	float malcolm_average;

	heading();

	ifstream myfile;
	myfile.open("infile.txt"); //open the file

	cout << fixed << showpoint;
	cout << setw(17) << "Angela" << setw(10) << "Langston" 
		<< setw(5) << "Maya" << setw(9) << "Malcolm" 
		<< setw(15) << "Class Total" << setw(15) << "Class Average" << endl;
	cout << " " << endl;

	myfile >> grade_1 >> grade_2 >> grade_3 >> grade_4;
	sum = float(grade_1) + float(grade_2) + float(grade_3) + float(grade_4); //add to class total
	average = find_class_average(sum);
	angela_sum = angela_sum + grade_1; //adds a grade to student's total
	langston_sum = langston_sum + grade_2;//adds a grade to student's total
	maya_sum = maya_sum + grade_3; //adds a grade to student's total
	malcolm_sum = malcolm_sum + grade_4; //adds a grade to student's total
	cout << "Algebra " << setw(8) << setprecision(1) << grade_1 << setw(8) << setprecision(1) << grade_2 
		<< setw(8) << setprecision(1) << grade_3 << setw(8) << setprecision(1) << grade_4 
		<< setw(13) << setprecision(1) << sum
		<< setw(13) << setprecision(1) << average << endl;
	
	myfile >> grade_1 >> grade_2 >> grade_3 >> grade_4;
	sum = float(grade_1) + float(grade_2) + float(grade_3) + float(grade_4); //add to class total
	angela_sum = angela_sum + grade_1; //adds a grade to student's total
	langston_sum = langston_sum + grade_2;//adds a grade to student's total
	maya_sum = maya_sum + grade_3; //adds a grade to student's total
	malcolm_sum = malcolm_sum + grade_4;//adds a grade to student's total
	average = find_class_average(sum);
	cout << "CS 1 " << setw(11) << setprecision(1) << grade_1 << setw(8) << setprecision(1) << grade_2
		<< setw(8) << setprecision(1) << grade_3 << setw(8) << setprecision(1) << grade_4 
		<< setw(13) << setprecision(1) << sum
		<< setw(13) << setprecision(1) << average << endl;

	myfile >> grade_1 >> grade_2 >> grade_3 >> grade_4;
	sum = float(grade_1) + float(grade_2) + float(grade_3) + float(grade_4); //add to class total
	average = find_class_average(sum);
	angela_sum = angela_sum + grade_1;//adds a grade to student's total
	langston_sum = langston_sum + grade_2;//adds a grade to student's total
	maya_sum = maya_sum + grade_3;//adds a grade to student's total
	malcolm_sum = malcolm_sum + grade_4;//adds a grade to student's total
	cout << "English " << setw(8) << setprecision(1) << grade_1 << setw(8) << setprecision(1) << grade_2
		<< setw(8) << setprecision(1) << grade_3 << setw(8) << setprecision(1) << grade_4 
		<< setw(13) << setprecision(1) << sum
		<< setw(13) << setprecision(1) << average << endl;

	myfile >> grade_1 >> grade_2 >> grade_3 >> grade_4;
	sum = float(grade_1) + float(grade_2) + float(grade_3) + float(grade_4); //add to class total
	angela_sum = angela_sum + grade_1;//adds a grade to student's total
	langston_sum = langston_sum + grade_2;//adds a grade to student's total
	maya_sum = maya_sum + grade_3;//adds a grade to student's total
	malcolm_sum = malcolm_sum + grade_4;//adds a grade to student's total
	average = find_class_average(sum);
	cout << "Science " << setw(8) << setprecision(1) << grade_1 << setw(8) << setprecision(1) << grade_2
		<< setw(8) << setprecision(1) << grade_3 << setw(8) << setprecision(1) << grade_4 
		<< setw(13) << setprecision(1) << sum
		<< setw(13) << setprecision(1) << average << endl;
	cout << " " << endl;

	angela_average = find_class_average(angela_sum);
	langston_average = find_class_average(langston_sum);
	maya_average = find_class_average(maya_sum);
	malcolm_average = find_class_average(malcolm_sum);

	cout << "Average" << setw(9) << setprecision(1) << angela_average //prints student averages
		<< setw(8) << setprecision(1) << langston_average
		<< setw(8) << setprecision(1) << maya_average
		<< setw(8) << setprecision(1) << malcolm_average << endl;
	cout << " " << endl;
	return 0;
}

void heading() //displays prompt for date and headers
{
	int month;
	int day;
	int year;
	char back_slash = '/';

	cout << "What is today's date?: "; // prompt the user for today's date
	cin >> month >> back_slash >> day >> back_slash >> year;
	cout << " " << endl;
	cout << "DATE " << month << back_slash << day << back_slash << year
		 << "************************************************** Page 1" << endl;
	cout << " " << endl;
	cout << "********************* SMALL COLLEGE GRADE REPORT **********************" << endl;
	cout << " " << endl;
}


float find_class_average(float sum) //calculates average for the class
{
		float class_average;
		
		class_average = sum / float(4);
		return class_average; 
}
/*What is today's date?: 2/11/2017

DATE 2/11/2017************************************************** Page 1

********************* SMALL COLLEGE GRADE REPORT **********************

           Angela  Langston Maya  Malcolm    Class Total  Class Average

Algebra     64.5    56.7    67.4    90.0        278.6         69.7
CS 1        88.6    77.0    55.3    89.4        310.3         77.6
English     91.3    67.4    89.0   100.0        347.7         86.9
Science    100.0    89.4    80.2    91.4        361.0         90.2

Average     86.1    72.6    73.0    92.7

Press any key to continue . . .*/