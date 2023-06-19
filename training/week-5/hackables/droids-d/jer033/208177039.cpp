#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long prefix[500005];
long long scratc[500005];//like a scratch paper that i use for a function and wipe clean every time

long long const mod = 998244353;

//NOTE TO HACKERS
//Congrats for finding this free hacking tip: Hack submission 207354654 (Problem F) by forcing it to use 128 bit integers

long long seq(int i, int j, long long prefix[500005], long long scratc[500005])
{
	scratc[j]=prefix[j];
	for (int k=j-1; k>=i-1; k--)
	{
		scratc[k]=min(prefix[k], scratc[k+1]);
	}
	long long ans=0;
	for (int k=i-1; k<=j; k++)
	{
		ans=min(ans, scratc[k]-prefix[k]);
	}
	return ans;
}

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=1; testcase<=t; testcase++)
	{
		cin >> n;
		prefix[0]=0;
		long long vi;
		for (int i=1; i<=n; i++)
		{
			cin >> vi;
			prefix[i]=prefix[i-1]+vi;
		}
		long long total=0;
		for (int i=1; i<=n; i++)
		{
			for (int j=i; j<=n; j++)
			{
				//cout << i << ' ' << j << ' ' << seq(i, j, prefix, scratc) << '\n';
				total+=seq(i, j, prefix, scratc);
				total=total%mod;
			}
		}
		total+=mod;
		total=total%mod;
		cout << total << '\n';
	}
}