#pragma once
#include "category.h"
#include <vector>
#include <string>
using namespace std;

class Budget {
public:
	Budget();
	void AddCategory(string name, double monthlyMax);
	void PrintCategorySummaries();
private:
	vector<Category> categories;
};