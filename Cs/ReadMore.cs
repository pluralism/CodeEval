using System;
using System.IO;


namespace CodeEval
{
    class ReadMore
    {
        static string ReadMoreAction(string s)
        {
            if (s.Length <= 55)
                return s;

            string tmp = s.Substring(0, 40);
            tmp = tmp.Substring(0, tmp.LastIndexOf(' ') != -1 ?
                tmp.LastIndexOf(' ') : tmp.Length);

            return tmp + "... <Read More>";
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = File.OpenText(args[0]))
            {
                while(!reader.EndOfStream)
                {
                    string line = reader.ReadLine();

                    if (line == null)
                        continue;

                    Console.WriteLine(ReadMoreAction(line));
                }
            }
        }
    }
}
