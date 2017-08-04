// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include "stdafx.h"
#include <iostream>                        // include input/output library code
#include <string>                          // include string manipulate library code
#include <iomanip>
using namespace std;                       // allows all of the names in a namespace 
										   // to be accessed without the namespace 
										   // identifier as a qualifier

void heading()
{
	cout << "*****************************************" << endl;
	cout << "Candace Williams" << endl;
	cout << "ID @02823097" << endl;
	cout << "SYCS-135 Computer Science I" << endl;
	cout << "Lab 4" << endl;
	cout << "February 2, 2017" << endl;
	cout << "*****************************************" << endl;
}

int main() //calculates mileage reimbursement
{
	float beginning_reading;
	float end_reading;
	const float reimbursement_rate = float(.35);
	float total_miles;
	float reimbursement_amount;

	heading();
	cout << "  " << endl;
	cout << "MILEAGE REIMBURSEMENT CALCULATOR" << endl; // 1) prompt user input
	cout << "  " << endl;
	cout << "Enter beginning odometer reading => "; //2) get user input
	cin >> beginning_reading;
	cout << "  " << endl;
	cout << "Enter ending odometer reading => "; //2) get user input
	cin >> end_reading;
	total_miles = float(end_reading) - float(beginning_reading); //3) subtract ending input from beginning input
	reimbursement_amount = total_miles * reimbursement_rate; //4) multiply difference by .35
	cout << "  " << endl;
	cout << fixed << showpoint;
	cout << "You traveled " << setprecision(2) << total_miles << " miles.";
	cout << " At $" << reimbursement_rate << " per mile, your reimbursement is $" << setprecision(2) << reimbursement_amount << "." << endl; //5) output data
	cout << "  " << endl;
	return 0; 
}
/******************************************
Candace Williams
ID @02823097
SYCS-135 Computer Science I
Lab 4
February 2, 2017
*****************************************

MILEAGE REIMBURSEMENT CALCULATOR

Enter beginning odometer reading => 55044

Enter ending odometer reading => 55178

You traveled 134.00 miles. At $0.35 per mile, your reimbursement is $46.90.

Press any key to continue . . .
*/
