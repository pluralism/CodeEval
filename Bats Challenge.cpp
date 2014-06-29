#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int number_of_bats(int start, int end, int spacing, bool cond)
{
    if(cond)
        return (end - start) / spacing - 1;
    return (end - start) / spacing;
}


int main(int argc, char * argv[])
{
    ifstream fin;
    
    fin.open(argv[1]);
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            string line;
            getline(fin, line);
            if(line.empty())
                continue;
            
            stringstream ss(line);
            vector<int> elements;
            int tmp;
            while(ss >> tmp)
                elements.push_back(tmp);
             
            int start = 6,
            final = elements[0] - 6,
            spacing_between_bats = elements[1],
            total_bats = 0,
            bats_on_wire = elements[2];
            
            if(bats_on_wire > 1)
            {
                total_bats += number_of_bats(start, elements[3], spacing_between_bats, false);
                for(int i = 3; i < elements.size() - 1; i++)
                    total_bats += number_of_bats(elements[i], elements[i + 1], spacing_between_bats, true);
                total_bats += number_of_bats(elements[elements.size() - 1], final, spacing_between_bats, false);
                
                cout << (total_bats < 0 ? 0 : total_bats) << endl;
            } else if(bats_on_wire == 1)
            {
                total_bats += number_of_bats(start, elements[3], spacing_between_bats, false);
                total_bats += number_of_bats(elements[3], final, spacing_between_bats, false);
                cout << (total_bats < 0 ? 0 : total_bats) << endl;
            } else if(bats_on_wire == 0)
                cout << (final - start) / spacing_between_bats + 1 << endl;
        }
        fin.close();
    }
    return 0;
}


