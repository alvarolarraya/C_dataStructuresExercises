#include <stdio.h>
#define N 6
typedef enum {FALSE= 0, TRUE= 1} boolean;
typedef int tabla[N+1];
int x;
boolean calcula_A(int tabla[N], int x);
boolean calcula_A(int tabla[N], int x)
{
    int y;
    boolean b;
    y = x+1;
    while ((y<N) && (tabla[x]!=tabla[y]))
        y = y+1;
    b = t[x] == t[y];
    return b;
}
int main(void)
{
    int z;
    boolean r;
    x = 0;
    z = calcula_A(t,0);
    r = t[x]==t[l];
    while (x<N-1 && r==1)
        z = calcula_A(t,x+1);
        
}
