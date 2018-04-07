#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool vst[102][102][102];

struct sts
{
	short S;
	short N;
	short M;
	int cnt;
};

int bfs(int S, int N, int M)
{
	int mid = S / 2;
	memset(vst, 0, sizeof(vst));
	queue<sts> que;
	sts f;
	f.S = S;
	f.N = 0;
	f.M = 0;
	f.cnt = 0;
	que.push(f);
	while (!que.empty())
	{
		sts now = que.front();
		que.pop();

		if (vst[now.S][now.N][now.M])
			continue;

		vst[now.S][now.N][now.M] = true;

		if ((now.S == mid && now.M == mid) || (now.S == mid && now.N == mid) || (now.N == mid && now.M == mid))
		{
			return now.cnt;
		}

		if (now.S != 0)
		{
			if (now.N<N)
			{
				sts news;
				news.cnt = now.cnt + 1;
				news.M = now.M;

				if (now.S<(N - now.N))
				{
					news.S = 0;
					news.N = now.N + now.S;
				}
				else
				{
					news.S = now.S - (N - now.N);
					news.N = N;
				}
				que.push(news);
			}

			if (now.M<M)
			{
				sts news;
				news.cnt = now.cnt + 1;
				news.N = now.N;

				if (now.S<(M - now.M))
				{
					news.S = 0;
					news.M = now.M + now.S;
				}
				else
				{
					news.S = now.S - (M - now.M);
					news.M = M;
				}
				que.push(news);
			}
		}
		//------------------------------------------------------

		if (now.N != 0)
		{
			if (now.S<S)
			{
				sts news;
				news.cnt = now.cnt + 1;
				news.M = now.M;

				if (now.N<(S - now.S))
				{
					news.N = 0;
					news.S = now.S + now.N;
				}
				else
				{
					news.N = now.N - (S - now.S);
					news.S = S;
				}
				que.push(news);
			}

			if (now.M<M)
			{
				sts news;
				news.cnt = now.cnt + 1;
				news.S = now.S;

				if (now.N<(M - now.M))
				{
					news.N = 0;
					news.M = now.M + now.N;
				}
				else
				{
					news.N = now.N - (M - now.M);
					news.M = M;
				}
				que.push(news);
			}
		}
		//-------------------------------------------

		if (now.M != 0)
		{
			if (now.S<S)
			{
				sts news;
				news.cnt = now.cnt + 1;
				news.N = now.N;

				if (now.M<(S - now.S))
				{
					news.M = 0;
					news.S = now.M + now.S;
				}
				else
				{
					news.M = now.M - (S - now.S);
					news.S = S;
				}
				que.push(news);
			}

			if (now.N<N)
			{
				sts news;
				news.cnt = now.cnt + 1;
				news.S = now.S;

				if (now.M<(N - now.N))
				{
					news.M = 0;
					news.N = now.N + now.M;
				}
				else
				{
					news.M = now.M - (N - now.N);
					news.N = N;
				}
				que.push(news);
			}
		}

	}
	return -1;
}

int main()
{
	int S, N, M;
	while (cin >> S >> N >> M)
	{
		if (S == 0 && N == 0 && M == 0)
			break;

		if (S % 2 == 1)
		{
			cout << "NO" << endl;
			continue;
		}

		if (N>M)
			swap(N, M);

		int ans = bfs(S, N, M);
		if (ans == -1)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
}