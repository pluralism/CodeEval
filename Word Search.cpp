#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


bool calculate(vector<vector<char>> grid, vector<vector<bool>> used, string word, int row, int col, int index)
{
    if(row < 0 || col < 0 || col > 3 || row > 2 || used[row][col])
        return false;
    
    if(grid[row][col] != word[index])
        return false;
    
    if(index == word.length() - 1)
        return true;
    
    used[row][col] = true;
    
    
    return calculate(grid, used, word, row + 1, col, index + 1) ||
    calculate(grid, used, word, row - 1, col, index + 1) ||
    calculate(grid, used, word, row, col + 1, index + 1) ||
    calculate(grid, used, word, row, col - 1, index + 1);
}



bool perform_main_operation(vector<vector<char>> grid, string word)
{
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[0].size(); j++)
        {
            vector<vector<bool>> used(4, vector<bool>(3, false));
            if(calculate(grid, used, word, i, j, 0))
                return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[])
{
    ifstream fin;
    vector<vector<char>> grid;
    vector<char> row1;
    vector<char> row2;
    vector<char> row3;
    row1.push_back('A');
    row1.push_back('B');
    row1.push_back('C');
    row1.push_back('E');
    grid.push_back(row1);
    
    row2.push_back('S');
    row2.push_back('F');
    row2.push_back('C');
    row2.push_back('S');
    grid.push_back(row2);
    
    row3.push_back('A');
    row3.push_back('D');
    row3.push_back('E');
    row3.push_back('E');
    grid.push_back(row3);
    
    fin.open(argv[1]);
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            string line;
            getline(fin, line);
            
            if(line.empty())
                continue;
            
            if(perform_main_operation(grid, line))
                cout << "True" << endl;
            else
                cout << "False" << endl;
        }
        fin.close();
    }
    return 0;
}

