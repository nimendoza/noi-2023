#include <algorithm>
#include <iostream>
using namespace std;

long long his[500005];

int main()
{
	int t, n;
	cin >> t;
	long long d;
	for (int test=1; test<=t; test++)
	{
		cin >> n >> d;
		for (int i=1; i<=n; i++)
			cin >> his[i];
		long long best;
		//how sneaky is it that it says AT MOST ONCE
		//this section of the code is dedicated for just that
		//luckily, it's a convenient way to get 'best'
		long long maxi=0;
		long long mini=10000000000000;
		for (int k=1; k<=n; k++)
		{
			maxi=max(maxi, his[k]);
			mini=min(mini, his[k]);
		}
		best=maxi-mini;
		for (int i=1; i<=n; i++)
		{
			for (int j=i; j<=n; j++)
			{
				long long maxi=0;
				long long mini=10000000000000;
				for (int k=1; k<=n; k++)
				{
					if (k<i or k>j)
					{
						maxi=max(maxi, his[k]);
						mini=min(mini, his[k]);
					}
				}
				if (j-i<n-1)
				{
					best=min(best, maxi-mini+(j-i+1)*d);//should not need 128 bits
				}
			}
		}
		cout << best << '\n';
	}
}