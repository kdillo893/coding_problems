//System is often included without explicit definition, I don't know other namespaces to include.
using System;
using static Functions;

internal class Program
{
    private static void Main(string[] args)
    {
        // Using random library from standard
        Random dice = new();
        int roll = dice.Next(1, 7);
        Console.WriteLine("Random result=" + roll);

        //overloaded random 
        int r1 = dice.Next();
        int r2 = dice.Next(89);
        int r3 = dice.Next(1, 11);

        Console.WriteLine("Random any: {0}, Random 0 to 89 excl: {1}, Random 1 to 10: {2}", r1, r2, r3);

        roll = dice.Next(0, 10);
        Console.WriteLine("Random result=" + roll);

        Functions.DiceRoll();

        Functions.SubExpiryCheck();

        //integer math
        int firstValue = 500;
        int secondValue = 600;
        int largerValue = Math.Max(firstValue, secondValue);

        Console.WriteLine($"Larger value={largerValue}");

        //string and comparisons
        string message = "The quick brown fox jumped over the lazy dog.";
        bool hasDog = message.Contains("dog",
            StringComparison.OrdinalIgnoreCase);

        if (hasDog)
        {
            Console.WriteLine($"the line \"{message}\" has the word \"dog\" in it!");
        }
    }
}
