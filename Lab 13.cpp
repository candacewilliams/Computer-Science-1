#include <iostream>
#include <iomanip>
using namespace std;
//prototype functions
void GetData(int&, int&);
void PrintData(int&, int&);
int main()
{
	//variable declarations
	int miles;
	int hours;
	GetData(miles, hours);
	PrintData(miles, hours);
	return 0;
}
//takes user input values for miles and hours
void GetData(int& miles, int&hours)
{
	cout << "Enter the Number of Miles: ";
	cin >> miles;
	cout << "Enter the Number of Hours: ";
	cin >> hours;
}
//prints miles, hours, and miles per hour
void PrintData(int& miles, int&hours)
{
	cout << fixed << showpoint;
	float miles_per_hour;
	//calculates miles per hour
	miles_per_hour = float(miles) / float(hours);
	//prints miles, hours, and miles per hour
	cout << "The Number of miles is: " << miles << endl;
	cout << "The Number of Hours is: " << hours << endl;
	cout << "The Number of Miles Per Hour is: " << setprecision(2) << miles_per_hour << endl;
}
/*Enter the Number of Miles: 12340
Enter the Number of Hours: 460
The Number of miles is: 12340
The Number of Hours is: 460
The Number of Miles Per Hour is: 26.83
Press any key to continue . . .*/