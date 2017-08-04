#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//prototype functions
void get_store_data(ifstream&, string[], float[][5]);
float compute_store_total(int, float[][5]);
void display_store_data(string[], float[][5], float[]);
int main()
{
	//variable declarations
	string name[7];
	float sales[7][5];
	float total_sales[7];
	ifstream myfile;
	myfile.open("infile.txt");
	//function call to get data from file
	get_store_data(myfile, name, sales);
	//loops through the row to add the columns
	for (int row = 0; row < 7; row++)
	{
		//sets the sum of the columns to an index in total_sales
		total_sales[row] = compute_store_total(row, sales);
	}
	//function call to display data
	display_store_data(name, sales, total_sales);
	return 0;
}
//stores data in sales array
void get_store_data(ifstream& myfile, string name[], float sales[][5])
{
	//gets name of the store and stores it in the name array
	for (int row = 0; row < 7; row++)
	{
		myfile >> name[row];
		//gets the monthly sales and stores it in the sales array
		for (int col = 0; col < 5; col++)
		{
			myfile >> sales[row][col];
		}
	}
}
//calculates sum for every monthly sales for each store
float compute_store_total(int row, float sales[][5])
{
	float total = 0.0;
	//gets the sales value for a row
	for (int col = 0; col < 5; col++)
	{
		//adds sale value to the total for one store
		total = total + sales[row][col];
	}
	return total;
}
//displays data for all the stores 
void display_store_data(string name[], float sales[][5], float total_sales[])
{
	//displays heading
	cout << "Store Name" << '\t' << "Jan" << '\t' << "Feb" << '\t' << "Mar" << '\t' << "Apr" << '\t' << "May" << '\t' << "Total" << endl << endl;
	//gets the store (also set the row)
	for (int row_index = 0; row_index < 7; row_index++)
	{
		cout << fixed << showpoint;
		//prints the name of the store
		cout << name[row_index];
		//gets the monthly sales
		for (int col_index = 0; col_index < 5; col_index++)
		{
			//prints the monthly sales and sets it to two decimal places
			cout << '\t' << setprecision(2) << sales[row_index][col_index];
		}
		//prints the total sales for a store and sets it to two decimal places
		cout << '\t' << setprecision(2) << total_sales[row_index] << endl;
	}
}
/*Store Name      Jan     Feb     Mar     Apr     May     Total

Takoma_store    2.70    71.30   14.70   23.90   51.20   163.80
Bethesda_store  12.70   8.90    17.80   7.80    18.30   65.50
Baltimore_store 123.50  134.80  564.60  451.80  521.90  1796.60
District_store  56.20   26.50   123.40  456.70  789.30  1452.10
Prince_store    23.10   28.30   12.90   120.00  45.80   230.10
Columbia_store  21.50   123.00  80.90   99.00   91.20   415.60
Bowie_store     100.00  100.00  100.00  100.00  100.00  500.00
Press any key to continue . . .*/