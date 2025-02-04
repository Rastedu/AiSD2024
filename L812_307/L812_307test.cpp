#include "L812_307.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

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

void goal_cell(char *s, char *t, int i, int j) //Изменён в L814_308.h
{
	i = strlen(s)-1;
	j = strlen(t)-1;
}

int main() {
    char* a="cr", *b="lf";
    int i=0, j=0;
    goal_cell(a, b, &i, &j);
    cout<<a[i]<<" "<<b[j];
}