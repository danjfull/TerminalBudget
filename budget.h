#pragma once
#include "category.h"
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

class Budget {
public:
	Budget();
	// Adds a new category to this budget. Returns this new category.
	void AddCategory(string name, double monthlyMax);
	string GetCategorySummaries();
	string Command(string command);
	string PromptCategoryDetails(string command);
	long double ParseMoney(string word, string& reply);
	void Save();
private:
	vector<Category> _categories;
	
	struct transaction {
		string category;
		long double value;
		int sign;
	};
	// stores the last transaction
	transaction _last;

	enum CategoryStatus {
		initiate, // parse the confirmation of making a new category
		max, // parse the monthly maximum
		done // not making a category
	};
	// Current status of making a new category
	CategoryStatus _status;
	void Load();
	// return 0.0L if fails to parse
	long double ParseLongD(string num);
};