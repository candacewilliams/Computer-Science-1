#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//prototype function
bool isHung(int);
int main()
{
	int question_counter = 0;
	string Question;
	string Answer_A;
	string Answer_B;
	string Answer_C;
	string Answer_D;
	string Correct_Answer;
	string Title;
	string Word;
	char Answer_Char;
	char User_Answer;
	char dummy;
	int num_errors = 0;
	ifstream myfile;
	myfile.open("infile.txt");
	while (question_counter <= 16)
	{
		cout << fixed << showpoint;
		getline(myfile, Question); // read question
		cout << "*********************MY HANG MAN GAME *************************" << endl;
		cout << Question << endl; //display question
		//Read and Display each answer'
		getline(myfile, Answer_A);
		cout << "\t " << Answer_A << endl;
		getline(myfile, Answer_B);
		cout << "\t " << Answer_B << endl;
		getline(myfile, Answer_C);
		cout << "\t " << Answer_C << endl;
		getline(myfile, Answer_D);
		cout << "\t " << Answer_D << endl;
		myfile >> Title >> Word >> Answer_Char;
		myfile.get(dummy);
		//Prompts User for Answer
		cout << "\t " << "Enter the capital letter of your answer ";
		//Get Answer from the User
		cin >> User_Answer;
		//Determine if User Answer is Correct
		if (User_Answer!= Answer_Char)
		{
			num_errors = num_errors + 1;
			if ((isHung(num_errors)) == true)
			{
				cout << "You've Been Hung" << endl;
				break;
			}
		}
		else
		{
			cout << "CORRECT" << endl;
			cout << "***************************************************************" << endl;
		}
		system("pause");
		system("cls"); //clears the screen
		question_counter = question_counter +1;
	}
	return 0;
}
//Determine if User "Is Hung"
bool isHung(int num_errors)
{
	if (num_errors == 1)
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << " O " << endl;
		cout << "***************************************************************" << endl;
	}
	else if (num_errors == 2)
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << " |" << endl;
		cout << "***************************************************************" << endl;
	}
	else if (num_errors == 3)
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << " |\\ "<< endl;
		cout << "***************************************************************" << endl;
		return false;
	}
	else if (num_errors == 4)
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << "  O " << endl;
		cout << "\t \t \t" << " /|\\" << endl;
		cout << "***************************************************************" << endl;
		return false;
	}
	else if (num_errors == 5)
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;
		cout << "***************************************************************" << endl;
		return false;
	}
	else if (num_errors == 6)
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;
		cout << "\t \t \t" << "  \\" << endl;
		cout << "***************************************************************" << endl;
		return false;
	}
	else
	{
		cout << "INCORRECT" << endl;
		cout << "\t \t \t" << " O " << endl;
		cout << "\t \t \t" << "/|\\" << endl;
		cout << "\t \t \t" << " | " << endl;
		cout << "\t \t \t" << "/ \\ " << endl;
		return true;
	}
}
/*
*********************MY HANG MAN GAME *************************
Question: What relational operator means greater than or equal to?
A Answer: >
B Answer: >=
C Answer: =>
D Answer: <
Enter the capital letter of your answer B
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: What two values does a bool variable allow?
A Answer: 0 and 1
B Answer: True or false
C Answer: Yes and no
D Answer: 1 and 2
Enter the capital letter of your answer B
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: Which relational expression (where x is 4 and y is 8) is true?
A Answer: x = y
B Answer: x > y
C Answer: x < = y
D Answer: x >= y
Enter the capital letter of your answer C
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: If we place an if statement within an if statement, we are creating a
A Answer: If-Then-Else statement
B Answer: Multiway branch
C Answer: If-Then-Else-If statement
D Answer: Nested control structure
Enter the capital letter of your answer D
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: The && and || operators are
Answer A: Binary operators
Answer B: Unary operators
Answer C: Secondary operators
Answer D: Primary operators
Enter the capital letter of your answer A
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: To find out if either the test grade is an A or the quiz grade is an A we would write the expression
Answer A: testGrade = `A' || quizGrade = `A'
Answer B: testGrade = `A' && quizGrade = `A'
Answer C: testGrade == `A' && quizGrade == `A'
Answer D: testGrade ==`A' || quizGrade == `A'
Enter the capital letter of your answer D
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: Which two pairs of expressions are equivalent?
A Answer: !(a == b) and a != b
B Answer: !(a == b) and a =! B
C Answer: (a == b)! and a != b
D Answer: (a == b)! and a =! B
Enter the capital letter of your answer A
CORRECT
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: Which operator has the lowest precedence?
A Answer: &&
B Answer: ==
C Answer: ||
D Answer: =
Enter the capital letter of your answer C
INCORRECT
O
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: An assertion that must be true before a module is executed for the module to execute correctly is a
A Answer: Postcondition
B Answer: Precondition
C Answer: Priorcondition
D Answer: Subsequentcondition
Enter the capital letter of your answer C
INCORRECT
O
|
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: The While statement is different from the If statement because
A Answer: It is a looping structure
B Answer: It is used to repeat a course of action
C Answer: The statement is either skipped, executed once, or executed over and over
D Answer: All of the above
Enter the capital letter of your answer C
INCORRECT
O
|\
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: What are the two major types of loops?
A Answer: Count-controlled loops and event-controlled loops
B Answer: Sentinel-controlled loops and end-of-file-Controlled loops
C Answer: Sentinel-controlled loops and flag-controlled loops
D Answer: Count-controlled loops and flag-controlled loops
Enter the capital letter of your answer C
INCORRECT
O
/|\
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: A While statement is a looping construct that allows a program to repeat a statement as long as the value on an expression is
A Answer: False
B Answer: True
C Answer: Positive
D Answer: Negative
Enter the capital letter of your answer C
INCORRECT
O
/|\
|
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: What are the phases of loop execution? 
         A Answer: Entry, test, exit
         B Answer: Entry, iteration, test
         C Answer: Entry, iteration, test, exit
         D Answer: Entry, entry, iteration, exit
         Enter the capital letter of your answer D
INCORRECT
                         O
                        /|\
                         |
                          \
***************************************************************
Press any key to continue . . .
*********************MY HANG MAN GAME *************************
Question: Event-controlled loops repeat until
         A Answer: something happens within the loop
         B Answer: the specified number of times is reached
         C Answer: the statement has been executed 25 times
         D Answer: the statement is false
         Enter the capital letter of your answer C
INCORRECT
                         O
                        /|\
                         |
                        / \
You've Been Hung
Press any key to continue . . .
*/
//pasting distorted the comment block