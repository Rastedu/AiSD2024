#include "L811_307.hpp"
#include "L806_301.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define MATCH 0
#define INSERT 1
#define DELETE 2

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

int match(char c, char d)
{
	if (c==d) return 0;
	else return 1;
}

int indel (char c)
{
	return 1;
}

int string_compare(char *s, char *t, int i, int j)
{
    int opt[3];
    int lowest_cost;
    if (i==0) return j*indel(' ');
    if (j==0) return i*indel(' ');
    opt[MATCH] = string_compare(s, t, i-1, j-1) + match(s[i], t[j]);
    opt[INSERT] = string_compare(s, t, i, j-1) + indel(t[j]);
    opt[DELETE] = string_compare(s, t, i-1, j) + indel(s[i]);
    lowest_cost = opt[MATCH];
    for (int k=INSERT; k<=DELETE; k++)
        if (opt[k] < lowest_cost) lowest_cost = opt[k];
        return lowest_cost;
}

int main () {
    /*ghtlcnfdbv? xnj pltcm rjl*/
    vector<string> text = reading("L806_301test.txt");
    for(string line : text)
    {
        char *a,*b;
        strcpy(a, randv(line, 1).c_str());
        strcpy(b, randv(line, 2).c_str());
        cout<<string_compare(a, b, strlen(a), strlen(b));
    }
}