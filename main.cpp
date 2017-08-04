#include <iostream>
#include <iomanip>
using namespace std;
float Get_user_input(); // prototype
float Convert_weight(float); // prototype
const float CONVERSION_RATE = 2.2;
int main()
{
	cout << fixed << showpoint;
	float lb_weight;
	float kg_weight;
	//calls a value-returning fuction to get lb_weight
	lb_weight = Get_user_input();
	//calls a value_returning function to convert lb_weight to kilograms
	kg_weight = Convert_weight(lb_weight);
	//Output both the weights rounded to two decimal places.
	cout << "The kilogram equivalent of " << setprecision(2) << lb_weight 
		<< " lbs is " << setprecision(2) << kg_weight << endl;
	system("pause");
	return 0;
}
//prompts the user to enter the weight of a person in pounds 
float Get_user_input()
{
	float lb_weight;
	cout << "Enter the weight of a person in pounds: ";
	cin >> lb_weight;
	return lb_weight;
}
//calculate the equivalent weight in kilograms
float Convert_weight(float lb_weight)
{
	return lb_weight / CONVERSION_RATE;
}
/*Enter the weight of a person in pounds: 56.6
The kilogram equivalent of 56.60 lbs is 25.73
*/