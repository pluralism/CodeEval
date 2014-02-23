#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
  ifstream fin;
  
  fin.open(argv[1]);
  while(!fin.eof())
  {
    string line, longest = "";
    getline(fin, line);
    
    if(line.empty())
      continue;
    
    //Build all the suffixes
    vector<string> suffs;
    for(int i = 0; i < line.length(); i++)
      suffs.push_back(line.substr(i, line.length()));
    
    //Sort the suffixes
    sort(suffs.begin(), suffs.end());
  }
  
  fin.close();
  return 0;
}