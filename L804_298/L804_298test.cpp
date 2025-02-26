#include "L804_298.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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

long fib_ultimate(int n) 
{
    long back2=0, back1=1;
    long next;
    if (n==0) return 0;
    for (int i=2; i<n; i++) {
        next = back2+back1;
        back2 = back1;
        back1 = next;
    }
    return back1 + back2;
}

int main () {
    cout<<fib_ultimate(5);
    vector<string> text = reading("L804_298test.txt");
    for(string line : text)
    {
        cout<<fib_ultimate(stoi(line));
    }
}