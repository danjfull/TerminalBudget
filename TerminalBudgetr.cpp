// TerminalBudgetr.cpp : Defines the entry point for the application.
// Note for developer: If this implementiation is unable to read a string of text accurately,
// Then the developer will instead get each part of a transaction one at a time on new lines.

#include "TerminalBudgetr.h"

using namespace std;

int main()
{
	Budget budget = Budget();
	// FOR DEBUG:
	//budget.AddCategory("groceries", 200.00); // create a category of the budget
	//budget.AddCategory("Rent", 2000.00); // price of a decent small apartment in Utah
	//budget.PrintCategorySummaries();

	// loop to get a command, and allow exiting:
	// start with app info:
	string command = "about"; // show starting information
	cout << budget.Command(command) << endl;
	cout << "Enter a transaction (or 'exit'):" << endl;
	getline(cin, command); // get first command
	while (command != "exit") // search for the word 'exit' in the string
	{
		string response = budget.Command(command); // respond to command
		if (response != string(""))
		{
			cout << response << endl;
		}
		getline(cin, command); // get a new command, full line
	}
	cout << "logout" << endl;
	return 0;
}
