#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int Arr[130][130];

	for (int i = 0; i<N; i++)
	{
		for (int i2 = 0; i2<N; i2++)
		{
			scanf("%d", &Arr[i][i2]);
		}
	}
	long long ans = -99999999999;
	for (int i = 0; i<N; i++)
	{
		for (int i2 = 0; i2<N; i2++)
		{
			long long dp[130][130] = {};

			dp[i][i2] = Arr[i][i2];
			for (int i3 = i2 + 1; i3<N; i3++)
			{
				dp[i][i3] = Arr[i][i3] + dp[i][i3 - 1];
			}
			for (int i3 = i + 1; i3<N; i3++)
			{
				dp[i3][i2] = Arr[i3][i2] + dp[i3 - 1][i2];
			}

			for (int i3 = i + 1; i3<N; i3++)
			{
				long long dp2[130];
				dp2[i2] = Arr[i3][i2];
				for (int i4 = i2 + 1; i4<N; i4++)
				{
					dp2[i4] = dp2[i4 - 1] + Arr[i3][i4];
					dp[i3][i4] = dp[i3 - 1][i4] + dp2[i4];
					ans = max(ans, dp[i3][i4]);
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}