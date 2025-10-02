# Command-Line Budget App
The main idea of this software is to reduce the amount of menus that users have to navigate through to enter a transaction in a typical budgeting software app. 
This is done by enabling the user to enter a transaction into the budget software by typing one english-like line that describes the entire transaction.
The software then categorizes it and tracks the budget.

The program is designed to allow user inputs like the following example user inputs (each is typed on one line):  
```34.86 in groceries```  
or:  
```income $2486.07```  
or:  
```1.7k on rent```

The budget would then store and track this spending, prompting the user to create categories as needed.

## Instructions for Build and Use

Steps to build and/or run the software:

1. Ensure C++ 20 is installed
2. Ensure Cmake is installed
3. Download the code and create a build folder within this upper-most folder.
4. From within this folder, run the command ```cmake ..```. Cmake will make the executable program. Run this program

Instructions for using the software:

1. Build and Run TerminalBudgetr.cpp
2. Type ```help``` and press enter to see instructions on how to use the program.
3. By default, a transaction can be typed into the terminal on one line, such as: ```groceries 59.04``` or ```1600.00 in income```
4. If the transaction's category does not exist, the program will prompt you to create one (and possibly set its monthly maximum)
5. typing ```summary``` and pressing enter will list the totals for each spending category in the terminal.
6. ```exit``` or ```quit``` can be typed on a single line, no capitals or spaces, anytime. It will save the current status of the budget and close the program.

The program saves all of the current spending category data in its local folder in the computer, loading (or creating) it each time the program starts.
If users wish to remove a budget category, they must edit the csv program's saved csv file, which is in the form of ```category_name, current_spent, max_spent``` and has 1 line for each category.

## Development Environment 

To recreate the development environment, you need the following software and/or libraries with the specified versions:

* Download Visual Studio 2022
* Download C++ 20
* Tools for Cmake (donloaded using Visual Studio Installer)

## Useful Websites to Learn More

I found these websites useful in developing this software:

* [Youtube: The only CMake tutorial you will ever need (easy CMake setup tutorial)](https://www.youtube.com/watch?v=A735Y4kMIPM)
* [W3 schools C++ Files](https://www.w3schools.com/cpp/cpp_files.asp)
* [CSV file management on GeeksForGeeks](https://www.geeksforgeeks.org/cpp/csv-file-management-using-c/)
* [Cplusplus Vector class documentation](https://cplusplus.com/reference/vector/vector/)

Google Chrome's search engine AI also provided some quick answers about a few C++ operations.

## Future Work

The following items I plan to fix, improve, and/or add to this project in the future:

* [ ] Allow a unique name to be saved for each transaction
* [ ] accept dates and times for each transaction
* [ ] list all transactions in order by date
* [ ] Compare spending against current day of the month