#include "stdafx.h"
// Program Numbers sends numbers to the output stream in // specified formats. 
#include <iostream> 
#include <iomanip>
using namespace std;

int num1;
int num2;
int num3;
int num4;
int num5;
float sum;

void heading()
{
	cout << "*****************************************" << endl;
	cout << "Candace Williams" << endl;
	cout << "@02823097" << endl;
	cout << "January 26, 2017" << endl;
	cout << "Lab 4, Problem 4" << endl;
	cout << "This program simply outputs a heading for my output" << endl;
	cout << "*****************************************" << endl;
}

float divide_sum(int, int, int, int, int)
{
	sum = (float(num1 + num2) / float(num3 + num4 + num5));
	return sum;

}

void display_answer(float)
{
	cout << setprecision(4) << sum << endl;
}



int main()
{
	heading();

	cout << "Enter 5 numbers: " << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	cout << fixed << showpoint;
	cout << setw(2) << num1;
	cout << setw(5) << num2;
	cout << setw(5) << num3;
	cout << setw(4) << num4;
	cout << setw(5) << num5 << endl;

	divide_sum(num1, num2, num3, num4, num5);
	display_answer(sum);
	return sum;
}
/******************************************
Candace Williams
@02823097
January 26, 2017
Lab 4, Problem 4
This program simply outputs a heading for my output
*****************************************
Enter 5 numbers:
1
2
3
4
5
 1    2    3   4    5
0.2500
Press any key to continue . . .*/
