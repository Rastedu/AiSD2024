#include "L812_307.hpp"
#include "L807_302.hpp"
#include "L811_307.hpp"
#include "L806_301.hpp"
#include "L808_303.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 10 // Изменяемое значение, которое Скиена не задал в этом параграфе

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

typedef struct {
	int cost; /* Стоимость попадания в данную ячейку*/
	int parent; /* Родительская ячейка*/
} cell;

cell m[MAXLEN+1][MAXLEN+1];

void goal_cell(char *s, char *t, int *i, int *j) //Изменён в L814_308.h
{
	*i = strlen(s)-1;
	*j = strlen(t)-1;
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

int string_compare(char *s, char *t)
{
	int i, j, k;
	int opt[3];
	for (size_t i=0; i<strlen(s); i++) {
		for (size_t j=0; j<strlen(t); j++) {
			opt[MATCH] = m[i-1][j-1].cost + match(s[i],t[i]);
			opt[INSERT] = m[i][j-1].cost + indel(t[j]);
			opt[DELETE] = m[i-1][j].cost + indel(s[i]);
			m[i][j].cost = opt[MATCH];
			m[i][j].parent = MATCH;
			for (size_t k=INSERT; k<=DELETE; k++)
				if (opt[k] < m[i][j].cost) {
					m[i][j].cost = opt[k];
					m[i][j].parent = k;
				}
		}
	}
	goal_cell(s, t, &i, &j);
	return (m[i][j].cost);
}

int main () {
    char* a="cr";
    char* b="lf";
    for (size_t i=0; i<MAXLEN; ++i)
    {
        for (size_t j=0; j<MAXLEN; ++j)
        {
            m[i][j].cost=i+j;
        }
    }
    cout<<string_compare(a, b);
	vector<string> text = reading("L808_303test.txt");
	for (size_t i=0; i<MAXLEN; ++i)
    {
        for (size_t j=0; j<MAXLEN; ++j)
        {
            m[i][j].cost=i+j;
        }
    }
    for(string line : text)
    {
        char *a,*b;
        strcpy(a, randv(line, 1).c_str());
        strcpy(b, randv(line, 2).c_str());
        cout<<string_compare(a, b);
    }
}