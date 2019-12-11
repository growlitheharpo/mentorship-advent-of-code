#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int SumOfDigits(std::vector<int>& digits);

int main()
{
    std::vector<int> numbers;

    std::ifstream fileIn("input.txt");
    std::string input;
    std::getline(fileIn, input);

    for (char a : input)
    {
        numbers.push_back(a - '0');
    }

    std::cout << SumOfDigits(numbers);

    std::cin.get();
    return 0;
}

int SumOfDigits(std::vector<int>& digits)
{
    int sum = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        if (i == digits.size() - 1)
        {
            if (digits[i] == digits.front())
            {
                sum += digits[i];
            }
        }

        else if (digits[i] == digits[i + 1])
        {
            sum += digits[i];
        }
    }
    return sum;
}
