#include <iostream>
#include< iomanip>
#include <fstream>
#include <string>
using namespace std;
//prototype functions
void heading();
float compute_service_charge(char, float, float);
float compute_interest(char, float, float);
void print_report(char, int, float);
int main()
{
	char acct_type;
	float acct_balance;
	float acct_minimum_balance;
	int acct_no;
	heading();
	ifstream myfile;
	myfile.open("infile.txt"); //opens file
	cout << fixed << showpoint;
	//reads account number, account type , minimum balance & current balance
	myfile >> acct_no >> acct_type >> acct_minimum_balance >> acct_balance;
	//updates account balance with the interest
	acct_balance = compute_interest(acct_type, acct_minimum_balance, acct_balance); 
	//updates account balace with the service charge
	acct_balance = compute_service_charge(acct_type, acct_minimum_balance, acct_balance);
	//displays account type, number, and balance
	print_report(acct_type, acct_no, acct_balance);
	myfile >> acct_no >> acct_type >> acct_minimum_balance >> acct_balance;
	acct_balance = compute_interest(acct_type, acct_minimum_balance, acct_balance);
	acct_balance = compute_service_charge(acct_type, acct_minimum_balance, acct_balance);
	print_report(acct_type, acct_no, acct_balance);
	myfile >> acct_no >> acct_type >> acct_minimum_balance >> acct_balance;
	acct_balance = compute_interest(acct_type, acct_minimum_balance, acct_balance);
	acct_balance = compute_service_charge(acct_type, acct_minimum_balance, acct_balance);
	print_report(acct_type, acct_no, acct_balance);
	myfile >> acct_no >> acct_type >> acct_minimum_balance >> acct_balance;
	acct_balance = compute_interest(acct_type, acct_minimum_balance, acct_balance);
	acct_balance = compute_service_charge(acct_type, acct_minimum_balance, acct_balance);
	print_report(acct_type, acct_no, acct_balance);
	myfile >> acct_no >> acct_type >> acct_minimum_balance >> acct_balance;
	acct_balance = compute_interest(acct_type, acct_minimum_balance, acct_balance);
	acct_balance = compute_service_charge(acct_type, acct_minimum_balance, acct_balance);
	print_report(acct_type, acct_no, acct_balance);
	return 0;
}
//displays student information
void heading()
{
	cout << "*************************************" << endl;
	cout << "Candace Williams" << endl;
	cout << "ID @02823097" << endl;
	cout << "SYCS-135 Computer Science I" << endl;
	cout << "Lab 6 Problem 2" << endl;
	cout << "February 16, 2017" << endl;
	cout << "*************************************" << endl;
}
// checks a customer's balance to determine interest
float compute_interest(char acct_type, float acct_minimum_balance, float acct_balance)
{
	float interest;
	if (acct_type == 'S' && (acct_balance >= acct_minimum_balance))
		interest = acct_balance + (acct_balance * 0.04);
	else if ((acct_type == 'C') && ((acct_balance >= acct_minimum_balance) && (acct_balance <= (acct_minimum_balance + 5000))))
		interest = acct_balance + (acct_balance * 0.03);
	else if ((acct_type == 'C') && (acct_balance > acct_minimum_balance + 5000))
		interest = acct_balance + (acct_balance * 0.05);
	else
		interest = acct_balance;
	return interest;
}
//determines service charge for account if account balance is less than the minimum balance
float compute_service_charge(char acct_type, float acct_minimum_balance, float acct_balance)
{
	float service_charge;
	if ((acct_type == 'S') && (acct_balance < acct_minimum_balance))
		service_charge = acct_balance - 10.00;
	else if ((acct_type == 'C') && (acct_balance < acct_minimum_balance))
		service_charge = acct_balance - 25.00;
	else
		service_charge = acct_balance;
	return service_charge;
}
//displays account number, account type, and current balance
void print_report(char acct_type, int acct_no, float acct_balance)
{
	cout << fixed << showpoint;
	cout << "*************************************" << endl;
	cout << "Account Number: " << acct_no << endl;
	cout << "Account Type: " << acct_type << endl;
	cout << "Account Balance: " << setprecision(2) << acct_balance << endl;
}
/**************************************
Candace Williams
ID @02823097
SYCS-135 Computer Science I
Lab 6 Problem 2
February 16, 2017
*************************************
*************************************
Account Number: 46728
Account Type: S
Account Balance: 2808.00
*************************************
Account Number: 87324
Account Type: C
Account Balance: 8073.45
*************************************
Account Number: 79873
Account Type: S
Account Balance: 790.00
*************************************
Account Number: 89832
Account Type: C
Account Balance: 3090.00
*************************************
Account Number: 98322
Account Type: C
Account Balance: 725.00
Press any key to continue . . .*/