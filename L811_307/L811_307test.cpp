#include "L811_307.hpp"
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

int match(char c, char d)
{
	if (c==d) return 0;
	else return 1;
}

int indel (char c)
{
	return 1;
}

int main() {
    char a='a', b='b', c='c';
    cout<<match(a,b)<<match(c,c);
    cout<<"\n"<<indel(a);
}