#include "L807_302.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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

typedef struct {
	int cost; /* Стоимость попадания в данную ячейку*/
	int parent; /* Родительская ячейка*/
} cell;

int main () {
	cell m[MAXLEN+1][MAXLEN+1]; /* Таблица динамического программирования*/
    m[0][0].cost   = 1;
    m[0][0].parent = 2;
    cout<<m[0][0].cost<<" () "<<m[0][0].parent;
}
