#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	bool flag = false;
	scanf("%d", &T);
	while (T--)
	{
		if (flag)
		{
			printf("\n");
		}
		else
		{
			flag = true;
		}

		int Case = 1;
		int n, m;
		while (scanf("%d %d", &n, &m) != EOF)
		{
			if (n == 0 && m == 0)
				break;

			int cnt = 0;
			for (int b = 2; b<n; b++)
			{
				for (int a = 1; a<b; a++)
				{
					if ((a*a + b * b + m) % (a*b) == 0)
						cnt++;
				}
			}

			printf("Case %d: %d\n", Case++, cnt);
		}
	}


	return 0;
}