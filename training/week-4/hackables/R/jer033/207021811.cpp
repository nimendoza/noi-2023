#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int ansfory[5015];
int vis[105];//value
int cis[105];//cost

int main()
{
	int t, n, d;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n >> d;
		ansfory[0]=0;
		for (int i=0; i<n; i++)
		{
			cin >> vis[i] >> cis[i];
		}
		for (int i=1; i<=d; i++)
		{
			int best=35000001;
			for (int j=0; j<n; j++)
			{
				if (i>=vis[j])
				{
					best=min(best, cis[j]+ansfory[i-vis[j]]);
				}
				else
				{
					best=min(best, cis[j]);
				}
			}
			ansfory[i]=best;
		}
		cout << ansfory[d] << '\n';
	}
}