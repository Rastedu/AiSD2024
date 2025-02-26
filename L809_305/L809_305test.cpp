#include "L806_301.hpp"
#include "L807_302.hpp"
#include "L809_305.hpp"
#include "L813_307.hpp" 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MATCH 0
#define DELETE 2
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

match_out(char *s, char *t, int i, int j);
insert_out(char *t, int j);
delete_out(char *s, int i);//эти три не на моей совести

reconstruct_path(char *s, char *t, int i, int j)
{
	if (m[i][j].parent == -1) return;
	if (m[i][j].parent == MATCH) {
		reconstruct_path(s, t, i-1, j-1);
		match_out(s, t, i, j);
		return;
	}
	if (m[i][j].parent == MATCH) {
		reconstruct_path(s, t, i, j-1);
		insert_out(t, j);
		return;
	}
	if (m[i][j].parent == DELETE) {
		reconstruct_path(s, t, i-1, j);
		delete_out(s, i);
		return;
	}
}

int main () {
    char* a="cr", b="lf";
    for (size_t i=0; i<MAXLEN; ++i)
    {
        for (size_t j=0; j<MAXLEN; ++j)
        {
            m[i][j].cost=i+j;
        }
    }
    cout<<string_compare(a, b);
    for (size_t i=0; i<MAXLEN; ++i)
    {
        for (size_t j=0; j<MAXLEN; ++j)
        {
            reconstruct_path(a,b,i,j);
        }
    }
    cout<<string_compare(a, b);

    vector<string> text = reading("L809_305test.txt");
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
        cout<<string_compare(a, b)<<endl;
        for (size_t i=0; i<MAXLEN; ++i)
        {
            for (size_t j=0; j<MAXLEN; ++j)
            {
                reconstruct_path(a,b,i,j);
            }
        }
        cout<<string_compare(a, b);
    }
    
}
