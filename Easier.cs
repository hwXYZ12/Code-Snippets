using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace exerciseProjectCSharp
{
    class Easier
    {
        private const string fileName = "C:\\Users\\William\\Desktop\\Easier\\easier.txt";
        private const string someFile = "C:\\Users\\William\\Desktop\\Easier\\debug.txt";

        static int Main()
        {
            Console.WriteLine("Please enter an integer or type 'next' to use the next integer in the series: ");
            bool gotInput = false, useNext = false;
            int x = 0;
            while(!gotInput)
            {
                try
                {
                    string line = Console.ReadLine();
                    if(line.Equals("next"))
                    {
                        // do stuff
                        gotInput = true;
                        useNext = true;
                    }
                    else
                    {
                        x = Int32.Parse(line);
                        gotInput = true;
                    }
                }
                catch
                {
                    Console.WriteLine("Please enter an integer!");
                }
            }

            // open the file in its current state
            // then we're going to parse it into memory and search for any instance
            // of Eulerxxx and replace those instance with Euleryyy where yyy is either
            // xxx+1 if the user selected 'next' or the int x that we retrieved from the user
            try
            {
                string newContents = null;
                using (StreamReader sr = new StreamReader(fileName))
                {
                    string contents = sr.ReadToEnd();
                    string working = contents;
                    newContents = contents;
                    
                    // parse the contents of the file for 'Euler', anywhere that this occurs
                    // we will replace it with another expression
                    
                    int start = contents.IndexOf("Euler");
                    int newVal = x;
                    while(start != -1)
                    {
                        start += 5;
                        if(useNext)
                        {
                            newVal = Int32.Parse(contents.Substring(start, 3)) + 1;
                        }

                        // padding
                        string s = "";
                        if (newVal < 10)
                        {
                            s = "00" + newVal;
                        } else if (newVal < 100)
                        {
                            s = "0" + newVal;
                        }
                        else
                        {
                            s = ""+newVal;
                        }

                        newContents = newContents.Substring(0, start) + s + newContents.Substring(start + 3);

                        // ready the next portion of the loop
                        working = contents.Substring(start);
                        if (working.IndexOf("Euler") == -1)
                        {
                            start = -1;
                        }
                        else
                        {
                            start += working.IndexOf("Euler");
                        }
                    }
                    sr.Close();
                }

                // once we've got a representation of the new contents of the file
                // we write it all back to the file
                using (StreamWriter sw = new StreamWriter(fileName))
                {
                    sw.Write(newContents);
                    Console.WriteLine("File successfully updated.");
                    sw.Close();
                }


            } catch (Exception e){
                Console.WriteLine("A fatal error has occurred.");
                Console.WriteLine(e.Message);
            }

            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
            return 0;
        }
    }
}