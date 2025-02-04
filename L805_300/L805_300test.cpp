#include "L805_300.hpp"
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

string randv (string s, size_t val) // разделяй и властвуй; строка и номер слова
{
    vector<string> words;
    size_t start = 0;
    size_t end;
    while ((end = s.find(' ', start)) != string::npos) {
        words.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(s.substr(start));
    return words[val];
}

long binomial_coefficient(size_t n, size_t m)
{
    long bc[MAXN][MAXN];
    for (int i=0; i<=n; i++) bc[i][0] = 1;
    for (int j=0; j<=n; j++) bc[j][j] = 1;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<i; j++)
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
    return bc[n][m];
}

int main() {
    int n, m;
    cout<<"choose n"<<endl;
    cin>>n;
    cout<<"choose the number of coefficient"<<endl;
    cin>>m;
    cout<<binomial_coefficient(n,m);
    vector<string> text = reading("L805_300test.txt");
    for(string line : text)
    {
        cout<<binomial_coefficient(stoi(randv(line,1)), stoi(randv(line,2)));
    }
}