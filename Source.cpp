#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//prototype functions
void heading();
float Compute_Gross_Pay(float, float, char);
float Compute_Taxes(float);
float Compute_Net_Pay(float, float);
void Print_Pay_Check(float, float, float, float, string, string, string ,string, string, string, string, string , string, string);
float Compute_Federal_Tax(float);
float Compute_State_Tax(float);
float Compute_City_Tax(float);
int main()
{
	heading();
	const string DATE = "2/23/2017";
	string lastName;
	string firstName;
	float deductions;
	string ID;
	string addressNum;
	string addressMiddle;
	string addressEnd;
	string city;
	string state;
	string zip;
	float payRate;
	char parttime_fulltime;
	float grossPay;
	float totalTax;
	float netPay;
	ifstream myfile;
	myfile.open("infile.txt"); //access file
	myfile >> lastName >> firstName >> deductions >> ID >> addressNum 
		>> addressMiddle >> addressEnd >> city >> state >> zip >> payRate >> parttime_fulltime;
	grossPay = Compute_Gross_Pay(deductions, payRate, parttime_fulltime);
	totalTax = Compute_Taxes(grossPay);
	netPay = Compute_Net_Pay(grossPay, totalTax);
	Print_Pay_Check(grossPay, netPay, totalTax, deductions, DATE, lastName, firstName, ID, addressNum, addressMiddle, addressEnd, city, state, zip);
	myfile >> lastName >> firstName >> deductions >> ID >> addressNum
		>> addressMiddle >> addressEnd >> city >> state >> zip >> payRate >> parttime_fulltime;
	grossPay = Compute_Gross_Pay(deductions, payRate, parttime_fulltime);
	totalTax = Compute_Taxes(grossPay);
	netPay = Compute_Net_Pay(grossPay, totalTax);
	Print_Pay_Check(grossPay, netPay, totalTax, deductions, DATE, lastName, firstName, ID, addressNum, addressMiddle, addressEnd, city, state, zip);
	myfile >> lastName >> firstName >> deductions >> ID >> addressNum
		>> addressMiddle >> addressEnd >> city >> state >> zip >> payRate >> parttime_fulltime;
	grossPay = Compute_Gross_Pay(deductions, payRate, parttime_fulltime);
	totalTax = Compute_Taxes(grossPay);
	netPay = Compute_Net_Pay(grossPay, totalTax);
	Print_Pay_Check(grossPay, netPay, totalTax, deductions, DATE, lastName, firstName, ID, addressNum, addressMiddle, addressEnd, city, state, zip);
	myfile >> lastName >> firstName >> deductions >> ID >> addressNum
		>> addressMiddle >> addressEnd >> city >> state >> zip >> payRate >> parttime_fulltime;
	grossPay = Compute_Gross_Pay(deductions, payRate, parttime_fulltime);
	totalTax = Compute_Taxes(grossPay);
	netPay = Compute_Net_Pay(grossPay, totalTax);
	Print_Pay_Check(grossPay, netPay, totalTax, deductions, DATE, lastName, firstName, ID, addressNum, addressMiddle, addressEnd, city, state, zip);

	myfile >> lastName >> firstName >> deductions >> ID >> addressNum
		>> addressMiddle >> addressEnd >> city >> state >> zip >> payRate >> parttime_fulltime;
	grossPay = Compute_Gross_Pay(deductions, payRate, parttime_fulltime);
	totalTax = Compute_Taxes(grossPay);
	netPay = Compute_Net_Pay(grossPay, totalTax);
	Print_Pay_Check(grossPay, netPay, totalTax, deductions, DATE, lastName, firstName, ID, addressNum, addressMiddle, addressEnd, city, state, zip);

	myfile >> lastName >> firstName >> deductions >> ID >> addressNum
		>> addressMiddle >> addressEnd >> city >> state >> zip >> payRate >> parttime_fulltime;
	grossPay = Compute_Gross_Pay(deductions, payRate, parttime_fulltime);
	totalTax = Compute_Taxes(grossPay);
	netPay = Compute_Net_Pay(grossPay, totalTax);
	Print_Pay_Check(grossPay, netPay, totalTax, deductions, DATE, lastName, firstName, ID, addressNum, addressMiddle, addressEnd, city, state, zip);
	return 0;
}
//computes gross pay
float Compute_Gross_Pay(float deductions, float payRate, char parttime_fulltime)
{
	float grossPay;
	grossPay = 40 * payRate;
	if (parttime_fulltime == 'P')
		grossPay = grossPay + (10.50 * deductions);
	return grossPay;
}
void heading()
{
	cout << "*****************************************************************" << endl;
	cout << "Candace Williams" << endl;
	cout << "@02823097" << endl;
	cout << "February 23, 2017" << endl;
	cout << "Midterm Exam" << endl;
	cout << "*****************************************************************" << endl;
}
//computes total taxes
float Compute_Taxes(float grossPay)
{
	float fedTax;
	float stateTax;
	float cityTax;
	float totalTax;

	fedTax = Compute_Federal_Tax(grossPay);
	stateTax = Compute_State_Tax(fedTax);
	cityTax = Compute_City_Tax(stateTax);
	totalTax = fedTax + cityTax + cityTax;
	return totalTax;
}
//computes federal tax
float Compute_Federal_Tax(float grossPay)
{
	float fedTax;
	if (grossPay <= 200)
		fedTax =  grossPay * .15;
	if (grossPay > 200 && grossPay <= 500)
		fedTax = grossPay * .25;
	if (grossPay > 500)
		fedTax = grossPay * .35;
	return fedTax;
}
//computes state tax
float Compute_State_Tax(float fedTax)
{
	int stateTax;
	if (fedTax < 80)
		stateTax = 0.0;
	else
		stateTax = fedTax * .10;
	return stateTax;
}
//computes city tax
float Compute_City_Tax(float stateTax)
{
	float cityTax;
	if (stateTax < 50)
		cityTax = 0.0;
	else
		cityTax = stateTax *.08;
	return cityTax;
}
//computes net pay
float Compute_Net_Pay(float grossPay, float totalTax)
{
	float netPay;
	netPay = grossPay -  totalTax;
	return netPay;
}
//prints pay check information
void Print_Pay_Check(float grossPay, float netPay, float totalTax, float deductions, string DATE, string lastName, string firstName,string ID, string addressNum, string addressMiddle, string addressEnd, string city, string state, string zip)
{
	cout << fixed << showpoint;
	cout << "*****************************************************************" << endl << endl;
	cout << "ABC Flower" << setw(49) << DATE << endl;
	cout << "123 Georgia Ave" << endl;
	cout << "Washington, DC 200059" << endl;
	cout << "Payable to: " << setw(4) << lastName << " " << firstName
		<< "          Pay this amount: $ " << setprecision(2) << netPay << endl;
	cout << setw(6) << addressNum << " " << addressMiddle << endl;
	cout << setw(6) << addressEnd;
	cout << setw(6) << city << setw(2) << zip << endl << endl;
	cout << "Gross Pay   $" << setprecision(2) << grossPay << endl;
	cout << "Total Taxes   $" << setprecision(2) << totalTax << endl;
}
/******************************************************************
Candace Williams
@02823097
February 23, 2017
Midterm Exam
*****************************************************************
*****************************************************************

ABC Flower                                        2/23/2017
123 Georgia Ave
Washington, DC 200059
Payable to: Herold, Will          Pay this amount: $ 170.10
   123 Main
   St.Washington,20019

Gross Pay   $226.80
Total Taxes   $56.70
*****************************************************************

ABC Flower                                        2/23/2017
123 Georgia Ave
Washington, DC 200059
Payable to: Jackson, Stan          Pay this amount: $ 331.50
    12 Douglas
  Ave.Baltimore,30229

Gross Pay   $442.00
Total Taxes   $110.50
*****************************************************************

ABC Flower                                        2/23/2017
123 Georgia Ave
Washington, DC 200059
Payable to: Jerry, Francis          Pay this amount: $ 631.47
  2345 6th
StreetWoodbridge,44040

Gross Pay   $971.50
Total Taxes   $340.02
*****************************************************************

ABC Flower                                        2/23/2017
123 Georgia Ave
Washington, DC 200059
Payable to: John, Wilson          Pay this amount: $ 312.00
    12 Georgia
  Ave.Washington,20019

Gross Pay   $416.00
Total Taxes   $104.00
*****************************************************************

ABC Flower                                        2/23/2017
123 Georgia Ave
Washington, DC 200059
Payable to: Smith, Stanley          Pay this amount: $ 358.15
    56 D
StreetBaltimore,30229

Gross Pay   $551.00
Total Taxes   $192.85
*****************************************************************

ABC Flower                                        2/23/2017
123 Georgia Ave
Washington, DC 200059
Payable to: Jeffers, Claude          Pay this amount: $ 1083.50
    66 32nd
StreetWoodbridge,44040

Gross Pay   $1681.20
Total Taxes   $597.70
Press any key to continue . . .*/
