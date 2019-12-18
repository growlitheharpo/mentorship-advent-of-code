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
    int sumA = 0;
    int sumB = 0;

	int halfWay = digits.size() / 2;

    for (int i = 0; i < digits.size(); i++)
    {
        int halfwayIndex = (i + halfWay) % digits.size();
        if (digits[i] == digits[halfwayIndex])
        {
            sumB += digits[i];
        }

        if (i >= halfWay)
        {
            if (digits[i] == digits[i-halfWay])
            {
                sumA += digits[i];
            }
        }

        else if (digits[i] == digits[i + halfWay])
        {
            sumA += digits[i];
        }
    }

    if (sumA != sumB)
    {
        throw std::exception("I was wrong");
    }

    return sumA;
}
