#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

char Map[55][55][55];
bool vis[55][55][55];

int YDx[] = { 1, -1, 0, 0, 0, 0 };
int YDy[] = { 0, 0, 1, -1, 0, 0 };
int YDz[] = { 0, 0, 0, 0, 1, -1 };

int A, B, C, T;

struct sts
{
	int x;
	int y;
	int z;
	int cnt;
};

void bfs()
{
	queue<sts> que;
	sts f;
	f.x = 0;
	f.y = 0;
	f.z = 0;
	f.cnt = 0;
	que.push(f);
	while (!que.empty())
	{
		sts now = que.front();
		que.pop();
		if (now.x == B - 1 && now.y == C - 1 && now.z == A - 1)
		{
			printf("%d\n", now.cnt);
			return;
		}

		for (int i = 0; i<6; i++)
		{
			int newx = now.x + YDx[i];
			int newy = now.y + YDy[i];
			int newz = now.z + YDz[i];

			if (newx >= 0 && newx<B && newy >= 0 && newy<C && newz >= 0 && newz<A && Map[newz][newx][newy] == '0' && !vis[newz][newy][newx])
			{
				sts news;
				news.x = newx;
				news.y = newy;
				news.z = newz;
				news.cnt = now.cnt + 1;
				if (news.cnt <= T)
				{
					que.push(news);
					vis[newz][newy][newx] = true;
				}
			}

		}

	}

	printf("-1\n");
}

int main()
{
	int K;
	scanf("%d", &K);
	while (K--)
	{
		memset(Map, 0, sizeof(Map));
		memset(vis, 0, sizeof(vis));
		scanf("%d %d %d %d", &A, &B, &C, &T);
		getchar();
		for (int i = 0; i<A; i++)
		{
			for (int i2 = 0; i2<B; i2++)
			{
				for (int i3 = 0; i3<C; i3++)
				{
					Map[i][i2][i3] = getchar();
					getchar();
				}
			}
		}

		bfs();
	}
	return 0;
}