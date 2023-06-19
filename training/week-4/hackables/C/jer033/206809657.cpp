#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long lengths[270000];

int check(int n, long long lengths[270000], long long c, long long k)
{
	long long count=0;
	for (int i=0; i<n; i++)
	{
		count+=(lengths[i]-1)/k;
	}
	if (count <= c)
		return 1;
	return 0;
}

int main()
{
	int t, n;
	long long c;
	cin >> t;
	for (int testcase=1; testcase<=t; testcase++)
	{
		cin >> n >> c;
		for (int i=0; i<n; i++)
		{
			cin >> lengths[i];
		}
		long long lo = 1;
		long long hi = 1073741824;
		//cout << hi+hi << '\n';
		//check for the smallest k that works
		long long mid;
		while (hi!=lo)
		{
			//cout << hi << ' ' << lo << '\n';
			mid=(hi+lo)/2;
			if (check(n, lengths, c, mid))
			{
				hi=mid;
			}
			else
			{
				lo=mid+1;
			}
		}
		cout << hi << '\n';
	}
}