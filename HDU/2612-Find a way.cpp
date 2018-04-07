#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
char Arr[210][210];
int CArr[3][210][210];
int ed[210][210];
int YDx[] = { 0, 1, 0, -1 };
int YDy[] = { 1, 0, -1, 0 };

struct status
{
	pair<int, int> P;
	int cost;
};

void bfs(int n, int x, int y)
{
	memset(ed, 0, sizeof(ed));
	ed[x][y] = 1;
	queue<status> que;
	status F;
	F.P.first = x;
	F.P.second = y;
	F.cost = 0;
	que.push(F);
	while (que.size())
	{
		status now = que.front();
		que.pop();
		for (int i = 0; i<4; i++)
		{
			int newx = now.P.first + YDx[i];
			int newy = now.P.second + YDy[i];
			if (newx >= 0 && newx<N && newy >= 0 && newy<M && Arr[newx][newy] != '#' && ed[newx][newy] == 0)
			{
				status news;
				news.P.first = newx;
				news.P.second = newy;
				news.cost = now.cost + 11;
				ed[newx][newy] = 1;
				CArr[n][newx][newy] = news.cost;
				que.push(news);
			}
		}
	}
}

int main()
{
	while (scanf("%d %d", &N, &M) != EOF)
	{
		memset(CArr, 0, sizeof(CArr));
		memset(Arr, 0, sizeof(Arr));
		for (int i = 0; i<N; i++)
		{
			scanf("%s", &Arr[i]);
		}

		for (int i = 0; i<N; i++)
		{
			for (int i2 = 0; i2<M; i2++)
			{
				if (Arr[i][i2] == 'Y')
					bfs(0, i, i2);

				if (Arr[i][i2] == 'M')
					bfs(1, i, i2);
			}
		}

		int ans = 99999999;

		for (int i = 0; i<N; i++)
		{
			for (int i2 = 0; i2<M; i2++)
			{
				if (Arr[i][i2] == '@')
				{
					if (CArr[0][i][i2] == 0 || CArr[1][i][i2] == 0)
						continue;
					int cost = CArr[0][i][i2] + CArr[1][i][i2];
					ans = min(ans, cost);
				}
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}