#include "budget.h"
#include <iostream>
using namespace std;

Budget::Budget(): categoryName(""), lastValue(0.0L), lastSign(1), status(CategoryStatus::done)
{

}

Category Budget::AddCategory(string name, double monthlyMax)
{
	categories.emplace_back(name, monthlyMax); // create a category in the categories list
	return categories.back();
}

void Budget::PrintCategorySummaries()
{
	for (auto& cat : categories) // for every cat in categories
	{
		cout << cat.Summary() << endl;
	}
}

string Budget::PromptCategoryDetails(string command)
{
	string reply = "";
	// check to see if they wanted to make a new category
	if (status == CategoryStatus::initiate) //
	{
		if (command == "y" || command == "Y" || command == "yes")
		{
			if (lastSign == -1)
			{
				// Then this is income, not expense
				Category cat = AddCategory(categoryName, 0.0L); // set the max to 0.0
				cat.AddTransaction(lastValue);
				reply += "\nCreated new: \n" + cat.Summary();
				status = CategoryStatus::done;
			}
			else
			{
				// define a monthly max for this expense
				reply = "Define monthly maximum for: " + categoryName;
				status = CategoryStatus::max;
			}
		}
		else
		{
			// cancel the transaction and don't make a new category for it.
			status = CategoryStatus::done; // they don't want to make a category
			reply = " transaction cancelled";
		}
	}
	else if (status == CategoryStatus::max)
	{
		long double max = ParseMoney(command, reply);
		if (reply.find("ERROR") == string::npos)
		{
			Category cat = AddCategory(categoryName, max);
			cat.AddTransaction(lastValue);
			reply += "\nCreated new: \n" + cat.Summary();
			status = CategoryStatus::done;
		}
		else
		{
			reply += "\n--> Invalid value! Try again.";
		}
	}
	return reply;
}

long double Budget::ParseMoney(string word, string& reply)
{
	long double multiplier = 1.00L;
	// first, remove any character modifiers
	if (word.ends_with('k'))
	{
		multiplier *= 1000.00L; // multiply by 1000 (1k)
		reply += " multiplier 1000,";
		word.pop_back(); // remove the k
	}
	if (word.starts_with('$'))
	{
		reply += " erase $,";
		word.erase(0, 1); // remove any dollar signs
	}

	// try to get a number from it
	long double newValue = 0.00L;
	try {
		newValue = stold(word); // convert to long double
	}
	catch (const invalid_argument& e) {
		reply += " ERROR invalid argument- " + string(e.what());
		newValue = 0.00L;
	}
	catch (const out_of_range& e) {
		reply += " ERROR argument out of range- " + string(e.what());
		newValue = 0.00L;
	}
	
	return newValue * multiplier;
}

string Budget::Command(string command)
{
	// here's a unique setup: This function acts as the API for the budget, accepting strings of commands,
	// and then returning a response. This makes it so that the <main()> function doesn't need to handle this logic
	if (command != string(""))
	{
		string reply = ""; // string to send information back out
		// do logic on this string
		
		if (status != CategoryStatus::done)
		{
			return PromptCategoryDetails(command); // check for category creation
		}

		// populate these details:
		string category = "";
		long double value = 0.00L;

		// parse the string into details
		bool category_start = true;
		int sign = 1;
		long double multiplier = 1.00L;
		stringstream ss(command);
		string word;
		while (ss >> word) // go through each word in the string
		{
			reply += " analyzing '" + word + "',";
			// see if it is a number
			bool hasdigit = false;
			for (char l : word)
			{
				if (isdigit(l))
				{
					hasdigit = true;
				}
			}


			if (word == "spent")
			{
				if (sign != 1)
				{
					reply += " sign changed to 1,";
				}
				sign = 1;
				//category_start = false;
			}
			else if (word == "earned" || word == "income")
			{
				sign = -1; // record that money was earned
				reply += " sign changed to -1,";
				if (word == "income")
				{
					category += word;
				}
				//category_start = false;
			}
			else if (word.ends_with("cents"))
			{
				multiplier *= 0.01L; // this is in cents
				reply += " multiplier 0.01,";
				
				//category_start = false;
			}
			else if (hasdigit) // convert to a value
			{
				// see if this was meant to be a number
				long double newValue = ParseMoney(word, reply);
				if (abs(newValue) > 0.00L)
				{
					if (abs(value) > 0.00L) // if a value was already recorded
					{
						reply += " updating old transaction value (" + to_string(value) + ") to " + to_string(newValue) + " in " + word + ",";
					}
					value = newValue; // then this must be the new value. Disregard the old value
					//category_start = false; // don't allow a new category name to start
				}
			}
			else if (word == "at" || word == "in" || word == "on")
			{
				// then this might be the start of a category name
				reply += " detected category starting,";
				category_start = true;
			}
			else if (word == "summary")
			{
				PrintCategorySummaries(); // print summaries
				return string(" printing summaries:");
			}
			else if (word == "help" || word == "--list") // if they say help, give a help menu of information
			{
				return string("type 'exit' to logout and close this program.\n\
Or, type a dollar amount and its spending/earning category name (dollar signs '$' not required).\
\n Use the word 'earned' or 'income' to denote a category in which money is gained.\
\n You may use the word 'cents' to describe an amount. \
\n Use 'k' at the end of a number to state that it is multiplied by 1000.\
\n You may use negative numbers in a transaction (for example, to denote a refund).");
			}
			else if (word == "about")
			{
				return string("----- TerminalBudgetr app v1.0 ----- By D Fuller, September 2025\nThis software is provided 'as-is', with no guarantees whatsoever.\nType 'help' to see available commands.");
			}
			else
			{
				if (category != "")
				{
					category += " "; // add a space between words in a category name
				}
				category += word; // add this word to the category name
			}
		}
		value = multiplier * value; // when all modifiers are done, calculate the new value

		// now add to the category with this new value
		bool found = false;
		for (auto& cat : categories)
		{
			if (cat.Name() == category)
			{
				cat.AddTransaction(value);
				ostringstream ss; // a stream to put the formatted number into
				ss << fixed << setprecision(2) << value; // format the stream
				reply += "\n-> added " + ss.str() + " to " + cat.Name();
				found = true;
			}
		}
		if (!found)
		{
			reply += "\n Category not yet defined: '" + category + "'. Make new (y/n)?";
			status = CategoryStatus::initiate;
		}
		// keep track of this new transaction's details
		lastSign = sign;
		categoryName = category;
		lastValue = value;
		return reply;

		/*// search for the category
		size_t found = command.find("groceries");
		if (found != string::npos)
		{
			for (auto& cat : categories)
			{
				if (cat.Name() == "groceries")
				{
					cat.AddTransaction(10.00L); // add a transaction to this category
				}
			}
			return string("Added $10 to category 'groceries'");
		}
		else // see if they want a printed summary
		{
			found = command.find("summary");
			if (found != string::npos)
			{
				PrintCategorySummaries(); // print summaries
			}
		}
		*/
	}
	else return string("");
}
