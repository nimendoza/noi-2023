#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long regulard[100005];
long long droideka[100005];
long long dp[4005][8009];

int main()
{
	int t, n, k;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n >> k;
		long long holder;
		for (int i=0; i<n; i++)
		{
			cin >> holder;
			regulard[i]=holder;
		}
		for (int i=0; i<n; i++)
		{
			cin >> holder;
			droideka[i]=regulard[i]+holder;
		}
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<=2*n; j++)
			{
				if (i==0)
				{
					if (j==0)
						dp[i][j]=0;
					else if (j==1)
						dp[i][j]=regulard[0];
					else
						dp[i][j]=droideka[0];
				}
				else
				{
					long long best=dp[i-1][j];
					if (j>=1)
						best=max(best, dp[i-1][j-1]+regulard[i]);
					if (j>=2)
						best=max(best, dp[i-1][j-2]+droideka[i]);
					dp[i][j]=best;
				}
			}
		}
		cout << dp[n-1][k] << '\n';
	}
}