#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

class Row
{
public:
	std::vector<int> numbers;
	int smallestNumber;
	int largestNumber;
	int difference;
	int divisionResult;

	int findLargestAndSmallest()
	{
		largestNumber = numbers[0];
        smallestNumber = numbers[0];

		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] > largestNumber)
			{
				largestNumber = numbers[i];
			}

            if (numbers[i] < smallestNumber)
            {
                smallestNumber = numbers[i];
            }
		}

		return largestNumber;
	}

	int findDifference()
	{
		difference = largestNumber - smallestNumber;
		return difference;
	}

	int findDivisibleNumbers()
	{
		for (int i : numbers)
		{
			for (int j : numbers)
			{
				if (i != j)
				{
					if (i % j == 0)
					{
						divisionResult = i / j;
					}
				}
			}
		}
		return divisionResult;
	}
};

std::vector<std::string> split(const std::string& s, char delimiter);
void rowComputations(Row& row);

int main()
{
	int checksum = 0;
	std::vector<std::string> rows;

	std::ifstream fileIn("input.txt");
	std::string s;
	while (std::getline(fileIn, s))
	{
		rows.push_back(s);
	}

	for (std::string s : rows)
	{
		Row row;

		for (std::string newString : split(s, '\t'))
		{
			std::stringstream geek(newString);
            int value = std::stoi(newString);

			int x = 0;
			geek >> x;
			row.numbers.push_back(x);
		}

		rowComputations(row);
		checksum += row.divisionResult;
	}


	std::cout << "The checksum is " << checksum << "." << std::endl;
    std::cin.get();
    return 0;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

void rowComputations(Row& row)
{
	row.findDivisibleNumbers();
}
