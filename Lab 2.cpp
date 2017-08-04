// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double interest_rate;
int num_years;
double loan_amount;
int months;

double calculate_monthly_payment(double, int, double)
{
	double monthly_payment = loan_amount * ((double(interest_rate)) * (pow(1 + interest_rate, months)) / (pow(1 + interest_rate, months) - 1));
	cout << "Your Monthly Payment is " << monthly_payment << endl;
	return monthly_payment;
}

int main()
{
	cout << "Enter Interest Rate" << endl;;
	cin >> interest_rate;
	interest_rate = interest_rate / 12;
	cout << "Enter Number of Years" << endl;
	cin >> num_years;
	months = num_years * 12;
	cout << "Enter Loan Amount" << endl;
	cin >> loan_amount;
	calculate_monthly_payment(interest_rate, months, loan_amount);

    return 0;
}

/*Enter Interest Rate
0.05
Enter Number of Years
7
Enter Loan Amount
50000
Your Monthly Payment is 706.695
Press any key to continue . . .*/

