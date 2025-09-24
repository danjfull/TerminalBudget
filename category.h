#pragma once
#include <string>
#include <format>
using namespace std;

class Category {
public:
	Category(string name, double max);
	void SetMax(double max);
	string Summary();
	double CurrentSpending();
private:
	string name;
	double max;

};
