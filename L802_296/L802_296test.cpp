#include "L802_296.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAXN 45
#define UNKNOWN -1

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

long f[MAXN+1];

long fib_c(size_t n)
{
    if (f[n] == UNKNOWN)
    f[n] = fib_c(n-1) + fib_c(n-2);
    return f[n];
}

long fib_c_driver(int n)
{
    f[0] = 0;
    f[1] = 1;
    for (int i=2; i<=n; i++) f[i]=UNKNOWN;
    return fib_c(n);
}

int main () {
    cout<<fib_c_driver(5);
    vector<string> text = reading("L802_296test.txt");
    for(string line : text)
    {
        cout<<fib_c_driver(stoi(line));
    }
}