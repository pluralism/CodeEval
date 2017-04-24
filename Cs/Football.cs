using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeEval
{
    class Football
    {
        static string CalcFootball(string s)
        {
            string r = "";
            Dictionary<int, List<int>> dict = new Dictionary<int, List<int>>();
            List<string> arr = s.Split('|').ToList().Select(t => t.Trim()).ToList();

            for(int i = 0; i < arr.Count; i++)
            {
                List<int> nums = arr[i].Split(' ').ToList().Select(n => Int32.Parse(n)).ToList();
                foreach(int n in nums)
                {
                    if (!dict.ContainsKey(n))
                        dict[n] = new List<int>();
                    dict[n].Add(i + 1);
                }
            }

            foreach(int n in dict.Keys.OrderBy(t => t).ToList())
                r += $"{n}:{String.Join(",", dict[n])}; ";

            return r.Trim();
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

                    Console.WriteLine(CalcFootball(line));
                }
            }
        }
    }
}
