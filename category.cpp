#include "category.h"
using namespace std;

Category::Category() : name("_NOT_SET_"), max(0.00L), current(0.0L)
{
	
}

Category::Category(const Category& other)
{
	// This is the copy contructor
	this->name = other.name;
	this->max = other.max;
	this->current = other.current;
}

Category::Category(string name, long double max) : name(name), max(max)
{
	current = 0.0L;
}

void Category::SetMax(long double max)
{
	this->max = max;
}

string Category::Summary()
{
	ostringstream ss; // a stream to put formatted text into
	ss << fixed << setprecision(2); // format the stream
	// use < << setfill('_') > to pad next item with a custom character

	ss << "|" << setw(24) << name << ": $" << setw(10) << CurrentSpending() << " / $" << setw(10) << max; // In USD, by default
	
	return ss.str(); // return the stream as a string
}

void Category::AddTransaction(long double amount)
{
	current += amount;
}

long double Category::CurrentSpending()
{
	return current;
}

string Category::SaveCsv()
{
	return name + "," + to_string(current) + "," + to_string(max);
}
