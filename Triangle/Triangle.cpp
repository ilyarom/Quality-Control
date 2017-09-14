

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <String>
#include <algorithm>
#include <functional>

using namespace std;

/*struct LongNumber {
vector<int> numbers;
LongNumber operator +(const LongNumber &a) {
int carry = 0;
for (size_t i = 0; i < max(this->numbers.size(), a.numbers.size()) || carry; ++i) {
if (i == this->numbers.size())
this->numbers.push_back(0);
this->numbers[i] += carry + (i < a.numbers.size() ? a.numbers[i] : 0);
carry = this->numbers[i] >= 10;
if (carry)  this->numbers[i] -= 10;
}
}
LongNumber
};


void ReadNumber(string arg, vector<int> &number) {
for (size_t i = 0; i < arg.length(); ++i) {
number.push_back(arg[i]);
}
}*/

/*long double Convert(String ) {
for (size_t i = 0; i < strlen(arg.get()); ++i) {

}
}*/

bool isNumberic(string arg) {
	bool isDotUsed = false;
	if (arg[0] == '.' || arg[arg.size() - 1] == '.') {
		return false;
	}
	for (size_t i = 0; i < arg.size(); ++i) {
		if (arg[i] == '.' && isDotUsed) {
			return false;
		}
		if (arg[i] == '.') {
			isDotUsed = true;
		}
		if (arg[i] < '0' || arg[i] > '9')
			return false;
	}
	return true;
}


int main(int argc, char* argv[])
{
	if (argc != 4) {
		cout << "Specify the lengths of the sides as parameters. Input format: triangle.exe a b c" << endl;
		return 1;
	}
	string arg1 = argv[1];
	string arg2 = argv[2];
	string arg3 = argv[3];
	long double a;
	long double b;
	long double c;
	if (!isNumberic(arg1) || !isNumberic(arg2) || !isNumberic(arg3)) {
		cout << "Incorrect input data\n";
		return 1;
	}
	try {
		a = stod(arg1.c_str());
		b = stod(arg2.c_str());
		c = stod(arg3.c_str());
	}
	catch (exception exc) {
		cout << "Incorrect input data\n";
		return 1;
	}
	if (a < (b + c) && b < (a + c) && c < (a + b))
	{
		if (a == b && b == c)
		{
			cout << "Equilateral triangle" << endl;
		}
		else if (a == b || b == c || c == a)
		{
			cout << "Isosceles triangle" << endl;
		}
		else if (a*a == b*b + c*c || b*b == c*c + a*a || c*c == a*a + b*b)
		{
			cout << "Rectangular triangle" << endl;
		}
		else
		{
			cout << "Triangle has the right to life" << endl;
		}
	}
	else
	{
		cout << "Triangle is not exist" << endl;
	}
	return 0;
}

