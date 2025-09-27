#pragma once
#include <string>
#include <format>
#include <iomanip>
#include <sstream> // for converting an output stream to a string
using namespace std;

class Category {
public:
	Category(string name, long double max);
	void SetMax(long double max);
	string Summary();
	long double CurrentSpending();
	void AddTransaction(long double amount);
	string Name() { return name; };
private:
	string name;
	long double max;
	long double current; // current amount spent in this category
};
