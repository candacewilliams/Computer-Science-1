#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string myname, fname, lname;
	int length_of_name, comma_position; 
	ifstream myfile;
 	myfile.open("infile.txt");
	for (int x = 0; x < 3; x++)
	{
		getline(myfile, myname);
		length_of_name = myname.size();
		comma_position = myname.find(',');
		//cout << length_of_name << endl;
		//cout << comma_position << endl;
		lname = myname.substr(0, comma_position);
		cout << lname + " ";
		fname = myname.substr(length_of_name - (comma_position + 2);
		cout << fname << endl;
	}
	return 0;
}