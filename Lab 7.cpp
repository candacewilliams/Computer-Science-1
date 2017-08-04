#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//prototype function
void lookup_name(ifstream&, string&, string&);
int main()
{
	ifstream myfile;
	string full_name; //stores full_name
	string phone_number; // stores phone_number
	string first_name; // user inputs first name
	string last_name; // user inputs last name
	string user_name; // concatenated first and last name
	string user_continue; // checks to see if user wants to insert new value
	do {
		cout << "Enter First and Last Name" << endl; //prompts user for first and last name
		cin >> first_name >> last_name; // user inputs first and last name
		user_name = first_name + " " + last_name; // concatenates first and last name
		lookup_name(myfile, user_name, phone_number); 
		//checks to see if phone_number is a blank string
		if (phone_number == " ")
		{
			cout << "This name is not in the address book" << endl;
		}	
		else 
		{
			cout << full_name << " " << phone_number << endl; //outputs name and number
		}
		
		cout << "Would you like to continue?" << endl; // prompts user to input more values
		cin >> user_continue; // user inputs Yes or No
	} while (user_continue == "Yes");
	return 0;
}
void lookup_name(ifstream& myfile, string& user_name, string& phone_number)
{
	string first_name;
	string last_name;
	string full_name;
	myfile.open("infile.txt"); //opens file
	for (int i = 0; i < 4; i++)
	{
		myfile >> first_name >> last_name >> phone_number; //reads in first name, last name, and phone number from file
		full_name = first_name + " " + last_name; //concatenates first and last name
		//conditional to check if name exists 
		if (user_name == full_name)
		{
			myfile.close(); //close file
			return;
		}
		else
		{
			phone_number = " "; // sets phone number to a blank string if user name != full name
		}
	} 
	myfile.close(); //close file
	return;
}
/*Enter First and Last Name
Harry Keeling
 (202)806-4830
Would you like to continue?
Yes
Enter First and Last Name
John Doe
This name is not in the address book
Would you like to continue?
Yes
Enter First and Last Name
Todd Shurn
 (410)560-8909
Would you like to continue?
Yes
Enter First and Last Name
Frank James
 (301)123-3459
Would you like to continue?
Yes
Enter First and Last Name
Arthur Paul
 (202)865-9090
Would you like to continue?
Yes
Enter First and Last Name
Paul Frank
This name is not in the address book
Would you like to continue?
No
Press any key to continue . . .*/