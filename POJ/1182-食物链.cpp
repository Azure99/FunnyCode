#include <iostream>
#include <cstdio>

int Fat[50100];
int Rank[50100];

int Find(int x)
{
    if(x!=Fat[x])
    {
        int fx=Find(Fat[x]);
        Rank[x]=(Rank[x]+Rank[Fat[x]])%3;
        Fat[x]=fx;
    }
    return Fat[x];
}

int Join(int x, int y, int type)
{
    int fx = Find(x);
    int fy = Find(y);
    type--;
    if(fx == fy)
    {
        if((Rank[y]-Rank[x]+3)%3!=type)
            return 1;
        else
            return 0;
    }
    Fat[fy] = fx;
    Rank[fy] = (Rank[x]-Rank[y]+type+3) % 3;
    return 0;
}

int main()
{
    int N, K, t, x, y;
    scanf("%d %d", &N, &K);
    for(int i=0; i<=N; i++)
    {
        Fat[i] = i;
        Rank[i] = 0;
    }

    int wrong = 0;
    while(K--)
    {
        scanf("%d %d %d", &t, &x, &y);

        if(x>N || y>N)
            wrong++;
        else if(t==2 && x==y)
            wrong++;
        else
        {
            wrong += Join(x, y, t);
        }
    }
    printf("%d", wrong);
    return 0;
}