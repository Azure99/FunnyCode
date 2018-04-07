#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> ID;
map<int, string> Name;
vector<string> vct[2010];
vector<int> vct_i[2010];
int N, Q;
int cnt;

void solve(int index)
{
	int AnsCnt[2010] = {}, id;
	AnsCnt[index] = -9999;

	for (int &v : vct_i[index])
	{
		AnsCnt[v] = -9999;
		for (int &v2 : vct_i[v])
		{
			AnsCnt[v2]++;
		}
	}
	int Max = -1;
	for (int i = 1; i <= cnt; i++)
	{
		Max = max(Max, AnsCnt[i]);
	}
	if (Max == 0)
		cout << "-";
	else
	{
		vector<string> out;
		for (int i = 1; i <= cnt; i++)
		{
			if (AnsCnt[i] == Max)
			{
				out.push_back(Name[i]);
			}
		}
		sort(out.begin(), out.end());
		int s = out.size();
		for (int i = 0; i<s - 1; i++)
			cout << out[i] << ' ';
		cout << out[s - 1];
	}
	cout << endl;

}

int main()
{
	cin.sync_with_stdio(false);
	int Case = 1;
	int T;
	cin >> T;
	while (T--)
	{
		ID.clear();
		Name.clear();
		memset(vct, 0, sizeof(vct));
		memset(vct_i, 0, sizeof(vct_i));
		cnt = 1;
		cin >> N >> Q;
		while (N--)
		{
			string A, B;
			cin >> A >> B;

			if (!ID[A])
			{
				ID[A] = cnt;
				Name[cnt] = A;
				cnt++;
			}

			if (!ID[B])
			{
				ID[B] = cnt;
				Name[cnt] = B;
				cnt++;
			}

			int id1 = ID[A];
			int id2 = ID[B];
			vct[id1].push_back(B);
			vct_i[id1].push_back(id2);
			vct[id2].push_back(A);
			vct_i[id2].push_back(id1);
		}
		cout << "Case " << Case << ':' << endl;
		Case++;
		while (Q--)
		{
			string obj;
			cin >> obj;
			solve(ID[obj]);
		}
	}

	return 0;
}
