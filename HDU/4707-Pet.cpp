#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, d;
int ans;
vector<int> vct[100010];

void dfs(int i, int cnt)
{
	if (cnt>d)
		ans++;

	for (int &v : vct[i])
	{
		dfs(v, cnt + 1);
	}
}

int main()
{
	int T, a, b;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d %d", &N, &d);
		for (int i = 0; i<N; i++)
			vct[i].clear();

		for (int i = 0; i<N - 1; i++)
		{
			scanf("%d %d", &a, &b);
			vct[a].push_back(b);
		}
		dfs(0, 0);
		printf("%d\n", ans);

	}
	return 0;
}