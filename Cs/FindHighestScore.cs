using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeEval
{
    class FindHighestScore
    {
        static string HighestScore(string s)
        {
            string res = "";
            List<List<int>> t = new List<List<int>>();

            foreach(string line in s.Split('|'))
                t.Add(line.Split(' ').Where(ss => ss.Length > 0).ToList().
                    Select(n => Convert.ToInt32(n)).ToList());

            for(int i = 0; i < t[0].Count(); i++)
                res += t.Select(n => n[i]).ToList().Max() + " "; 

            return res.Trim();
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


                    Console.WriteLine(HighestScore(line));
                }
            }
        }
    }
}
