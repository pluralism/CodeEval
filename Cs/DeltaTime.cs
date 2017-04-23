using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeEval
{
    class DeltaTime
    {
     
        static void CalcTimeDiff(DateTime s1, DateTime s2)
        {
            long diff = Math.Max(s1.Ticks, s2.Ticks) - Math.Min(s1.Ticks, s2.Ticks);
            Console.WriteLine(new DateTime(diff).ToString("HH:mm:ss"));
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

                    string[] arr = line.Split(' ').ToArray();
                    CalcTimeDiff(DateTime.Parse(arr.First()), DateTime.Parse(arr.Last()));
                }
            }
        }
    }
}
