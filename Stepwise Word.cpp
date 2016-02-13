#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


string getLongestWord(string s) {
    string longest = "";
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp, ' '))
        if(tmp.length() > longest.length())
            longest = tmp;

    return longest;
}


int main(int argc, char *argv[]) {
    ifstream fin;

    fin.open(argv[1]);
    while(!fin.eof())
    {
        string line;
        getline(fin, line);

        if(line.empty())
            continue;

        string longestWord = getLongestWord(line);
        int stars = 0;
        for(int i = 0; i < longestWord.size(); i++) {
            for(int j = 0; j < stars; j++)
                cout << "*";
                stars++;
            cout << longestWord[i] << (i == longestWord.length() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}