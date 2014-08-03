#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


void perform_action(vector<bool> &locks)
{
    for(int i = 1; i < locks.size(); i += 2)
        locks[i] = true;
    
    for(int i = 2; i < locks.size(); i += 3)
        locks[i] = !locks[i];
}


int main(int argc, const char * argv[])
{
    ifstream fin;
    
    fin.open(argv[1]);
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            int N, M, total = 0;
            string line;
            
            getline(fin, line);
            if(line.empty())
                continue;
            
            stringstream ss(line);
            ss >> N >> M;
            vector<bool> locks(N, false);
            
            for(int i = 0; i < M - 1; i++)
                perform_action(locks);
            locks[locks.size() - 1] = !locks[locks.size() - 1];
            
            for(int i = 0; i < locks.size(); i++)
                if(!locks[i])
                    total++;
            
            cout << total << endl;
        }
        fin.close();
    }
    return 0;
}

