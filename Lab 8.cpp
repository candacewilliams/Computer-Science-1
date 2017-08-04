#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//prototype functions
float compute_lab_grade();
float compute_quiz_grade();
float compute_test_grade();
float compute_assignment_grade();
float get_lab_data();
float get_quiz_data();
float get_test_data();
float get_assignment_data();
ifstream myfile;
int main()
{
	// open file
	myfile.open("infile.txt"); 
	float lab_grade_total;
	float quiz_grade_total;
	float test_grade_total;
	float assignment_grade_total;
	float lab_score;
	float quiz_score;
	float assignment_score;
	float test_score;
	float final_average;
	char final_letter_grade;
	char lab_letter_grade;
	char assignment_letter_grade;
	char quiz_letter_grade;
	char test_letter_grade;
	int count = 1;
	while (myfile) //only works if myfile has a value
	{
		lab_grade_total = compute_lab_grade();
		assignment_grade_total = compute_assignment_grade();
		quiz_grade_total = compute_quiz_grade();
		test_grade_total = compute_test_grade();
		//Assigns Letter to Lab Value
		if (lab_grade_total >= 60)
		{
			lab_letter_grade = 'A';
			lab_grade_total = 4.0;
		}
		else if ((lab_grade_total < 60) && (lab_grade_total >= 50))
		{
			lab_letter_grade = 'B';
			lab_grade_total = 3.0;
		}
		else if ((lab_grade_total < 50) && (lab_grade_total >= 40))
		{
			lab_letter_grade = 'C';
			lab_grade_total = 2.0;
		}
		else if ((lab_grade_total < 40) && (lab_grade_total >= 30))
		{
			lab_letter_grade = 'D';
			lab_grade_total = 1.0;
		}
		else if (lab_grade_total < 30)
		{
			lab_letter_grade = 'F';
			lab_grade_total = 0.0;
		}
		//Assigns Letter to Assignment Value
		if (assignment_grade_total >= 130)
		{
			assignment_letter_grade = 'A';
			assignment_grade_total = 4.0;
		}
		else if ((assignment_grade_total < 130) && (assignment_grade_total >= 112))
		{
			assignment_letter_grade = 'B';
			assignment_grade_total = 3.0;
		}
		else if ((assignment_grade_total < 112) && (assignment_grade_total >= 100))
		{
			assignment_letter_grade = 'C';
			assignment_grade_total = 2.0;
		}
		else if ((assignment_grade_total < 100) && (assignment_grade_total >= 80))
		{
			assignment_letter_grade = 'D';
			assignment_grade_total = 1.0;
		}
		else if (assignment_grade_total < 80)
		{
			assignment_letter_grade = 'F';
			assignment_grade_total = 0.0;
		}
		//Assigns Letter to Quiz Value
		if (quiz_grade_total >= 100)
		{
			quiz_letter_grade = 'A';
			quiz_grade_total = 4.0;
		}
		else if ((quiz_grade_total < 100) && (quiz_grade_total >= 85))
		{
			quiz_letter_grade = 'B';
			quiz_grade_total = 3.0;
		}
		else if ((quiz_grade_total < 85) && (quiz_grade_total >= 70))
		{
			quiz_letter_grade = 'C';
			quiz_grade_total = 2.0;
		}
		else if ((quiz_grade_total < 70) && (quiz_grade_total >= 60))
		{
			quiz_letter_grade = 'D';
			quiz_grade_total = 1.0;
		}
		else if (quiz_grade_total < 60)
		{
			quiz_letter_grade = 'F';
			quiz_grade_total = 0.0;
		}
		//Assigns Letter to Test Value
		if (test_grade_total >= 360)
		{
			test_letter_grade = 'A';
			test_grade_total = 4.0;
		}
		else if ((test_grade_total < 360) && (test_grade_total >= 210))
		{
			test_letter_grade = 'B';
			test_grade_total = 3.0;
		}
		else if ((test_grade_total < 210) && (test_grade_total >= 180))
		{
			test_letter_grade = 'C';
			test_grade_total = 2.0;
		}
		else if ((test_grade_total < 180) && (test_grade_total >= 150))
		{
			test_letter_grade = 'D';
			test_grade_total = 1.0;
		}
		else if (test_grade_total < 150)
		{
			test_letter_grade = 'F';
			test_grade_total = 0.0;
		}
		//calculates final score
		final_average = (((10 * quiz_grade_total) + (25 * assignment_grade_total) + (30 * lab_grade_total) + (35 * test_grade_total)) / 100);
		//Assigns Letter to final score
		if (final_average >= 3.49)
		{
			final_letter_grade = 'A';
		}
		else if ((final_average < 3.49) && (final_average >= 2.7))
		{
			final_letter_grade = 'B';
		}
		else if ((final_average < 2.7) && (final_average >= 1.7))
		{
			final_letter_grade = 'C';
		}
		else if ((final_average < 1.7) && (final_average >= .7))
		{
			final_letter_grade = 'D';
		}
		else if (final_average < .7)
		{
			final_letter_grade = 'F';
		}
		//outputs Letter Grades
		cout << "Student " << count << endl;
		cout << "Student's Lab Grade is: " << lab_letter_grade << endl;
		cout << "Student's Assignment Grade is: " << assignment_letter_grade << endl;
		cout << "Student's Quiz Grade is: " << quiz_letter_grade << endl;
		cout << "Student's Exam Grade is: " << test_letter_grade << endl;
		cout << "Student's Final Grade is a " << final_letter_grade << endl << endl;
		count++;
	}
	//closes file
	myfile.close();
	return 0;
}
//retrieves lab scores from the file
float get_lab_data()
{
	float lab_score;
	float lab_grade_total = 0;
	for (int iterate = 0; iterate <= 4; iterate++)
	{
		myfile >> lab_score;
		lab_grade_total = lab_grade_total + lab_score;
	}
	return lab_grade_total;
}
//retrieves assignment scores from file
float get_assignment_data()
{
	float assignment_score;
	float assignment_grade_total=0;
	for (int iterate = 0; iterate <= 6; iterate++)
	{
		myfile >> assignment_score;
		assignment_grade_total = assignment_grade_total + assignment_score;
	}
	return assignment_grade_total;
}
//retrieves quiz scores from file
float get_quiz_data()
{
	float quiz_score;
	float quiz_grade_total = 0;
	for (int iterate = 0; iterate <= 11; iterate++)
	{
		myfile >> quiz_score;
		quiz_grade_total = quiz_grade_total + quiz_score;
	}
	return quiz_grade_total;
}
//retrieves test scores from file
float get_test_data()
{
	float test_score;
	float test_grade_total = 0;
	for (int iterate = 0; iterate <= 2; iterate++)
	{
		myfile >> test_score;
		test_grade_total = test_grade_total + test_score;
	}
	return test_grade_total;
}
//takes added lab scores to one variable
float compute_lab_grade()
{
	float lab_grade_total;
	lab_grade_total = get_lab_data();
	return lab_grade_total;
}
//takes added assignment scores to one variable
float compute_assignment_grade()
{
	float assignment_grade_total;
	assignment_grade_total = get_assignment_data();
	return assignment_grade_total;
}
//takes added quiz scores to one variable
float compute_quiz_grade()
{
	float quiz_grade_total;
	quiz_grade_total = get_quiz_data();
	return quiz_grade_total;
}
//takes added test scores to one variable
float compute_test_grade()
{
	float test_grade_total;
	test_grade_total = get_test_data();
	return test_grade_total;
}
/*Student 1
Student's Lab Grade is: F
Student's Assignment Grade is: D
Student's Quiz Grade is: F
Student's Exam Grade is: B
Student's Final Grade is a D

Student 2
Student's Lab Grade is: B
Student's Assignment Grade is: C
Student's Quiz Grade is: B
Student's Exam Grade is: B
Student's Final Grade is a B

Student 3
Student's Lab Grade is: C
Student's Assignment Grade is: B
Student's Quiz Grade is: F
Student's Exam Grade is: B
Student's Final Grade is a C

Student 4
Student's Lab Grade is: C
Student's Assignment Grade is: D
Student's Quiz Grade is: F
Student's Exam Grade is: B
Student's Final Grade is a C

Student 5
Student's Lab Grade is: C
Student's Assignment Grade is: F
Student's Quiz Grade is: D
Student's Exam Grade is: B
Student's Final Grade is a C

Student 6
Student's Lab Grade is: B
Student's Assignment Grade is: A
Student's Quiz Grade is: C
Student's Exam Grade is: B
Student's Final Grade is a B

Student 7
Student's Lab Grade is: C
Student's Assignment Grade is: F
Student's Quiz Grade is: B
Student's Exam Grade is: B
Student's Final Grade is a C

Student 8
Student's Lab Grade is: A
Student's Assignment Grade is: B
Student's Quiz Grade is: C
Student's Exam Grade is: B
Student's Final Grade is a B

Student 9
Student's Lab Grade is: B
Student's Assignment Grade is: D
Student's Quiz Grade is: B
Student's Exam Grade is: C
Student's Final Grade is a C

Student 10
Student's Lab Grade is: F
Student's Assignment Grade is: C
Student's Quiz Grade is: B
Student's Exam Grade is: B
Student's Final Grade is a C

Student 11
Student's Lab Grade is: F
Student's Assignment Grade is: F
Student's Quiz Grade is: F
Student's Exam Grade is: D
Student's Final Grade is a F

Student 12
Student's Lab Grade is: B
Student's Assignment Grade is: B
Student's Quiz Grade is: B
Student's Exam Grade is: B
Student's Final Grade is a B

Student 13
Student's Lab Grade is: A
Student's Assignment Grade is: D
Student's Quiz Grade is: B
Student's Exam Grade is: B
Student's Final Grade is a B

Student 14
Student's Lab Grade is: B
Student's Assignment Grade is: B
Student's Quiz Grade is: C
Student's Exam Grade is: B
Student's Final Grade is a B

Student 15
Student's Lab Grade is: B
Student's Assignment Grade is: B
Student's Quiz Grade is: B
Student's Exam Grade is: B
Student's Final Grade is a B

Student 16
Student's Lab Grade is: F
Student's Assignment Grade is: F
Student's Quiz Grade is: F
Student's Exam Grade is: B
Student's Final Grade is a D

Student 17
Student's Lab Grade is: A
Student's Assignment Grade is: F
Student's Quiz Grade is: F
Student's Exam Grade is: B
Student's Final Grade is a C

Student 18
Student's Lab Grade is: F
Student's Assignment Grade is: B
Student's Quiz Grade is: B
Student's Exam Grade is: C
Student's Final Grade is a C

Student 19
Student's Lab Grade is: A
Student's Assignment Grade is: C
Student's Quiz Grade is: C
Student's Exam Grade is: B
Student's Final Grade is a B

Student 20
Student's Lab Grade is: F
Student's Assignment Grade is: F
Student's Quiz Grade is: F
Student's Exam Grade is: F
Student's Final Grade is a F

Press any key to continue . . .*/