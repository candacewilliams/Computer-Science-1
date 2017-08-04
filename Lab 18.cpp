#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//prototype functions
void evaluate_cholesterol(int, int, string&, string&);
float get_ratio(int, int);
void evaluate_blood_pressure(int, int, string&, string&);
int main()
{
	//variable declarations
	int data_count = 1;
	int patient_count = 0;
	int num_visits;
	int num_patients;
	int HDL_Reading;
	int LDL_Reading;
	int Systolic_Reading;
	int Diastolic_Reading;
	float ratio;
	string Systolic_Eval;
	string Diastolic_Eval;
	string HDL_Eval; 
	string LDL_Eval;
	ifstream myfile;
	string patient_name;
	char patient_status;
	//opens file
	myfile.open("infile.txt");
	//prompts user for number of patients requested
	cout << "Enter the number of patient records: ";
	cin >> num_patients;
	//outer loop keeps track of the total records requested
	while (patient_count < num_patients)
	{
		    //reads data from file
			myfile >> patient_name >> patient_status >> num_visits;
			cout << " " << endl << endl;
			cout << "Current Patient's Name- " << patient_name << endl;

		//inner while loop keeps track of the individual records for each person
		while ((num_visits > 0))
		{
			//reads data from file
			myfile >> HDL_Reading >> LDL_Reading >> Systolic_Reading >> Diastolic_Reading;
			evaluate_cholesterol(HDL_Reading, LDL_Reading, HDL_Eval, LDL_Eval);
			ratio = get_ratio(HDL_Reading, LDL_Reading);
			//prints cholesterol data
			cout << " " << endl;
			cout << "DATA SET " << data_count << endl;
			cout << "Cholesterol Profile" << endl;
			cout << "  HDL: " << HDL_Reading << " LDL: " << LDL_Reading << endl;
			cout << "  Ratio: " << ratio << endl;
			cout << "  HDL " << HDL_Eval << endl;
			cout << "  LDL " << LDL_Eval << endl;
			//checks to see if HDL -LDL ratio is good or not
			if (ratio > 0.3)
			{
				cout << "  Ratio is good" << endl;
			}
			else
			{
				cout << "  Ratio is not good" << endl;
			}
			evaluate_blood_pressure(Systolic_Reading, Diastolic_Reading, Systolic_Eval, Diastolic_Eval);
			//prints Blood Pressure data
			cout << "Blood Pressure Profile" << endl;
			cout << "  Systolic: " << Systolic_Reading << " Diastolic: " << Diastolic_Reading << endl;
			cout << "  Systolic reading is: " << Systolic_Eval << endl;
			cout << "  Diastolic reading is: " << Diastolic_Eval << endl;
		    //decrements num_visits and num_records
			num_visits--;
			data_count++;
		}
		data_count = 1;
		patient_count++;
	}
	return 0;
}
//evaluates cholesterol reading
void evaluate_cholesterol(int HDL_Reading, int LDL_Reading , string& HDL_Eval, string& LDL_Eval)
{
	//compares HDL readings to determine status
	if (HDL_Reading >= 60)
		HDL_Eval = "Excellent";
	else
		if (HDL_Reading >= 40)
			HDL_Eval = "Is Okay";
		else
			HDL_Eval = "Too Low";
	//compares LDL Reading to determine status
	if (LDL_Reading >= 190)
		LDL_Eval = "Very High";
	else
		if (LDL_Reading >= 160)
			LDL_Eval = "High";
		else
			if (LDL_Reading >= 130)
				LDL_Eval = "Borderline High";
			else
				if (LDL_Reading >= 100)
					LDL_Eval = "Near Optimal";
				else
					LDL_Eval = "Optimal";
}
//calculates ratio of HDL and LDL
float get_ratio(int HDL_Reading, int LDL_Reading)
{
	float ratio;
	ratio = float(HDL_Reading) / float(LDL_Reading);
	return ratio;
}
//evaluates blood pressure reading 
void evaluate_blood_pressure(int Systolic_Reading, int Diastolic_Reading, string& Systolic_Eval, string& Diastolic_Eval)
{
	//compares Systolic readings to determine status
	if (Systolic_Reading >= 180)
		Systolic_Eval = "Stage 3 hypertension";
	else
		if (Systolic_Reading > 160)
			Systolic_Eval = "Stage 2 hypertension";
		else
			if (Systolic_Reading > 140)
				Systolic_Eval = "Stage 1 hypertension";
			else
				if (Systolic_Reading > 130)
					Systolic_Eval = "High normal";
				else
					if (Systolic_Reading > 120)
						Systolic_Eval = "Normal";
					else
						Systolic_Eval = "Optimal";
	//compares Diastolic readings to determine status
	if (Diastolic_Reading >= 110)
		Diastolic_Eval = "Stage 3 hypertension";
	else
		if (Diastolic_Reading > 110)
			Diastolic_Eval = "Stage 2 hypertension";
		else
			if (Diastolic_Reading > 100)
				Diastolic_Eval = "Stage 1 hypertension";
			else
				if (Diastolic_Reading > 90)
					Diastolic_Eval = "High normal";
				else
					if (Diastolic_Reading > 80)
						Diastolic_Eval = "Normal";
					else
						Diastolic_Eval = "Optimal";
}
/*Enter the number of patient records: 4


Current Patient's Name- Jones

DATA SET 1
Cholesterol Profile
  HDL: 60 LDL: 124
  Ratio: 0.483871
  HDL Excellent
  LDL Near Optimal
  Ratio is good
Blood Pressure Profile
  Systolic: 130 Diastolic: 84
  Systolic reading is: Normal
  Diastolic reading is: Normal

DATA SET 2
Cholesterol Profile
  HDL: 65 LDL: 121
  Ratio: 0.53719
  HDL Excellent
  LDL Near Optimal
  Ratio is good
Blood Pressure Profile
  Systolic: 133 Diastolic: 80
  Systolic reading is: High normal
  Diastolic reading is: Optimal

DATA SET 3
Cholesterol Profile
  HDL: 70 LDL: 120
  Ratio: 0.583333
  HDL Excellent
  LDL Near Optimal
  Ratio is good
Blood Pressure Profile
  Systolic: 130 Diastolic: 81
  Systolic reading is: Normal
  Diastolic reading is: Normal


Current Patient's Name- Smith

DATA SET 1
Cholesterol Profile
  HDL: 30 LDL: 195
  Ratio: 0.153846
  HDL Too Low
  LDL Very High
  Ratio is not good
Blood Pressure Profile
  Systolic: 120 Diastolic: 85
  Systolic reading is: Optimal
  Diastolic reading is: Normal


Current Patient's Name- Williams

DATA SET 1
Cholesterol Profile
  HDL: 45 LDL: 185
  Ratio: 0.243243
  HDL Is Okay
  LDL High
  Ratio is not good
Blood Pressure Profile
  Systolic: 190 Diastolic: 112
  Systolic reading is: Stage 3 hypertension
  Diastolic reading is: Stage 3 hypertension

DATA SET 2
Cholesterol Profile
  HDL: 50 LDL: 181
  Ratio: 0.276243
  HDL Is Okay
  LDL High
  Ratio is not good
Blood Pressure Profile
  Systolic: 193 Diastolic: 115
  Systolic reading is: Stage 3 hypertension
  Diastolic reading is: Stage 3 hypertension


Current Patient's Name- Foster

DATA SET 1
Cholesterol Profile
  HDL: 55 LDL: 165
  Ratio: 0.333333
  HDL Is Okay
  LDL High
  Ratio is good
Blood Pressure Profile
  Systolic: 163 Diastolic: 115
  Systolic reading is: Stage 2 hypertension
  Diastolic reading is: Stage 3 hypertension

DATA SET 2
Cholesterol Profile
  HDL: 65 LDL: 145
  Ratio: 0.448276
  HDL Excellent
  LDL Borderline High
  Ratio is good
Blood Pressure Profile
  Systolic: 167 Diastolic: 95
  Systolic reading is: Stage 2 hypertension
  Diastolic reading is: High normal

DATA SET 3
Cholesterol Profile
  HDL: 57 LDL: 165
  Ratio: 0.345455
  HDL Is Okay
  LDL High
  Ratio is good
Blood Pressure Profile
  Systolic: 163 Diastolic: 105
  Systolic reading is: Stage 2 hypertension
  Diastolic reading is: Stage 1 hypertension

DATA SET 4
Cholesterol Profile
  HDL: 59 LDL: 163
  Ratio: 0.361963
  HDL Is Okay
  LDL High
  Ratio is good
Blood Pressure Profile
  Systolic: 165 Diastolic: 108
  Systolic reading is: Stage 2 hypertension
  Diastolic reading is: Stage 1 hypertension
  Press any key to continue . . .*/
