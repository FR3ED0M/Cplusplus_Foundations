/************************************************************************************************************************

Name: Lukas W. Garcia                             Z#: Z23237934
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 10-19-2016                     Due Time: 11:30 PM
Total Points: 100
Assignment 7: charwood_freq.cpp

Description: Opens a data file, reads the contents of the data file, and outputs on the screen how many words and
			 letters that file contains.
*************************************************************************************************************************/

//Include the following
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Prototypes for the functions:
void CountWords();
void asciitochar(string & let, int * freq);
void Output(int * freq);

//Function Implementations are here:

///*********************************************************************************************************************
//Name: CountWords
//Precondition: Data file has not been opened, variables have not been initialized.
//Postcondition: Data file is opened, variables are initialized, words are counted.
//Description: The function opens the data file and reads from it how many words are in it. After it counts how many
//			   words are in the data file, it out puts them to the user on screen.
//*********************************************************************************************************************
void CountWords()
{
	ifstream in;
	in.open("mytext.dat");
	char word[25];
	int count = 0;
	while (!in.eof())
	{
		in >> word;
		count++;
	}
	cout << count << " words "<< endl;
	in.close();
}

///*********************************************************************************************************************
//Name: asciitochar
//Precondition: Variables have been initialized, file has been opened, array and strings have been set.
//Postcondition: Changes the char value of a character in the file to a calculated form from ascii code.
//Description: The function, after the file has been opened, checks the characters of the file and sets each char
//			   to a value it pertains to on the ascii table of characters. It then counts how many of those characters,
//			   either uppercase or lowercase, are present in the file.
//*********************************************************************************************************************
void asciitochar(string & let, int * freq)
{
	for (int i = 0; i < let.length(); i++)
	{
		//lowercase ascii table
		if (toascii(let[i]) > 96 && toascii(let[i]) < 123)
		{
			freq[toascii(let[i]) - 96]++;
		}
		//uppercase ascii table
		if (toascii(let[i]) > 64 && toascii(let[i]) < 91)
		{
			freq[toascii(let[i]) - 64]++;
		}
	}
}

///*********************************************************************************************************************
//Name: Output
//Precondition: Variables have been initialized, file opened, arrays are set, and acsii table is used.
//Postcondition: The array is used for showing user how many of each ascii table character are in file.
//Description: The user is shown the data from which the function asciitochar has extracted, with each character
//			   given a value of how many exist in the data file.
//*********************************************************************************************************************
void Output(int * freq)
{
	for (int i = 1; i < 27; i++)
	{
		if (freq[i] > 9 && freq[i] != 0)
		{
		cout <<  freq[i] << " " << char(96 + i) << endl;
		}
		if (freq[i] < 10 && freq[i] != 0)
		{
			cout << freq[i] << "  " << char(96 + i) << endl;
		}
	}
}


//Here is your driver to test the program
int main()
{
	int freq[27];
	string let;
	int i;

	//initialized and declaring the array to zero
	for (i = 0; i < 27; i++)
	{
		freq[i] = 0;
	}

	//opening the data file
	ifstream in;
	in.open("mytext.dat");

	if (in.fail())
	{
		//text to show in case file has not been found.
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		CountWords();
		getline(in, let);		//allows for the program to read line with whitespace
		asciitochar(let,freq);
		Output(freq);
	}
	in.close();
}