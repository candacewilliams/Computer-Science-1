#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void heading(); //prototype function
float celsius_to_farenheit(int); //prototype function

int main()
{
	int celsius;
	float converted_temperature;

	heading();

	ifstream myfile;
	myfile.open("infile.txt"); //Open file of temperatures 

	myfile >> celsius; //Get temperature reading from file 
	converted_temperature = celsius_to_farenheit(celsius); //Compute the Degrees of Celsius into Fahrenheit(F = (C x 9) / 5 + 32)
	cout << fixed << showpoint;
	cout << celsius << " Degrees C = " << setprecision(2) << converted_temperature << " Degrees F" << endl; //Output the conversion to the user in this format, e.g. 20 Degrees C = 68 Degrees F
	
	myfile >> celsius; //Get temperature reading from file 
	converted_temperature = celsius_to_farenheit(celsius); //Compute the Degrees of Celsius into Fahrenheit(F = (C x 9) / 5 + 32)
	cout << fixed << showpoint;
	cout << celsius << " Degrees C = " << setprecision(2) << converted_temperature << " Degrees F" << endl; //Output the conversion to the user in this format, e.g. 20 Degrees C = 68 Degrees F

	myfile >> celsius; //Get temperature reading from file 
	converted_temperature = celsius_to_farenheit(celsius); //Compute the Degrees of Celsius into Fahrenheit(F = (C x 9) / 5 + 32)
	cout << fixed << showpoint;
	cout << celsius << " Degrees C = " << setprecision(2) << converted_temperature << " Degrees F" << endl; //Output the conversion to the user in this format, e.g. 20 Degrees C = 68 Degrees F

	myfile >> celsius; //Get temperature reading from file 
	converted_temperature = celsius_to_farenheit(celsius); //Compute the Degrees of Celsius into Fahrenheit(F = (C x 9) / 5 + 32)
	cout << fixed << showpoint;
	cout << celsius << " Degrees C = " << setprecision(2) << converted_temperature << " Degrees F" << endl; //Output the conversion to the user in this format, e.g. 20 Degrees C = 68 Degrees F
	
	myfile >> celsius; //Get temperature reading from file 
	converted_temperature = celsius_to_farenheit(celsius); //Compute the Degrees of Celsius into Fahrenheit(F = (C x 9) / 5 + 32)
	cout << fixed << showpoint;
	cout << celsius << " Degrees C = " << setprecision(2) << converted_temperature << " Degrees F" << endl; //Output the conversion to the user in this format, e.g. 20 Degrees C = 68 Degrees F
	
	myfile.close(); // Close the temperature file
	return 0;
}

void heading()
{
	cout << "******************************" << endl;
	cout << "Candace Williams" << endl;
	cout << "@02823097" << endl;
	cout << "February 8, 2017" << endl;
	cout << "Lab 5" << endl;
	cout << "Calculate Farenheit Temperatures" << endl;
	cout << "******************************" << endl;
}

float celsius_to_farenheit(int celsius)
{
	float farenheit;
	farenheit = float (celsius * 9) / 5 + 32;
	return farenheit;

}

/*
******************************
Candace Williams
@02823097
February 8, 2017
Lab 5
Calculate Farenheit Temperatures
******************************
24 Degrees C = 75.20 Degrees F
78 Degrees C = 172.40 Degrees F
34 Degrees C = 93.20 Degrees F
29 Degrees C = 84.20 Degrees F
0 Degrees C = 32.00 Degrees F
Press any key to continue . . .*/