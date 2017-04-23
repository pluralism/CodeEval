using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;


namespace CodeEval
{
    class Testing
    {
        static string FindBugs(string s1, string s2)
        {
            int count = 0;
            for (int i = 0; i < s1.Length; i++)
                if (s1[i] != s2[i]) count++;

            if (count > 6)
                return "Critical";
            else if (count == 0)
                return "Done";
            else if (count <= 2)
                return "Low";
            else if (count <= 4)
                return "Medium";

            return "High";
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

                    List<string> tmp = line.Split('|').ToList();
                    Console.WriteLine(FindBugs(tmp.First().Substring(0, tmp.First().Length - 1),
                        tmp.Last().Substring(1)));
                }
            }
        }
    }
}
