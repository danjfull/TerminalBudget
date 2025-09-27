# Command-Line Budget Statistics App
The main idea of this software is to reduce the amount of menus that users have to navigate through to enter a transaction in a typical budgeting software app. 
This is done by enabling the user to enter a transaction into the budget software by typing one english-like line that describes the entire transaction.
The software then categorizes it and tracks the budget.

The ultimate goal is allowing user inputs like the following example user input (typed on one line):  
```34.86 groceries yesterday at 11am```  
or:  
```2486.17 income today```  
or:  
```17 movie night on 9/30```

The budget would then store and track this, giving percentage spent so far, and if this is on track to stay under the monthly budget for that category.


## Instructions for Build and Use

Steps to build and/or run the software:

1. Ensure C++ is installed
2. Ensure Cmake is installed
3. Download the code and create a build folder within this upper-most folder.
4. From within this folder, run the command ```cmake ..```. Cmake will make the executable program. Run this program

Instructions for using the software:

1. Build and Run TerminalBudgetr.cpp
2. Type ```help``` and press enter to see instructions on how to use the program.
3. By default, a transaction can be typed into the terminal on one line, such as: ```groceries 59.04``` or ```1600.00 in income```
4. If the transaction's category does not exist, the program will prompt you to create one (and possibly set its monthly maximum)
5. typing ```summary``` and pressing enter will list the totals for each spending category in the terminal.

The program does not currently save any data between running. 

## Development Environment 

To recreate the development environment, you need the following software and/or libraries with the specified versions:

* Download Visual Studio 2022
* Tools for Cmake (donloaded using Visual Studio Installer)

## Useful Websites to Learn More

I found these websites useful in developing this software:

* [Youtube: The only CMake tutorial you will ever need (easy CMake setup tutorial)](https://www.youtube.com/watch?v=A735Y4kMIPM)
*
*

## Future Work

The following items I plan to fix, improve, and/or add to this project in the future:

* [ ] Save to a file 
* [ ] Allow a unique name fto be saved for each transaction
* [ ] accept dates and times for each transaction
* [ ] list all transactions in order by date
* [ ] Compare spending against current day of the month