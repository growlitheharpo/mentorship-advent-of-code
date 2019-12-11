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

		Console.WriteLine("Hello world!");
        string input = Console.ReadLine();

        try
        {
            foreach (char a in input.ToCharArray())
            {
                numbers.Add((int)Char.GetNumericValue(a));
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
        for (int i=0; i < digits.Count; i++)
        {
            if (i == digits.Count-1)
            {
                if (digits[i] == digits.First())
                {
                    sum += digits[i];
                }
            }

            else if (digits[i] == digits[i+1])
            {
                sum += digits[i];
            }
        }
        return sum;
    }
}
