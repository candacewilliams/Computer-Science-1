#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//prototype functions
void heading();
float compute_area(float, float);
float compute_cost_of_cutting(float);
void print_report_line(float, float, float, float, string);

int main()
{

//declare variables
	float lawn_width;
	float lawn_length;
	float area_of_lawn;
	float cost_of_cutting;
	float daily_total = 0.0;
	float total_width = 0.0;
	float total_length = 0.0;
	float total_area = 0.0;
	string address;
	char dummy;
	ifstream myfile; //open the file of lawn dimensions
	heading();
	cout << fixed << showpoint; 
	cout << setw(9) << "Address";
	cout << setw(16) << "Width";
	cout << setw(9) << "Length";
	cout << setw(7) << "Area";
	cout << setw(11) << "Cost" << endl;
	cout << " " << endl;

	myfile.open("infile.txt");
	getline(myfile, address); //read address, lawn width and lawn length from the file
	myfile >> lawn_width >> lawn_length;
	myfile.get(dummy);
	total_length = total_length + lawn_length; // add length to total length
	total_width = total_width + lawn_width;  // add width to total width
	area_of_lawn = compute_area(lawn_width, lawn_length); // compute the area of the lawn
	total_area = total_area + area_of_lawn; // add area to total area
	cost_of_cutting = compute_cost_of_cutting(area_of_lawn);
	daily_total = daily_total + cost_of_cutting; // add charge to daily total
	print_report_line(lawn_length, lawn_width, area_of_lawn, cost_of_cutting, address);

	getline(myfile, address);
	myfile >> lawn_width >> lawn_length; // read address, lawn width and lawn length from the file
	myfile.get(dummy);
	total_length = total_length + lawn_length; //  add length to total length
	total_width = total_width + lawn_width; // add width to total width
	area_of_lawn = compute_area(lawn_width, lawn_length); // compute the area of the lawn
	total_area = total_area + area_of_lawn; // add area to total area
	cost_of_cutting = compute_cost_of_cutting(area_of_lawn);
	daily_total = daily_total + cost_of_cutting; // add charge to daily total
	print_report_line(lawn_length, lawn_width, area_of_lawn, cost_of_cutting, address);

	getline(myfile, address);
	myfile >> lawn_width >> lawn_length; // read address, lawn width and lawn length from the file
	myfile.get(dummy);
	total_length = total_length + lawn_length; // add length to total length
	total_width = total_width + lawn_width;  // add width to total width
	area_of_lawn = compute_area(lawn_width, lawn_length); // compute the area of the lawn
	total_area = total_area + area_of_lawn; // add area to total area
	cost_of_cutting = compute_cost_of_cutting(area_of_lawn);
	daily_total = daily_total + cost_of_cutting; // add charge to daily total
	print_report_line(lawn_length, lawn_width, area_of_lawn, cost_of_cutting, address);

	cout << " " << endl;
	cout << "Daily Total -- $" << daily_total << endl; //display the total amount of money they have earned for the day
	cout << "Average_Length -- " << total_length / float(3) << endl; //compute and display the average length
	cout << "Average Width -- " << total_width / float(3) << endl;// compute and display to average width
	cout << "Average Area -- " << total_area / float(3) << endl; //compute and display the average area

	return 0;
}

void heading()
{
	cout << "*********************************" << endl;
	cout << "Candace Williams" << endl;
	cout << "ID @02823097" << endl;
	cout << "SYCS-135 Computer Science I" << endl;
	cout << "Lab 6 Problem 1" << endl;
	cout << "February 16, 2017" << endl;
	cout << "Program to print lawn cutting results" << endl;
	cout << "*********************************" << endl;
	cout << "  " << endl;
	cout << "*******Daily Lawn Cutting Report**************" << endl;
}

//Compute the amount to charge the client ({0}.05 X AREA)

float compute_area(float lawn_width, float lawn_length)
{
	float area_of_lawn;
	area_of_lawn = lawn_width * lawn_length;
	return area_of_lawn;
}

float compute_cost_of_cutting(float area_of_lawn)
{
	float cost_of_cutting;
	cost_of_cutting = float(0.05) * area_of_lawn;
	return cost_of_cutting;
}
//display the client address, the lawn dimensions, the lawn area and the amount to charge
void print_report_line(float lawn_length, float lawn_width, float area_of_lawn, float cost_of_cutting, string address)
{
		cout << setw(20) << left << address << setw(8) << setprecision(2) << lawn_width 
		<< setw(8) << setprecision(2) << setw(8) << setprecision(2)
		<< lawn_length << setw(10) << setprecision(2) << area_of_lawn 
		<< "$" << setprecision(2) << cost_of_cutting << endl;
}
/**********************************
Candace Williams
ID @02823097
SYCS-135 Computer Science I
Lab 6
February 16, 2017
Program to print lawn cutting results
*********************************

*******Daily Lawn Cutting Report**************
  Address           Width   Length   Area       Cost

123 Main St         55.60   67.00   3725.20   $186.26
67 Georgia Ave      30.00   40.00   1200.00   $60.00
1234 14th St        79.20   24.50   1940.40   $97.02

Daily Total -- $343.28
Average_Length -- 43.83
Average Width -- 54.93
Average Area -- 2288.53
Press any key to continue . . .*/