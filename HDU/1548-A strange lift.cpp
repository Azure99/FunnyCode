#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int Arr[300];
int flag[300];
int N, A, B;

int bfs()
{
	typedef pair<int, int> status;
	queue<status> que;
	status f;
	f.first = A;
	f.second = 0;
	que.push(f);
	while (!que.empty())
	{
		status now = que.front();
		que.pop();

		if (flag[now.first - 1] == 1)
			continue;
		else
			flag[now.first - 1] = 1;

		if (now.first == B)
		{
			return now.second;
		}

		int up = now.first + Arr[now.first - 1];
		int down = now.first - Arr[now.first - 1];


		if (up <= N)
		{
			status New;
			New.first = up;
			New.second = now.second + 1;
			que.push(New);
		}

		if (down >= 1)
		{
			status New;
			New.first = down;
			New.second = now.second + 1;
			que.push(New);
		}
	}
	return -1;
}

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		if (N == 0)
			break;
		memset(Arr, 0, sizeof(Arr));
		memset(flag, 0, sizeof(flag));
		scanf("%d %d", &A, &B);
		for (int i = 0; i<N; i++)
		{
			scanf("%d", &Arr[i]);
		}
		int ans = bfs();
		printf("%d\n", ans);
	}
}
