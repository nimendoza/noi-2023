#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int ansforx[5015];
int vis[105];//value
int cis[105];//cost

int main()
{
	int t, n, d;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n >> d;
		ansforx[0]=0;
		for (int i=0; i<n; i++)
		{
			cin >> vis[i] >> cis[i];
		}
		for (int i=1; i<=d; i++)
		{
			int best=0;
			for (int j=0; j<n; j++)
			{
				if (i>=cis[j])
				{
					best=max(best, vis[j]+ansforx[i-cis[j]]);
				}
			}
			ansforx[i]=best;
		}
		cout << ansforx[d] << '\n';
	}
}