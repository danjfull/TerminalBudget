// TerminalBudgetr.cpp : Defines the entry point for the application.
//

#include "TerminalBudgetr.h"

using namespace std;

int main()
{
	Budget budget = Budget();
	budget.AddCategory("groceries", 200.00); // create a category of the budget
	budget.AddCategory("Rent", 2000.00); // price of a decent small apartment in Utah
	budget.PrintCategorySummaries();
	cout << "Hello CMake" << endl;
	return 0;
}
