#include "category.h"
using namespace std;

Category::Category(string name, double max): name(name), max(max)
{

}

void Category::SetMax(double max)
{
	this->max = max;
}

string Category::Summary()
{
	double current = CurrentSpending();
	string summary = name + string(": ") + to_string(CurrentSpending()) + string(" / ") + to_string(max);
	//string summary = std::vformat("{}: {.:2f} / {.:2f}", std::make_format_args(name, current, max)); // prints out a summary (BUGGED)
	return summary;
}

double Category::CurrentSpending()
{
	return 0.0;
}
