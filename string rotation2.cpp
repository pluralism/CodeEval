#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


bool rotation(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
    if(s1 == s2)
        return true;
    
    for(int i = 0; i < s1.size(); i++)
    {
        string t(s1);
        rotate(t.begin(), t.begin() + i, t.end());
        if(t.compare(s2) == 0)
            return true;
    }
    
    return false;
}



int main(int argc, char * argv[])
{
    ifstream fin;
    
    fin.open(argv[1]);
    while(!fin.eof())
    {
        string line, s1, s2;
        getline(fin, line);
        
        if(line.empty())
            continue;
        
        replace(line.begin(), line.end(), ',', ' ');
        istringstream ss(line);
        ss >> s1 >> s2;
        
        if(rotation(s1, s2))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    
    fin.close();
    return 0;
}

