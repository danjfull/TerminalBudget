#pragma once
#include <string>
#include <format>
#include <iomanip>
#include <vector>
#include <sstream> // for converting an output stream to a string
using namespace std;

class Category {
public:
	Category();
	// Create copy of this category
	Category(const Category& other);
	Category(string name, long double max);
	void SetMax(long double max);
	string Summary() const;
	long double CurrentSpending() const;
	void AddTransaction(long double amount);
	string Name() { return name; };
	// return a csv string of this category information
	string SaveCsv();
private:
	string name;
	long double max;
	long double current; // current amount spent in this category
};
