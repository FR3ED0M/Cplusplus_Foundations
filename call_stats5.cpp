/************************************************************************************************************************

Name: Lukas W. Garcia                             Z#: Z23237934
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 10-30-2016                     Due Time: 11:30 PM
Total Points: 100
Assignment 7: call_stats5.cpp

Description: Program reads names and information from a file, processes the data with calculations, grabs user input to 
			 search, add, and remove an item from/to the list. Information is then presented to the user. After all info
			 has been shown, the class record is than erased from existence.
*************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


class call_record
{
public:
	string firstname;
	string lastname;
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

//prototypes go here
void Initialize(call_record *& call_DB, int & count, int & size); //reads the file and sets data to class variables
bool Is_empty(const int count); //return true is call_DB empty; otherwise false
bool Is_full(const int count, int size); //return tree is call_DB is full; otherwise false
int Search(const call_record *call_DB, const int count, const string key);//returns location if item in listl; otherwise return -1
void Add(call_record * &call_DB, int & count, int & size, const string key); //adds item inorder to the list
void Remove(call_record *call_DB, int & count, const string key); //removes an item from the list
void Double_size(call_record * &call_DB, int & count, int & size);
void Process(call_record *call_DB, const int & count);
void Print(const call_record *call_DB, int & count); //prints all the elements in the list to the screen
void Destroy_call_DB(call_record * &call_DB); //de-allocates all memory allocate to call_DB by operator new.



/************************************************************************************************************************************/
//Name: Initialize
//Precondition: Variables have not been declared.
//Postcondition: File is opened, variables are declared, and data is imported into the class records.
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record, 
//call_DB. If the count because equal to the size the function double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
void Initialize(call_record * & call_DB, int & count, int & size)
{
	count = 0;
	ifstream in;
	in.open("callstats_data.txt");

	while (!in.eof())
	{
		if (Is_full(count, size))
		{
			Double_size(call_DB, count, size);
		}
		in >> call_DB[count].firstname;
		in >> call_DB[count].lastname;
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;
		count++;
		//NOTE: THE OTHER FIELDS (net_cost, tax_rate, call_tax, total_cost) WILL BE DETERMINE IN PROCESS.... 
	}
	in.close();

}

/***********************************************************************************************************************************/
//Name: Is_empty
//Precondition: Variable count has been declared
//Postcondition: If count is zero, returns a true positive, but if not it returns as not empty
//Decription: Returns true if call_DB is empty
/**********************************************************************************************************************************/
bool Is_empty(const int count)
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**********************************************************************************************************************************/
//Name: Is_full 
//Precondition: Variables have been declared
//Postcondition: If array is full, then count is equal to that of the size.
//Decription: Returns true if call_DB is full
/*********************************************************************************************************************************/
bool Is_full(const int count, int size)
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: Search
//Precondition: Variables and functions have been declared 
//Postcondition: Loop has been declared and initialized
//Decription: Locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int Search(const call_record *call_DB, const int count, const string key)
{
	//very important
	//step 1: create for loop. Hint:  int i =0; i<count; i++
	//step2: in body of loop use an if statement with no else..Hint: if (call_DB[i].cell_number == key).. return i;
	//step3: outside for loop: Hint: if program reaches this point, key was not in call_DB...return -1.
	//end if function

	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].cell_number == key)
		{
			return i;
		}
	}
	return -1;
}

/*********************************************************************************************************************************/
//Name: Add
//Precondition: Variables and functions have been declared
//Postcondition: Variable and functions gets implemented for use for search function
//Decription: Adds a key to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void Add(call_record * &call_DB, int & count, int & size, const string key)
{

	//very important
	//step 1: check to see if call_DB Is_full
	//step 2: if call_DB is full Double_size
	//        if call_DB is not full just add record to the end of call_DB.  The cell number of the new call record
	//           is stored in key. You must prompt the user for the other fields...
	if (Is_full(count, size))
	{
		Double_size(call_DB, count, size);
	}
	call_DB[count].cell_number = key;
	cout << endl << endl;
	cout << "Enter firstname, lastname, relays and call_length:\n";
	cin >> call_DB[count].firstname;
	cin >> call_DB[count].lastname;
	cin >> call_DB[count].relays;
	cin	>> call_DB[count].call_length;
	count++;
}

/********************************************************************************************************************************/
//Name: Remove
//Precondition: Variables and function have been intialized and declared
//Postcondition: Function gets created for implementation with Search function
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void Remove(call_record *call_DB, int & count, const string key)
{
	//very important
	//step 0: check to see if empty; if empty return -1 otherwise continue
	//step 1: call Search and see if key is in call_DB; Hint: int loc = Search...
	//step 2: if loc == -1 then key not in call_DB
	//step 3: if loc != -1 then key is in call_DB
	//step 4: Use a for loop to shift up; Hint: for(int j = loc; j<count-1; j++)
	//                                             call_DB[j] = call_DB[j+1];
	//step 5: Outside the for loop decrement count by 1
	//all finish

	if (Is_empty(count))
	{
		count = 0;
	}

	int loc = Search(call_DB, count, key);
	if (loc != -1)
	{
		for (int i = loc; i < count - 1; i++)
		{
			call_DB[i] = call_DB[i + 1];
		}
		count--;
	}
}

