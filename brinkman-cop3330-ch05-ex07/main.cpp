#include "main.h"

void CheckSize(vector<string> elements)
{
	if (elements.size() != 3)
	{
		cout << "Incorrect number count. Please enter in the following format: \"a b c\"";
		exit(0);
	}
}

double TryToConvert(double num, vector<string> elements, int index)
{
	try { num = stod(elements[index]); }
	catch (exception)
	{
		cout << "Incorrect value. Please enter in the following format: \"number number number\"";
		exit(0);
	}
	return num;
}

void SplitString(string str, vector<string>& vec) {

	string temp = "";
	for (int i = 0; (unsigned)i < str.length(); ++i) {

		if (str[i] == ' ') {
			vec.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(str[i]);
		}

	}
	vec.push_back(temp);
}

int CheckIfRootReal(double a, double b, double c, double &discriminant)
{
	discriminant = pow(b, 2) - (4 * a * c);

	if (discriminant < 0)
		return -1;
	else if (discriminant == 0)
		return 0;
	else
		return 1;
}

void PerformQuadratic(double a, double b, double c, double discriminant, double &result1, double &result2)
{
	result1 = (-b + sqrt(discriminant)) / (2 * a);
	result2 = (-b - sqrt(discriminant)) / (2 * a);
}

void PrintResults(int rootExists)
{
	double result1, result2;
	if (rootExists == -1)
		cout << "There are no real roots";
	else if (rootExists == 0)
	{
		cout << "There is only one real root";
	}
	else
	{
		PerformQuadratic(a, b, c, discriminant, result1, result2);
		cout << "The roots are: " << result1 << " and " << result2;
	}
}

int main()
{
	vector<string> elements;
	string input;
	double rootExists;

	cout << "Please enter the a b and c values of your quadratic equation: (Ex. 2 5 8)\n";
	getline(cin, input);

	SplitString(input, elements);

	CheckSize(elements);
	a = TryToConvert(a, elements, 0);
	b = TryToConvert(b, elements, 1);
	c = TryToConvert(c, elements, 2);

	rootExists = CheckIfRootReal(a, b, c, discriminant);

	PrintResults(rootExists);
}