#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//Make enumerated list of cars that company sells.
enum CarMakeType{ Audi, Chrysler, Ford, Nissan, Mercedes, Honda, Volvo, Porsche, Lexus }; 
string car_manufacture[9] = { "Audi" , "Chrysler", "Ford" , "Nissan", "Mercedes", "Honda", "Volvo", "Porsche", "Lexus" };
//Make a date struct that contains information about day, month, and year.
struct DateType {   
	//Declare struct variables (ALL INT).
	int day;                                    
	int month;
	int year;
};
//Make struct that contains information about the customer, delivery date of the car, cost, and car model.
struct CarType { 
	//Declare struct variables.
	string fname;                                   
	string lname;
	float cost;
	DateType date_delivery;
	CarMakeType car_make;
};
//Function Prototypes
CarType Get_Car_data(ifstream&);                          
void Lookup_Car_data(char, CarType[]);
void Modify_Car_data(float, int, CarType[]);
void Output_car_data(CarType[], ofstream&);
void Print_Car_report(CarType[]);
void Write_Car_Output(CarType[], ofstream&);
int main()
{
	//variable declarations
	CarType car_information[10];
	ifstream myfile;
	ofstream outfile;
	char user_input;
	char continue_loop;
	int count = 0;
	myfile.open("infile.txt");
	//end of file loop to add file data to array
	while (!myfile.eof() && count < 10)
	{
		car_information[count] = Get_Car_data(myfile);
		count++;
	}
	myfile.close();
	do
	{
		cout << fixed << showpoint;
		cout << " " << endl;
		//prints manufacturers in database
		cout << "Choose from the list of car manufacturers below." << endl;
		cout << "\t" << "<F - Ford, L - Lexus, N - Nissan, M - Mercedes, H - Honda," << endl;
		cout << "\t" << "A - Audi, C - Chrysler, V - Volvo, P - Porsche>" << endl;
		cout << " " << endl;
		//prompts user to insert discount
		cout << "Enter the make of the car you wish to discount: ";
		cin >> user_input;
		cout << " " << endl;
		cout << " " << endl;
		//function call to find car data match with the user input
		Lookup_Car_data(user_input, car_information);
		cout << " " << endl;
		//prompts user to contine
		cout << "Do you want to discount any more cars?";
		cin >> continue_loop;
	} while (continue_loop != 'n');
	//after completing all work in the databse, call function to display the database in a file and to the user
	Output_car_data(car_information, outfile);
	return 0;
}
//retrieves car data from database (myfile)
CarType Get_Car_data(ifstream& myfile)
	{
	//variable declarations
		CarType current_car;
		char car_model;
		//reads in value from database
		myfile >> current_car.fname >> current_car.lname >> current_car.cost >> current_car.date_delivery.day >> current_car.date_delivery.month
			>> current_car.date_delivery.year >> car_model;
		//determines the value for the car make/model
		switch (car_model)
		{
		case 'F': 
			current_car.car_make = Ford;
			break;
		case 'N': 
			current_car.car_make = Nissan;
			break;
		case 'L': 
			current_car.car_make = Lexus;
			break;
		case 'M': current_car.car_make = Mercedes;
			break;
		case 'H': current_car.car_make = Honda;
			break;
		case 'C': current_car.car_make = Chrysler;
			break;
		case 'A': current_car.car_make = Audi;
			break;
		case 'P': current_car.car_make = Porsche;
			break;
		case 'V': current_car.car_make = Volvo;
			break;
	}
		return current_car;
}
//displays current information on customer in the database
void Lookup_Car_data(char user_input, CarType car_information[])
	{
	//variable declarations
		CarMakeType conversion_int;
		float discount;
		// converts the user input into corresponding enumerator 
		switch (user_input)
		{
		case 'F': conversion_int = Ford;
			break;
		case 'N': conversion_int = Nissan;
			break;
		case 'L': conversion_int = Lexus;
			break;
		case 'M': conversion_int = Mercedes;
			break;
		case 'H': conversion_int = Honda;
			break;
		case 'C': conversion_int = Chrysler;
			break;
		case 'A': conversion_int = Audi;
			break;
		case 'P': conversion_int = Porsche;
			break;
		case 'V': conversion_int = Volvo;
			break;
		}
		//loops through number of lines in file
		for (int car_index = 0; car_index < 10; car_index++)
		{
			//checks to see if the converted_int is equal to a car model value in the database
			if (conversion_int == car_information[car_index].car_make)
			{
				//displays data for one customer
				cout << fixed << showpoint; 
				cout << "You are modifying :" << endl;
				cout << "\t" << "Customer Name: " << car_information[car_index].fname << " " << car_information[car_index].lname << endl;
				cout << "\t" << "Car Price: $" << setprecision(2) << car_information[car_index].cost << endl;
				cout << "\t" << "Purchase Date: " << car_information[car_index].date_delivery.day << "/"
					<< car_information[car_index].date_delivery.month << "/" << car_information[car_index].date_delivery.year << endl;
				cout << "\t" << "Car Model: " << car_manufacture[car_information[car_index].car_make] << endl;
				//prompts user for discount 
				cout << "Enter the discount <e.g. 0.10n = 10%>: ";
				cin >> discount;
				cout << " " << endl;
				//calls function to make price adjutment 
				Modify_Car_data(discount, car_index, car_information);
				break;
			}
		}
	}
