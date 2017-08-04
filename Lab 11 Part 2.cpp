#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void heading(); //prototype function
float difference_of_temperatures(float current_temperature, float previous_temperature); //prototype function
float average_temperature(float temperature_sum); // prototype function
int main()
{
	float current_temperature;
	float previous_temperature;
	float temperature_sum = 0.0;

	heading();

	cout << "TEMP     DIFF" << endl;
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "  " << endl;

	ifstream myfile;
	myfile.open("infile.txt"); //Open file of temperatures 
	
	myfile >> current_temperature; // Get current temperature
	cout << current_temperature << endl; 
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	float temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl; 
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous

	myfile >> current_temperature; // Get current temperature
	cout << current_temperature;
	temperature_sum = temperature_sum + current_temperature; // adds current sum to sumation of all sums
	temperature_difference = difference_of_temperatures(current_temperature, previous_temperature); // calculates difference in current and previous temperatures
	cout << setw(8) << temperature_difference << endl;
	previous_temperature = current_temperature; // current temperature becomes previous
	

	cout << fixed << showpoint;
	float average_temp = average_temperature(temperature_sum);
	cout << "Average Temperature: " << setprecision(2) << average_temp << endl;
	
	return 0;
}

void heading()
{
	cout << "Candace Williams" << endl;
	cout << "@02823097" << endl;
	cout << "February 8, 2017" << endl;
	cout << "Lab 5" << endl;
	cout << "Problem: Compute the difference between temperatures and the average temperature" << endl;
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "  " << endl;
}

float difference_of_temperatures(float current_temperature, float previous_temperature)
{

	float temperature_difference;
	temperature_difference = current_temperature - previous_temperature;
	return temperature_difference;
}

float average_temperature(float temperature_sum)
{
	float average_temperature = temperature_sum / float(12);
	return average_temperature;
}
/*Candace Williams
@02823097
February 8, 2017
Lab 5
Problem: Compute the difference between temperatures and the average temperature



TEMP     DIFF



34.5
38.6     4.1
42.4     3.8
46.8     4.4
51.3     4.5
63.1    11.8
60.2    -2.9
55.9    -4.3
60.3     4.4
56.7    -3.6
50.3    -6.4
42.2    -8.1
Average Temperature: 50.19
Press any key to continue . . .
*/