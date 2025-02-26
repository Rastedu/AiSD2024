#include "L810_306.hpp"
#include "L806_301.hpp"
#include "L807_302.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define MAXLEN 2 // Изменяемое значение, которое Скиена не задал в этом параграфе

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

typedef struct {
	int cost; /* Стоимость попадания в данную ячейку*/
	int parent; /* Родительская ячейка*/
} cell;

cell m[MAXLEN+1][MAXLEN+1];

void row_init (int i) //Изменён в L814_308.h
{
	m[0][i].cost=i;
	if (i>0)
		m[0][i].parent = INSERT;
	else
		m[0][i].parent = -1;
}

void column_init (int i)
{
	m[i][0].cost=i;
	if (i>0)
		m[i][0].parent = DELETE;
	else
		m[i][0].parent = -1;
}

int main() {
    for (size_t i=0; i<MAXLEN; ++i)
    {
        for (size_t j=0; j<MAXLEN; ++j)
        {
            m[i][j].cost=i+j;
        }
    }
    for (size_t i=0; i<MAXLEN; ++i)
    {
        row_init(i);
        column_init(i);
    }
	for (size_t i=0; i<MAXLEN; i++)
	{
		for (size_t j=0; j<MAXLEN; j++)
		{
			cout<<m[i][j].cost<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for (size_t i=0; i<MAXLEN; i++)
	{
		for (size_t j=0; j<MAXLEN; j++)
		{
			cout<<m[i][j].parent<<" ";
		}
		cout<<endl;
	}
}
