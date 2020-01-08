
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        int checksum = 0;

        string[] rows = File.ReadAllLines("input.txt");


        foreach (string s in rows)
        {
            Row row = new Row();
            foreach (string split in s.Split('\t'))
            {
                row.Numbers.Add(int.Parse(split));
                Console.WriteLine(int.Parse(split).ToString());
            }

            RowComputations(row);
            checksum += row.DivisionResult;
        }

        Console.WriteLine("The checksum is " + checksum + ".");
    }

    static void RowComputations(Row row)
    {
        row.FindDivisibleNumbers();
    }
}

public class Row
{
    List<int> numbers = new List<int>();
    int smallestNumber;
    int largestNumber;
    int difference;
    int divisionResult;

    public List<int> Numbers
    {
        set
        {
            numbers = value;
        }
        get
        {
            return numbers;
        }
    }

    public int SmallestNumber
    {
        set
        {
            smallestNumber = value;
        }
        get
        {
            return smallestNumber;
        }
    }

    public int LargestNumber
    {
        set
        {
            largestNumber = value;
        }
        get
        {
            return largestNumber;
        }
    }

    public int Difference
    {
        set
        {
            difference = value;
        }
        get
        {
            return difference;
        }
    }

    public int DivisionResult
    {
        set
        {
            divisionResult = value;
        }
        get
        {
            return divisionResult;
        }
    }

    public int FindSmallest()
    {
        SmallestNumber = Numbers[0];
        for (int i = 0; i < Numbers.Count; i++)
        {
            if (i == Numbers.Count-1)
            {
                if (Numbers[i] < SmallestNumber)
                {
                    SmallestNumber = Numbers[i];
                }
            }

            else if (Numbers[i] < SmallestNumber)
            {
                SmallestNumber = Numbers[i];
            }
        }
        return SmallestNumber;
    }

    public int FindLargest()
    {
        LargestNumber = Numbers[0];
        for (int i = 0; i < Numbers.Count; i++)
        {
            if (i == Numbers.Count - 1)
            {
                if (Numbers[i] > LargestNumber)
                {
                    LargestNumber = Numbers[i];
                }
            }

            else if (Numbers[i] > LargestNumber)
            {
                LargestNumber = Numbers[i];
            }
        }
        return LargestNumber;
    }

    public int FindDifference()
    {
        Difference = LargestNumber - SmallestNumber;
        return Difference;
    }

    public int FindDivisibleNumbers()
    {
        foreach (int i in numbers)
        {
            foreach (int j in numbers)
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
}
