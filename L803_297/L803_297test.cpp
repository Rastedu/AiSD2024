#include "L802_296.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define MAXN 45

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

long fib_dp (int n) 
{
    long f[MAXN+1];
    f[0] = 0;
    f[1] = 1;
    for (int i=2; i<=n; i++) f[i]=f[i-1]+f[i-2];
    return f[n];
}

int main () {
    cout<<fib_dp(5);
    vector<string> text = reading("L803_297test.txt");
    for(string line : text)
    {
        cout<<fib_dp(stoi(line));
    }
}