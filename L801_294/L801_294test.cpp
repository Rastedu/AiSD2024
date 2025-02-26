#include "L801_294.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

long fib_r(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;
    return fib_r(n-1) + fib_r(n-2);
}

vector<string> reading(const string& file)
{
    vector<string> lines;
    string line;
    ifstream in(file);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            lines.push_back(line);
        }
    }
    in.close();
    return lines;
}

int main () {
    cout<<fib_r(5)<<" and "<<fib_r(6);
    vector<string> text = reading("L801_294test.txt");
    for(string line : text)
    {
        cout<<fib_r(stoi(line));
    }
}