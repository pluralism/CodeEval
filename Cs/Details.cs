using System;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeEval
{
    class Details
    {
        static int Difference(string s)
        {
            int r = int.MaxValue;
            MatchCollection matches = Regex.Matches(s, @"X\.*Y");
            foreach (Match match in matches)
                if (match.Value.Length - 2 < r)
                    r = match.Value.Length - 2;

            return r;
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = File.OpenText(args[0]))
            {
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();

                    if (line == null)
                        continue;

                    Console.WriteLine(Difference(line));
                }
            }
        }
    }
}
