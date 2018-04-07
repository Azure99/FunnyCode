#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int Fa[30010];
int KArr[30010];
int Find(int x)
{
	int r = x;
	while (r != Fa[r])
	{
		r = Fa[r];
	}

	int t1 = x;
	int t2;
	while (t1 != Fa[t1])
	{
		t2 = Fa[t1];
		Fa[t1] = r;
		t1 = t2;
	}
	return r;
}

void Join(int x, int y)
{
	int Fx = Find(x);
	int Fy = Find(y);
	if (Fx != Fy)
	{
		Fa[Fy] = Fx;
	}
}

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		if (N == 0)
			break;
		scanf("%d", &M);

		for (int i = 0; i<N; i++)
			Fa[i] = i;

		int K;
		while (M--)
		{
			scanf("%d", &K);
			for (int i = 0; i<K; i++)
			{
				scanf("%d", &KArr[i]);
			}

			for (int i = 0; i<K - 1; i++)
			{
				Join(KArr[i], KArr[i + 1]);
			}
		}

		int ans = 0;
		int zero = Find(0);
		for (int i = 0; i<N; i++)
		{
			if (Find(i) == zero)
			{
				ans++;
			}
		}

		printf("%d\n", ans);
	}


	return 0;
}