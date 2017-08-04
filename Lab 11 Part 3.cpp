#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float Find_Mean_Off(int, int, int, int); //prototype function
float Stand_Deviation_Formula(int, int, int, int, float); //prototype function

int main()
{
	int num1;
	int num2;
	int num3;
	int num4; 
	float average;
	float standard_deviation;

	cout << "Enter four integers" << endl; // prompts user to input 4 integers
	cin >> num1 >> num2 >> num3 >> num4;
	average = Find_Mean_Off(num1, num2, num3, num4);
	standard_deviation = Stand_Deviation_Formula(num1, num2, num3, num4, average);
	cout << "The mean for " << num1 << "," << num2 << "," << num3 
		<< ",and " << num4 << " is " << average << endl; // outputs average
	cout << "The Standard Deviation is " << standard_deviation << endl; //outputs Standard Deviation
	return 0;
}

//find the mean (the average) of all the integers that the user inputs.
float Find_Mean_Off(int num1, int num2, int num3, int num4) 
{
	float average;
	average = float(num1 + num2 + num3 + num4) / float(4);
	return average; //the mean to be used in the standard deviation finding function.
}
//calculates standard deviation
float Stand_Deviation_Formula(int num1, int num2, int num3, int num4, float average) //
{
	float standard_deviation;
	standard_deviation = sqrt((pow(num1 - average, 2) + pow (num2 - average, 2) + pow(num3 - average, 2) + pow(num4 - average, 2) / 3)); 
	return standard_deviation;
}
/*Enter four integers
3 6 7 10
The mean for 3,6,7,and 10 is 6.5
The Standard Deviation is 4.10284
Press any key to continue . . .*/