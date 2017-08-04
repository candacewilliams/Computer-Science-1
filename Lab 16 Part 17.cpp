#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//prototype function
int pennies_to_dollars(int);
int pennies_to_cents(int);
int main()
{
	int num_pennies;
	int total;
	int num_cents;
	int num_dollars;
	//prompts the user to enter a number of cents
	cout << "Enter number of cents" << endl;
	cin >> num_pennies;
	num_dollars = pennies_to_dollars(num_pennies);
	num_cents = pennies_to_cents(num_pennies);
	cout << fixed << showpoint << "You have this much money: $" << num_dollars << "." << setprecision(2) << num_cents << endl;
	return 0;
}
//convert to dollars
int pennies_to_dollars(int num_pennies)
{
	int num_dollars;
	num_dollars = (num_pennies / 100);
	return num_dollars;
}
//converts pennies to cents
int pennies_to_cents(int num_pennies)
{
	int num_cents;
	num_cents = num_pennies % 100;
	return num_cents;
}
/*Enter number of cents
199
You have this much money: $1.99
Press any key to continue . . .
*/
/*Enter number of cents
99
You have this much money: $0.99
Press any key to continue . . .
*/