//adjusts the price of the vehicle 
void Modify_Car_data(float discount, int car_index, CarType car_information[])
{
	cout << "Old Price : " << car_information[car_index].cost << endl;
	//resets the cost of the car to the discounted price
	car_information[car_index].cost = car_information[car_index].cost - (car_information[car_index].cost * discount);
	cout << "New Price : " << car_information[car_index].cost << endl;
	cout << int(discount * 100) << "% "<< "Discount has been applied" << endl;
}
//calls the function that will output the datbase and write information to anew file
void Output_car_data(CarType car_information[], ofstream& outfile)
{
	//function call to print database 
	Print_Car_report(car_information);
	//function call to write database into a file
	Write_Car_Output(car_information, outfile);
}
//displays database
void Print_Car_report(CarType car_information[])
{
	cout << " "  << endl;
	cout << "Customer Name" << setw(10) << "Price " << setw(25) << "Purchase Date" << setw(12) << " Model" << endl;
	cout << " " << endl;
	//loops through database to print all information for each customer
	for (int index = 0; index < 10; index++)
	{
		cout << car_information[index].fname << " " << car_information[index].lname << "      "; 
		cout << setw(10) << setprecision(2) << car_information[index].cost << "      ";
		cout << setw(7) << car_information[index].date_delivery.day << "/"
			<< car_information[index].date_delivery.month << "/" << car_information[index].date_delivery.year << "      ";
		cout << setw(10) << car_manufacture[car_information[index].car_make] << endl;
	}
}
//write databse to a new file 
void Write_Car_Output(CarType car_information[], ofstream& outfile)
{
	//loops through database
	for (int index = 0; index < 10; index++)
	{
		outfile << car_information[index].fname << " " << car_information[index].lname << "      ";
		outfile << setprecision(2) << car_information[index].cost << "      ";
		outfile << car_information[index].date_delivery.day << "/"
			<< car_information[index].date_delivery.month << "/" << car_information[index].date_delivery.year << "      ";
		outfile << car_manufacture[car_information[index].car_make] << endl;
	}
	//closes file
	outfile.close();
}
/*

Choose from the list of car manufacturers below.
<F - Ford, L - Lexus, N - Nissan, M - Mercedes, H - Honda,
A - Audi, C - Chrysler, V - Volvo, P - Porsche>

Enter the make of the car you wish to discount: L


You are modifying :
Customer Name: Bear Bare
Car Price: $44444.00
Purchase Date: 9/6/1990
Car Model: Lexus
Enter the discount <e.g. 0.10n = 10%>: .20

Old Price : 44444.00
New Price : 35555.20
20% Discount has been applied

Do you want to discount any more cars? Y

Choose from the list of car manufacturers below.
<F - Ford, L - Lexus, N - Nissan, M - Mercedes, H - Honda,
A - Audi, C - Chrysler, V - Volvo, P - Porsche>

Enter the make of the car you wish to discount: V


You are modifying :
Customer Name: Janis Smith
Car Price: $23450.00
Purchase Date: 7/11/2001
Car Model: Volvo
Enter the discount <e.g. 0.10n = 10%>: .30

Old Price : 23450.00
New Price : 16415.00
30% Discount has been applied

Do you want to discount any more cars? n

Customer Name    Price             Purchase Date       Model

Tiny Tim        55000.00            1/1/1985            Ford
Mary Murphy        12500.00            2/7/1995          Nissan
Bear Bare        35555.20            9/6/1990           Lexus
Sally Sale         7500.00            6/3/1970        Mercedes
Betty Bye        18888.00            4/8/1988        Chrysler
Alice Alas        23005.00            6/6/1992            Ford
Randy Law        12098.00            1/4/2009            Audi
Carl Lane        45000.00           12/3/2003         Porsche
Janis Smith        16415.00            7/11/2001           Volvo
George Lee        14560.00            4/4/1999           Honda
Press any key to continue . . .
*/