
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        Row row1 = new Row();
        Row row2 = new Row();
        Row row3 = new Row();
        int checksum = 0;

        Console.WriteLine("Input the first row:");
        string firstRow = Console.ReadLine();

        foreach (char a in firstRow.ToCharArray())
        {
            row1.Numbers.Add((int)Char.GetNumericValue(a));
        }

        Console.WriteLine("Input the second row:");
        string secondRow = Console.ReadLine();

        foreach (char b in secondRow.ToCharArray())
        {
            row2.Numbers.Add((int)Char.GetNumericValue(b));
        }

        Console.WriteLine("Input the third row:");
        string thirdRow = Console.ReadLine();

        foreach (char c in thirdRow.ToCharArray())
        {
            row3.Numbers.Add((int)Char.GetNumericValue(c));
        }

        RowComputations(row1);
        RowComputations(row2);
        RowComputations(row3);

        Console.WriteLine("The first row's largest and smallest values are " + row1.LargestNumber + " and " +
            row1.SmallestNumber + ", and their difference is " + row1.Difference + ".\n");
        Console.WriteLine("The second row's largest and smallest values are " + row2.LargestNumber + " and " +
            row2.SmallestNumber + ", and their difference is " + row2.Difference + ".\n");
        Console.WriteLine("The third row's largest and smallest values are " + row3.LargestNumber + " and " +
            row3.SmallestNumber + ", and their difference is " + row3.Difference + ".\n");

        checksum = row1.Difference + row2.Difference + row3.Difference;

        Console.WriteLine("The checksum is " + row1.Difference + " + " + row2.Difference + " + " + row3.Difference +
            " = " + checksum + ".");
    }

    static void RowComputations(Row row)
    {
        row.FindLargest();
        row.FindSmallest();
        row.FindDifference();
    }
}

public class Row
{
    List<int> numbers = new List<int>();
    int smallestNumber;
    int largestNumber;
    int difference;

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
}
