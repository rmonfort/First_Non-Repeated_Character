#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::count;
using std::string;
using std::unique;
using std::sort;

// Determines first non-repeated character in string s
char first_non_repeated_char(const string& s)
{
	// Cycle through each character int he string and check if it's repeated
	for (auto& c : s)
	{
		int mycount = count(s.begin(), s.end(), c);

		// If character not repeated elsewhere in string, return that character
		if (mycount == 1)
		{
			return c;
		}
	}

	// Return a blank if no non-repeated character found in string s
	return ' ';
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	// Cycle through input file
	string line;
	while (getline(ifs, line))
	{
		// Ignore empty lines
		if (line == "")
		{
			continue;
		}

		// Determine first non-repeated character in line and output it
		char first_char = first_non_repeated_char(line);
		cout << first_char << endl;
	}

	return 0;
}