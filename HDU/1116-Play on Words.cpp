#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int IN[30];
int OUT[30];
int Fu[30];
bool exist[30];
int t[30];

int Find(int x)
{
	int r = x;
	while (Fu[r] != r)
		r = Fu[r];

	int t1 = x;
	int t2;
	while (Fu[t1] != t1)
	{
		t2 = Fu[t1];
		Fu[t1] = r;
		t1 = t2;
	}
	return r;
}

int Join(int x, int y)
{
	int Fx = Find(x);
	int Fy = Find(y);
	if (Fx != Fy)
		Fu[Fy] = Fx;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(IN, 0, sizeof(IN));
		memset(OUT, 0, sizeof(OUT));
		memset(exist, 0, sizeof(exist));
		memset(t, 0, sizeof(t));
		for (int i = 0; i <= 26; i++)
			Fu[i] = i;

		int N;
		scanf("%d", &N);
		for (int i = 0; i<N; i++)
		{
			char word[1010];
			scanf("%s", &word);
			char x = word[0];
			char y = word[strlen(word) - 1];

			Join(x - 'a', y - 'a');
			IN[x - 'a']++;
			OUT[y - 'a']++;
			exist[x - 'a'] = true;
			exist[y - 'a'] = true;
		}

		int cnt = 0;
		for (int i = 0; i<26; i++)
		{
			Fu[i] = Find(i);
			if (exist[i])
			{
				if (Fu[i] == i)
					cnt++;
			}
		}

		if (cnt>1)
		{
			printf("The door cannot be opened.\n");
		}
		else
		{
			int noeq = 0;
			for (int i = 0; i<26; i++)
			{
				if (exist[i])
				{
					if (IN[i] != OUT[i])
					{
						t[noeq] = i;
						noeq++;
					}
				}
			}
			if (noeq == 0)
			{
				printf("Ordering is possible.\n");
			}
			else
			{
				if (!(noeq == 2))
				{
					printf("The door cannot be opened.\n");
				}
				else
				{
					if (OUT[t[0]] - IN[t[0]] == 1 && IN[t[1]] - OUT[t[1]] == 1)
					{
						printf("Ordering is possible.\n");
					}
					else if (OUT[t[1]] - IN[t[1]] == 1 && IN[t[0]] - OUT[t[0]] == 1)
					{
						printf("Ordering is possible.\n");
					}
					else
					{
						printf("The door cannot be opened.\n");
					}
				}


			}
		}
	}
	return 0;
}