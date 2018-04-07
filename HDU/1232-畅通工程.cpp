#include <iostream>
#include <cstdio>
#include <cstring>
#pragma G++ optimize("O3")
using namespace std;

int Fa[1010];
int N, M;

int Find(int x)
{
    int r = x;
    while(Fa[r]!=r)
    {
        r = Fa[r];
    }

    int t1=x, t2;
    while(t1!=Fa[t1])
    {
        t2 = Fa[t1];
        Fa[t1] = r;
        t1 = t2;
    }
    return r;
}

void Join(int a, int b)
{
    int ax = Find(a);
    int bx = Find(b);
    if(ax!=bx)
    {
        Fa[bx] = ax;
    }
}

int main()
{
    while(scanf("%d", &N)!=EOF)
    {
        if(N==0)
            break;
        scanf("%d", &M);

        for(int i=1; i<=N; i++)
            Fa[i] = i;

        int a, b;
        for(int i=0; i<M; i++)
        {
            scanf("%d %d", &a, &b);
            Join(a, b);
        }
        int ans = 0;
        for(int i=1; i<=N; i++)
        {
            if(Fa[i]==i)
                ans++;
        }

        printf("%d\n", --ans);
    }

    return 0;
}