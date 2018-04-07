#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int NextA[1200];
char IP[1200];
char obj[1200];

void InitNext()
{
	NextA[0] = -1;
	int i = 0;
	int j = -1;
	int len = strlen(obj);
	while (i < len)
	{
		if (j == -1 || obj[i] == obj[j])
			NextA[++i] = ++j;
		else
			j = NextA[j];
	}
}

int KMP(char IP[], char obj[], int start)
{
	int IPlen = strlen(IP);
	int objlen = strlen(obj);
	int i = start;
	int j = 0;
	while (i<IPlen && j<objlen)
	{
		if (j == -1 || IP[i] == obj[j])
		{
			i++;
			j++;
		}
		else
		{
			j = NextA[j];
		}
	}

	if (j == objlen)
		return i - j;
	else
		return -1;
}

int main()
{
	while (scanf("%s", IP) != EOF)
	{
		if (IP[0] == '#')
			break;
		scanf("%s", obj);
		int objlen = strlen(obj);
		InitNext();
		int cnt = 0;
		int p = KMP(IP, obj, 0);
		while (p != -1)
		{

			cnt++;
			p = KMP(IP, obj, p + objlen);
		}
		printf("%d\n", cnt);
		memset(IP, 0, sizeof(IP));
		memset(obj, 0, sizeof(obj));
		memset(NextA, 0, sizeof(NextA));
	}
	return 0;
}