/******************************************************************************************************************************/
//Name: Double_Size
//Precondition: Variables have not been initialized
//Postcondition: Variables become initialized and declared
//Decription: Doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void Double_size(call_record * &call_DB, int & count, int & size)
{

	//KNOW AND UNDERSTAND THIS
	size *= 2;  //double the size (in this program, the size is the capacity

	call_record *temp = new call_record[size]; //allocate space for the new array (this whose size has been doubled

											//copy contents of call_DB into new memory pointed to by temp -- which is doubled the size
	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;  //de-allocate old memory of call_DB;
	call_DB = temp;  //assign new memory pointed to by temp to call_DB
}


/******************************************************************************************************************************/
//Name: Process
//Precondition: Class variables have not been computed
//Postcondition: Calculations are implemented, variables declared, and added into array
//Decription: Calculates the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void Process(call_record *call_DB, const int & count)
{
	for (int i = 0; i < count; i++)
	{
		//determine the net_cost
		call_DB[i].net_cost = (call_DB[i].relays / 50.0)*0.40*call_DB[i].call_length;

		//determine the tax rate
		if (call_DB[i].relays >= 0 && call_DB[i].relays <= 5)
		{
			call_DB[i].tax_rate = 0.01;
			call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		}
		else if (call_DB[i].relays >= 6 && call_DB[i].relays <= 11)
		{
			call_DB[i].tax_rate = .03;
			call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		}
		else if (call_DB[i].relays >= 12 && call_DB[i].relays <= 20)
		{
			call_DB[i].tax_rate = .05;
			call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		}
		else if (call_DB[i].relays >= 21 && call_DB[i].relays <= 50)
		{
			call_DB[i].tax_rate = .08;
			call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		}
		else
		{
			call_DB[i].tax_rate = .12;
			call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		}

		//determine the total_cost
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
	}
}


/****************************************************************************************************************************/
//Name: Print
//Precondition: Variables have not been formatted for output use
//Postcondition: All data is formatted for readability purposes.
//Decription: Prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void Print(const call_record *call_DB, int & count)
{
	for (int i = 0; i<count; i++)
	{
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout.setf(ios::fixed);

		//these 3 if statements are used to format the data to output
		if (call_DB[i].firstname.size() + call_DB[i].lastname.size() >= 16)
		{
			cout << call_DB[i].firstname << " ";
			cout << call_DB[i].lastname << "\t";
		}

		if (call_DB[i].firstname.size() + call_DB[i].lastname.size() == 15)
		{
			cout << call_DB[i].firstname << " ";
			cout << call_DB[i].lastname << "\t";
		}

		if (call_DB[i].firstname.size() + call_DB[i].lastname.size() < 15)
		{
			cout << call_DB[i].firstname << " ";
			cout << call_DB[i].lastname << "\t\t";	
		}

		//*Note: if a name is less than 10 characters long, there might be a format issue

		//here is the rest of the data that will be printed after the names
		cout << call_DB[i].cell_number << "\t";
		cout << call_DB[i].relays << "\t";
		cout << call_DB[i].call_length << "\t";
		cout << call_DB[i].net_cost << "\t";
		cout << call_DB[i].tax_rate << "\t";
		cout << call_DB[i].call_tax << "\t";
		cout << call_DB[i].total_cost << endl;
	}
}

/****************************************************************************************************************************/
//Name: Destroy_call_DB
//Precondition: Array has not been deleted
//Postcondition: Array gets deleted
//Decription: De-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void Destroy_call_DB(call_record * &call_DB)
{
	delete[] call_DB;
	call_DB = '\0';		//set to null
}


//the main driver goes here
int main()
{
	int size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	int count = 0;
	call_record *call_DB = new call_record[size];
	string key;

	//prints the original data found within the array
	cout << "*****************************************************************************************\n";
	Initialize(call_DB, count, size);
	Process(call_DB, count);
	Print(call_DB, count);
	cout << "*****************************************************************************************\n";

	//asks users for input, searches the array, asks user for info, adds it to menu, then prints back to main screen
	cout << endl;
	cout << "Enter the cell number of the item to add: ";
	cin >> key;
	Add(call_DB, count, size, key);
	Process(call_DB, count);
	cout << endl;
	cout << "*****************************************************************************************\n";
	Print(call_DB, count);
	cout << "*****************************************************************************************\n";
	
	//asks user for input, searches the array, removes item from menu, then prints back to the main screen
	cout << endl;
	cout << "Enter the cell number of the item to remove: ";
	cin >> key;
	Search(call_DB, count, key);
	Remove(call_DB, count, key);
	cout << endl;
	cout << "*****************************************************************************************\n";
	Print(call_DB, count);
	cout << "*****************************************************************************************\n";
	
	//destroys the array by deleting it, and then prompts the user of what has occured
	Destroy_call_DB(call_DB);
	cout << endl;
	cout << "*************************** The call records have been erased ***************************" << endl;
	cout << endl << endl;

	return 0;
}