#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Arr[1000000];

int main()
{
	int Case = 1;
	int Z, I, M, L;
	while (scanf("%d %d %d %d", &Z, &I, &M, &L) != EOF)
	{
		if (Z == 0 && I == 0 && L == 0 && M == 0)
			break;

		int c = 0;
		int two = -1;
		int three = -1;
		memset(Arr, 0, sizeof(Arr));
		while (true)
		{
			L = (Z*L + I) % M;
			Arr[L]++;
			c++;
			if (Arr[L] == 2 && two == -1)
				two = c;

			if (Arr[L] == 3 && three == -1)
			{
				three = c;
				break;
			}
		}
		printf("Case %d: %d\n", Case++, three - two);
	}
}