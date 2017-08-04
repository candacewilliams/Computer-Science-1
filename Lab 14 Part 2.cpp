#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//prototype functions
void get_user_input(char&, int&, int&, int&, int&);
float compute_item_cost(char&, int&, int&, int&, int&);
int main()
{
	//variable declarations
	char wood_type;
	int num_pieces;
	string wood_name;
	int width;
	int height;
	int length;
	float cost;
	float total_cost = 0.0;
	do
	{
		get_user_input(wood_type, num_pieces, width, height, length);
		//checks to see is user wants to calculate total to end purchase
		if (wood_type == 'T')
		{
			cout << fixed << showpoint;
			//displays total cost
			cout << "Total Cost: $" << setprecision(2) << total_cost << endl;
			break;
		}
		//sets cost of one wood type purchase to cost variable
		cost = compute_item_cost(wood_type, num_pieces, width, height, length);
		//adds cost of one purchase to total transaction
		total_cost = total_cost + cost;
		//checks wood character to print out full wood name
		if (wood_type == 'P')
		{
			wood_name = "Pine";
		}
		else if (wood_type == 'F')
		{
			wood_name = "Fir";
		}
		else if (wood_type == 'C')
		{
			wood_name = "Cedar";
		}
		else if (wood_type == 'M')
		{
			wood_name = "Maple";
		}
		else if (wood_type == 'O')
		{
			wood_name = "Oak";
		}
		//displays purchase information for one wood type 
		cout << num_pieces << " " << width << "X" << length << "X" << height
			<< " " << wood_name << "," << "Cost: $" << fixed << setprecision(2) << cost << endl;
		cout << "*******************************************" << endl;
	} while (wood_type != 'T');
	return 0;
}
//get user purchase information
void get_user_input(char& wood_type, int& num_pieces, int& width, int&height, int& length)
{
	//prompts user for purchase information
	cout << "Enter item ( Wood Type---No of Pieces---Width---Height---Length)" << endl;
	//checks if user wants to end transaction or calculates the cost for one wood type purchase
	cin >> wood_type;
		if (wood_type == 'T')
		{
			return;
		}
		cin >> num_pieces >>width >> height >> length;
}
//calculates cost of one wood type purchase
float compute_item_cost(char& wood_type, int& num_pieces, int& width, int& height, int& length)
{
	float total_dimensions;
	float cost;
	//calculate total dimensions
	total_dimensions = float(length * width * height) / 12;
	//checks wood type to get prices and multiples it by number of pieces
	if (wood_type == 'P')
	{
		cost = total_dimensions * num_pieces * 0.89;
	}
	else if (wood_type == 'F')
	{
		cost = total_dimensions * num_pieces * 1.09;
	}
	else if (wood_type == 'C')
	{
		cost = total_dimensions * num_pieces * 2.26;
	}
	else if (wood_type == 'M')
	{
		cost = total_dimensions * num_pieces * 4.50;
	}
	else if (wood_type == 'O')
	{
		cost = total_dimensions * num_pieces * 3.10;
	}
	return cost;
}
/*Enter item ( Wood Type---No of Pieces---Width---Height---Length)
P 10 2 4 8
10 2X8X4 Pine,Cost: $47.47
*******************************************
Enter item ( Wood Type---No of Pieces---Width---Height---Length)
M 1 1 12 8
1 1X8X12 Maple,Cost: $36.00
*******************************************
Enter item ( Wood Type---No of Pieces---Width---Height---Length)
T
Total Cost: $83.47
Press any key to continue . . .

*/