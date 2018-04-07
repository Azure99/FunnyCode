#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<short, short> obj;

bool cmp(obj A, obj B)
{
    if(A.first==B.first)
        return A.second<B.second;
    else
        return A.first>B.first;
}

int main()
{
    obj Arr[10100];
    bool used[10100];
    int N, val, dl, p;
    while(scanf("%d", &N)!=EOF)
    {
        memset(used, 0, sizeof(used));
        memset(Arr, 0, sizeof(Arr));
        for(int i=0; i<N; i++)
        {
            scanf("%d %d", &Arr[i].first, &Arr[i].second);
        }
        sort(Arr, Arr+N, cmp);
        long long ans = 0;
        for(int i=0; i<N; i++)
        {
            int p = Arr[i].second;
            while(used[p])
                p--;

            if(p>=1)
            {
                used[p] = true;
                ans += Arr[i].first;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}