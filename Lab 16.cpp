#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	//declare variables
	string sentence;
	string word1;
	string word2;
	string word3;
	string word4;
	int space_pos1;
	int period_pos;
	//prompt user
	cout << "Enter a four word sentence with spaces to seperate with each word"<< endl;
	//get sentence from the user
	getline(cin, sentence);
	//find the first space
	space_pos1 = sentence.find(" ");
	//get the first word
	word1 = sentence.substr(0, space_pos1);
	//display the first word
	cout << word1 << endl;
	//reduce the string by one word
	sentence = sentence.substr(space_pos1 + 1, sentence.size() - space_pos1);
	//find the second space
	space_pos1 = sentence.find(" ");
	//get the second word
	word2 = sentence.substr(0, space_pos1);
	//display the second word
	cout << word2 << endl;
	//reduce the string by one word
	sentence = sentence.substr(space_pos1 + 1, sentence.size() - space_pos1);
	//get third space
	space_pos1 = sentence.find(" ");
	//get the third word
	word3 = sentence.substr(0, space_pos1);
	//display the third word
	cout << word3 << endl;
	//reduce the string by one word
	sentence = sentence.substr(space_pos1 + 1, sentence.size() - space_pos1);
	//find the period
	sentence.find(".");
	//get the fourth word;
	word4 = sentence;
	//display the fourth word
	cout << word4 << endl;
	return 0;
}
/*Enter a four word sentence with spaces to seperate with each word
The fox ran fast.
The
fox
ran
fast.
Press any key to continue . . .*/