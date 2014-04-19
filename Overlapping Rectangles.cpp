#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


class Point {
    int x, y;
    
public:
    Point(int x, int y);
    int getX();
    int getY();
};


Point::Point(int x, int y) :
    x(x), y(y)
{
    
}


int Point::getX()
{
    return x;
}


int Point::getY() {
    return y;
}



int main(int argc, char * argv[])
{
    ifstream fin;
    
    fin.open(argv[1]);
    while(!fin.eof())
    {
        string line;
        getline(fin, line);
        
        if(line.empty())
            continue;
        
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        int x1, y1, x2, y2, x3, y3, x4, y4;
        ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point p1 = Point(x1, y1);
        Point p2 = Point(x2, y2);
        Point p3 = Point(x3, y3);
        Point p4 = Point(x4, y4);
        
        if(min(p1.getX(), p2.getX()) <= max(p3.getX(), p4.getX()) && max(p1.getX(), p2.getX()) >= min(p3.getX(), p4.getX()) && max(p1.getY(), p2.getY()) >= min(p3.getY(), p4.getY()) && min(p1.getY(), p2.getY()) <= max(p3.getY(), p4.getY()))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    
    fin.close();
    return 0;
}

