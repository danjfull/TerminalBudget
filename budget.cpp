#include "budget.h"
#include <iostream>
using namespace std;

Budget::Budget()
{

}

void Budget::AddCategory(string name, double monthlyMax)
{
	categories.emplace_back(name, monthlyMax); // create a category in the categories list
}

void Budget::PrintCategorySummaries()
{
	for (auto& cat : categories) // for every cat in categories
	{
		cout << cat.Summary() << endl;
	}
}
