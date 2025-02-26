#include "L811_307.hpp"
#include <iostream>

using namespace std;

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