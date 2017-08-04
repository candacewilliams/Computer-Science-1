#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//prototype functions
int get_year();
int get_starting_day();
void print_heading(int);
string read_month_name();
int read_num_days();
int print_month(int, int, string);
ifstream myfile;
int main()
{
	int year;
	int start_date;
	int num_days;
	string read_month;
	myfile.open("infile.txt");
	//priming reads
	year = get_year();
	start_date = get_starting_day();
	print_heading(year);
	cout << " " << endl;
	read_month = read_month_name();
	num_days = read_num_days();
	//loops 12 times to get start date, month, and number of days for each month
	while (myfile)
	{
		cout << "" << endl;
		start_date = print_month(start_date, num_days, read_month);
		read_month = read_month_name();
		num_days = read_num_days();
	}
}
//gets year from user input
int get_year()
{
		int year;
		cout << "Enter the year" << endl;
		cin >> year;
		return year;
}
//gets starting date from user
int get_starting_day()
{
	int start_date;
	string date;
	cout << "Enter the start date < 0 = Sun , 1 = Mon, 2 = Tues , 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat > : " << endl;
	cin >> start_date;
	return start_date;
}
//prints year heading
void print_heading(int year)
{
	cout << '\t' << '\t' << '\t' << '\t' << "YEAR -- " << year << endl;
}
//reads month from file
string read_month_name()
{
	string read_month;
	myfile >> read_month;
	return read_month;
}
//reads the number of days in month from file
int read_num_days()
{
	int read_days; 
	myfile >> read_days;
	return read_days;
}
//dipslays calendar
int print_month(int start_date, int read_days, string read_month)
{
	int last_date = 0;
	//prints month heading
	cout << '\t' << '\t' << '\t' << '\t' << read_month << endl;
	//prints days of the week
	cout << '\t' << "Sun: \tMon: \tTue: \tWed: \tThu: \tFri: \tSat:" << endl;
	//creates tabs for start dates
	for (int count = 0; count < start_date; count++)
	{
		cout << '\t';
	}
	last_date = start_date;
	for (int counter = 1; counter <= read_days; counter++)
	{
		cout << left << '\t' << counter;
		last_date++;
		if (last_date % 7== 0)
		{
			last_date = 0;
			cout << endl; 
		}
	}
	cout << " " << endl;
	return last_date;
}
/*Enter the year
2017
Enter the start date < 0 = Sun , 1 = Mon, 2 = Tues , 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat > :
5
                                YEAR -- 2017


                                January
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                                1       2
        3       4       5       6       7       8       9
        10      11      12      13      14      15      16
        17      18      19      20      21      22      23
        24      25      26      27      28      29      30
        31

                                February
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                1       2       3       4       5       6
        7       8       9       10      11      12      13
        14      15      16      17      18      19      20
        21      22      23      24      25      26      27
        28

                                March
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                1       2       3       4       5       6
        7       8       9       10      11      12      13
        14      15      16      17      18      19      20
        21      22      23      24      25      26      27
        28      29      30      31

                                April
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                        1       2       3
        4       5       6       7       8       9       10
        11      12      13      14      15      16      17
        18      19      20      21      22      23      24
        25      26      27      28      29      30

                                May
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                                        1
        2       3       4       5       6       7       8
        9       10      11      12      13      14      15
        16      17      18      19      20      21      22
        23      24      25      26      27      28      29
        30      31

                                June
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                        1       2       3       4       5
        6       7       8       9       10      11      12
        13      14      15      16      17      18      19
        20      21      22      23      24      25      26
        27      28      29      30

                                July
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                        1       2       3
        4       5       6       7       8       9       10
        11      12      13      14      15      16      17
        18      19      20      21      22      23      24
        25      26      27      28      29      30      31


                                August
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
        1       2       3       4       5       6       7
        8       9       10      11      12      13      14
        15      16      17      18      19      20      21
        22      23      24      25      26      27      28
        29      30      31

                                September
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                1       2       3       4
        5       6       7       8       9       10      11
        12      13      14      15      16      17      18
        19      20      21      22      23      24      25
        26      27      28      29      30

                                October
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                                1       2
        3       4       5       6       7       8       9
        10      11      12      13      14      15      16
        17      18      19      20      21      22      23
        24      25      26      27      28      29      30
        31

                                November
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                1       2       3       4       5       6
        7       8       9       10      11      12      13
        14      15      16      17      18      19      20
        21      22      23      24      25      26      27
        28      29      30

                                December
        Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
                                1       2       3       4
        5       6       7       8       9       10      11
        12      13      14      15      16      17      18
        19      20      21      22      23      24      25
        26      27      28      29      30      31
		Press any key to continue . . .*/