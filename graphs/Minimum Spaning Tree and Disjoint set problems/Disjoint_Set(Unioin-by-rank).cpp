#include <iostream>
#include <vector>

using namespace std;

int find(int par[], int x)
{
    int c = 0;
    if (par[x] == x)
        return x;
    else
    {
        c = par[x];
        while (par[c] != c)
        {
            c = par[c];
        }
    }
    return c;
}

void unionSet(int par[], int x, int z)
{
    int c = 0, d = 0;

    c = par[x];
    while (par[c] != c)
    {
        c = par[c];
    }
    d=par[z];
    while(par[d]!=d){
        d=par[d];
    }
    par[c]=d;
}

int main()
{

    return 0;
}