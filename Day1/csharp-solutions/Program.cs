using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
	static void Main(string[] args)
	{
        List<int> numbers = new List<int>();

		Console.WriteLine("Input a number: ");
        string input = System.IO.File.ReadAllText("input.txt");

        try
        {
            foreach (char a in input)
            {
                numbers.Add(a - '0');
            }
            foreach (int s in numbers)
            {
                Console.WriteLine(s.ToString());
            }
        }
        catch (Exception e)
        {

        }

        int newSum = SumOfDigits(numbers);
        Console.WriteLine(newSum.ToString());
    }

    static int SumOfDigits(List<int> digits)
    {
        int sum = 0;
        int halfWay = digits.Count / 2;

        for (int i=0; i < digits.Count; i++)
        {
            if (i >= halfWay)
            {
                if (digits[i] == digits[i-halfWay])
                {
                    sum += digits[i];
                }
            }

            else if (digits[i] == digits[i+halfWay])
            {
                sum += digits[i];
            }
        }
        Console.WriteLine(halfWay.ToString());
        return sum;
    }
}