/*Enter the number of patient records: 3


Current Patient's Name- Jones

DATA SET 1
Cholesterol Profile
  HDL: 60 LDL: 124
  Ratio: 0.483871
  HDL Excellent
  LDL Near Optimal
  Ratio is good
Blood Pressure Profile
  Systolic: 130 Diastolic: 84
  Systolic reading is: Normal
  Diastolic reading is: Normal

DATA SET 2
Cholesterol Profile
  HDL: 65 LDL: 121
  Ratio: 0.53719
  HDL Excellent
  LDL Near Optimal
  Ratio is good
Blood Pressure Profile
  Systolic: 133 Diastolic: 80
  Systolic reading is: High normal
  Diastolic reading is: Optimal

DATA SET 3
Cholesterol Profile
  HDL: 70 LDL: 120
  Ratio: 0.583333
  HDL Excellent
  LDL Near Optimal
  Ratio is good
Blood Pressure Profile
  Systolic: 130 Diastolic: 81
  Systolic reading is: Normal
  Diastolic reading is: Normal


Current Patient's Name- Smith

DATA SET 1
Cholesterol Profile
  HDL: 30 LDL: 195
  Ratio: 0.153846
  HDL Too Low
  LDL Very High
  Ratio is not good
Blood Pressure Profile
  Systolic: 120 Diastolic: 85
  Systolic reading is: Optimal
  Diastolic reading is: Normal


Current Patient's Name- Williams

DATA SET 1
Cholesterol Profile
  HDL: 45 LDL: 185
  Ratio: 0.243243
  HDL Is Okay
  LDL High
  Ratio is not good
Blood Pressure Profile
  Systolic: 190 Diastolic: 112
  Systolic reading is: Stage 3 hypertension
  Diastolic reading is: Stage 3 hypertension

DATA SET 2
Cholesterol Profile
  HDL: 50 LDL: 181
  Ratio: 0.276243
  HDL Is Okay
  LDL High
  Ratio is not good
Blood Pressure Profile
  Systolic: 193 Diastolic: 115
  Systolic reading is: Stage 3 hypertension
  Diastolic reading is: Stage 3 hypertension
  Press any key to continue . . .*/