#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


void getPermutations(string s, int N, set<string> &tmp, string s2)
{
    if(s2.size() == N)
        tmp.insert(s2);
    else {
        for(int i = 0; i < s.size(); i++)
            getPermutations(s, N, tmp, s2 + s.substr(i, 1));
    }
}



int main(int argc, const char * argv[])
{
    ifstream fin;
    
    fin.open(argv[1]);
    while(!fin.eof())
    {
        string line, s;
        int N;
        getline(fin, line);
        
        if(line.empty())
            continue;
        
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        
        ss >> N >> s;
        set<string> stringSet;
        set<string>::iterator it;
        getPermutations(s, N, stringSet, "");
        string final = "";
        
        for(it = stringSet.begin(); it != stringSet.end(); it++)
        {
            final += (*it);
            if(it != stringSet.end())
                final += ",";
        }
        cout << final.substr(0, final.size() - 1) << endl;
    }
    fin.close();
    
    return 0;
}

