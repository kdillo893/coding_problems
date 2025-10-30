
class Functions
{

    ///<summary>
    /// Rolls 3 d6 and writes to console depending on the rolls.
    ///</summary>
    public static void DiceRoll()
    {
        Random dice = new Random();

        //make it a d6 roll-off instead
        int r1 = dice.Next(6) + 1;
        int r2 = dice.Next(6) + 1;
        int r3 = dice.Next(6) + 1;

        int total = r1 + r2 + r3;
        Console.WriteLine("random dice: {0} + {1} + {2} = {3}", r1, r2, r3, total);
        //rolling doubles (example of combination logic)
        if (r1 == r2 && r2 == r3)
        {
            Console.WriteLine("You rolled triples! +6");
            total += 6;
        }
        else if (r1 == r2 || r1 == r3 || r2 == r3)
        {
            Console.WriteLine("You rolled doubles! +2");
            total += 2;
        }

        Console.WriteLine("New Total:{0}", total);

        if (total >= 14)
        {
            Console.WriteLine("Nice Roll!");
        }
        else
        {
            Console.WriteLine("You didn't hit their AC!");
        }
    }

    /**
     * <summary>
     *  Return string containing text detailing how soon subscription will expire
     *  and any deals related to that.
     * </summary>
     */
    public static string? SubExpiryCheck()
    {



        return null;
    }
}
