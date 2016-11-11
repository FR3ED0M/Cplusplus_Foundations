/************************************************************************************************************************

Name: Lukas W. Garcia                             Z#: Z23237934
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 9-18-2016                     Due Time: 11:30 PM
Total Points: 100
Assignment 4: all_area_semi.cpp

Description: The program computes the semiperimeter and area of an arbitary triangle. It gathers data from the user
			 about the three sides and then computes the semiperimeter. After that, the program then executes another
			 formula that finds the area of the triangle and it reports it back to the user.

*************************************************************************************************************************/

//include necessary libraries
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//prototypes go here
void Input(int &a, int &b, int &c);
void Compute(int a, int b, int c, double &area, double &semiperimeter);


///*************************************************************************************************************************************
//Name: Input
//Precondition: The variables have not been initialized. 
//Postcondition: Asks the user to initialize variables by inputting them.
//Description: The function asks the user to enter data that will initialize the variables.
//*************************************************************************************************************************************

void Input(int &a, int &b, int &c)
{
	cout << "What is the length of side a: ";
	cin >> a;
	cout << "\nWhat is the length of side b: ";
	cin >> b;
	cout << "\nWhat is the length of side c: ";
	cin >> c;
}


///*************************************************************************************************************************************
//Name: Compute
//Precondition: Variables from Input function become initialized, but variables area and semiperimeter have not been.
//Postcondition: The function calculates the data for two variables, which is then answered back to the user.
//Description: The function uses data from the variables that were initialized in a,b,c and then places them
//			   into the calculations for semiperimeter and area. The user is then reported back the data after
//			   calculations are made.
//*************************************************************************************************************************************

void Compute(int a, int b, int c, double &area, double &semiperimeter)
{
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	
	if (((b + c) > a) && ((a + c) > b) && ((a + b) > c))
	{
		cout << "\n************************************" << endl;
		cout << "\nThe length of side a is: " << a << endl;
		cout << "The length of side b is: " << b << endl;
		cout << "The length of side c is: " << c << endl;
		
		semiperimeter = ((a + b + c) / 2);
		cout << "\nThe semiperimeter is: " << semiperimeter << endl;

		area = sqrt(semiperimeter*(semiperimeter - a)*(semiperimeter - b)*(semiperimeter - c));
		cout << "The area of the triangle is: " << area << endl;
		cout << "\n************************************" << endl;

	}
	else
	{
		cout << "\nERROR: The sum of two sides is NOT greater than the third side!" << endl;
	}
}

int main()
{
	//declare variables a, b, c, area, and semiperimeter
	int a, b, c;
	double area;
	double semiperimeter;

	string user_response = "y";

	//begin while loop
	while (user_response == "y" || user_response == "Y")
	{
		//call Input and Compute
		Input(a, b, c);
		Compute(a, b, c, area, semiperimeter);

		//ask user if he/she wants to do more calculations
		cout << "\nWould you like to keep computing area and semiperimeters (Enter y or n): ";
		cin >> user_response;
		cout << "\n";
	}
	//end while loop
	
	return 0;
}