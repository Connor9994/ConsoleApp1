/* 
std::end1				flushes the output buffer
\n						will not flush the output buffer
						Buffer flushes when (We tell it to) (It is Full) (Reading from the standard input stream)
<<						Output Operator
::						Scope Operator [std::cout means the name cout that is in the (namespace) scope std]
\						Escape Character for strings (Also used for String Literals like \n \t \b
return 0				Success
return int				Fail
const					Value is unchangable/doesn't plan to change
std::string::size_type	Allows String to be as large as necceary vs something like int
using std::cout;		Using-declaration that we mean for cout to be from std (can now just put [cout << "hello"])
*/

#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main()
{
	typedef vector<double>::size_type vec_sz;
	vector<string> studentNames;
	vector<double> homework;
	double x;
	double sum = 0;
	vector<double> mean;
	string UserName;

	cout << "Enter your names: \n";
	while (cin >> UserName)
	{
		studentNames.push_back(UserName);
		//vec_sz size = homework.size();
	}
	std::cin.clear();

	for (int i = 0; i != studentNames.size(); i++)
	{
		cout << "Alright " << studentNames[i] << " you're up. What'd you get on the tests? " << endl;
		while (cin >> x)
		{
			homework.push_back(x); 
			sum += x;
		}
		mean.push_back(sum / homework.size());
		std::cin.clear();
		sum = 0;
	}

	cout << mean[0] << endl << mean[1];

	/*if (size == 0)
	{
		cout << endl << "You must enter your grades. Please try again." << endl;
		return 1;
	}*/

	std::system("pause");
	return 0;
}


//Chapter 0
/*
#include "stdafx.h"
#include <iostream>
#include <string>
int math;

int main()
{
std::cout << "This (\") is a quote, and this (\\) is a backslash\n";
std::cout << "Hello, world!" << std::endl;
std::cout << "Enter Any Key To Exit" << std::endl;
std::getchar();
return 0;
}
*/

//Chapter 1
/*
#include "stdafx.h"
#include <iostream>
#include <string>
int main()
{
	// ask for the person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;         // define name
	std::cin >> name;         // read into
	
	// write a greeting
	std::string greeting = "Hello, " + name + "!";
	std::string spaces(greeting.size(),' ');
	std::string second("* " + spaces + " *");

	// write it all
	std::cout << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;

	std::system("pause");
	return 0;
}

//Chapter 1_Example
int main()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
		<< std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
		<< "; nice to meet you too!" << std::endl;
	std::system("pause");
	return 0;
}
*/

//Chapter 2
/*
#include "stdafx.h"
#include <iostream>
#include <string>
int main()
{
	// ask for the person's name
	std::cout << "Please enter your first name: ";

	// read the name
	std::string name;
	std::cin >> name;

	// build the message that we intend to write
	const std::string greeting = "Hello, " + name + "!";

	// the number of blanks surrounding the greeting
	const int pad = 1;

	// total number of rows to write
	const int rows = pad * 2 + 3;

	//Number of Columns required
	const std::string::size_type cols = greeting.size() + pad * 2 + 2;


	std::string::size_type c = 0;

	// write rows rows of output
	for (int r = 0; r != rows; ++r)
	{
		c = 0;
		while (c != cols)
		{
			if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
			{
				std::cout << "*";
				c++;
			}
			else
			{
				if (r == pad + 1 && c == pad + 1)
				{
					std::cout << greeting;
					c += greeting.size();
				}
				else
				{
					std::cout << " ";
					c++;
				}
			}
		}
		std::cout << std::endl;
	}
	std::system("pause");
	return 0;
}
*/

//Chapter 3
/*
#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

int main()
{
// ask for and read the student's name
cout << "Please enter your first name: ";
string name;

cin >> name;
cout << "Hello, " << name << "!" << endl;

// ask for and read the midterm and final grades
cout << "Please enter your midterm and final exam grades: ";
double midterm, final;
cin >> midterm >> final;

// ask for the homework grades
cout << "Enter all your homework grades, followed by end-of-file: ";

double x;
vector<double> homework;
typedef vector<double>::size_type vec_sz;

// invariant: homework contains all the homework grades read so far
while (cin >> x)
{
homework.push_back(x);
}
typedef vector<double>::size_type vec_sz;
vec_sz size = homework.size();
if (size == 0)
{
cout << endl << "You must enter your grades. Please try again." << endl;
return 1;
}

sort(homework.begin(), homework.end());
vec_sz mid = size / 2;
double median;
median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

streamsize prec = cout.precision();
cout.precision(3);
cout << "Your final grade is " << 0.2 * midterm + 0.4 * final + 0.4 * median
<< setprecision(prec) << endl;

std::system("pause");
return 0;
}
*/
