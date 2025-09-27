#pragma once
#include "category.h"
#include <vector>
#include <string>
using namespace std;

class Budget {
public:
	Budget();
	// Adds a new category to this budget. Returns this new category.
	Category AddCategory(string name, double monthlyMax);
	void PrintCategorySummaries();
	string Command(string command);
	string PromptCategoryDetails(string command);
	long double ParseMoney(string word, string& reply);
private:
	vector<Category> categories;
	// stores the category name from the last transaction
	string categoryName;
	// stores the value from the last transaction
	long double lastValue;
	// stores if the last transaction was earning or spending
	int lastSign;
	enum CategoryStatus {
		initiate,
		max,
		done
	};
	CategoryStatus status;
};