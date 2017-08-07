using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exerciseProjectCSharp
{
    class ApocalypseSimulation
    {
        static void Main()
        {            
            // introduce the user
            Console.WriteLine("Welcome to The Apocalypse Simulator!\nWe will be exploring one approach to population control" +
                               " that doesn't involve mandatory surgery!");

            StartSimulation:
            Console.WriteLine("Please enter simulation parameters.");
            Console.WriteLine("Enter the number of families:");

            int input = 0;
            while(true)
            {                
                // get number of families
                string number = Console.ReadLine();
                try
                {
                    Int32.TryParse(number, out input);
                    if (input <= 0)
                    {
                        Console.WriteLine("Error. Please enter a positive integer:");
                    }
                    else
                    {
                        break;
                    }
                }
                catch
                {
                    Console.WriteLine("Error. Please enter a positive integer:");
                }
            }

            // run the simulation with the given input
            // we're going to put 'input' number of integers (each integer
            // represents another family)
            // into a list and flip for either a boy or a girl
            // If it's a girl, then we dequeue the integer otherwise
            // we increment the count of boys and continue to the next
            // family. We repeat the process until all families
            // have flipped a girl. Note, we don't need to keep track
            // of the number of girls since by construction we should
            // have exactly one girl per family.
            // We use a random number generator to produce our coin flips

            bool[] families = new bool[input];
            for (int i = 0; i < input; ++i )
            {
                families[i] = false;
            }
            int totalBoys = 0;

            DateTime time = DateTime.Now;
            Random rnd = new Random((int)(time.Ticks % Int32.MaxValue));
            bool loop = true;
            while(loop)
            {
                int check = 0;
                for (int i = 0; i < input; ++i)
                {
                    // haven't already flipped a girl for this family yet
                    if(!families[i])
                    {
                        int flip = rnd.Next(1, 101);
                        if (flip <= 50)
                        {
                            // we got a girl, so 
                            // we remove the integer and
                            // continue
                            families[i] = true;
                        }
                        else
                        {
                            // we flipped a boy, we increment
                            // the count
                            ++totalBoys;
                        }
                    }
                    else
                    {
                        // count the number of girls that have been born
                        ++check;
                        if (check == input)
                            loop = false;
                    }
                    
                }
            }

            // print results
            Console.WriteLine("Results are as follows...");
            Console.WriteLine("Girls: " + input);
            Console.WriteLine("Boys: " + totalBoys);

            // prompt the user to repeat the simulation
            Console.WriteLine("Would you like to start the simulation again? (Y/N)");

            bool repeat = false;
            while (true)
            {
                // determine whether the user wants to continue or not
                string answer = Console.ReadLine();
                answer = answer.ToLower();
                if(answer.Equals("y"))
                {
                    // restart the simulation
                    repeat = true;
                    break;
                } else if (answer.Equals("n"))
                {
                    // exit simulation
                    repeat = false;
                    break;
                } 
                else
                {
                    Console.WriteLine("Error. Please enter either Y for Yes or N for No:");
                }
            }

            if(repeat)
            {
                goto StartSimulation;
            }


            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
