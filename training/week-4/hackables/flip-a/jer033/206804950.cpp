#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char binstr[200005];
int prefix[200005];
int maximu[200005];

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=1; testcase<=t; testcase++)
	{
		cin >> n >> binstr;
		int ones=0;
		int total=0;
		for (int i=0; i<n; i++)
		{
			if (binstr[i]=='1')
			{
				ones++;
				total++;
			}
			else
			{
				total--;
			}
			prefix[i]=total;
		}
		maximu[n-1]=total;
		for (int i=n-2; i>=0; i--)
		{
			maximu[i]=max(maximu[i+1], prefix[i]);
		}
		int ans=0;
		for (int i=0; i<n; i++)
		{
			ans = max(ans, maximu[i]-prefix[i]);
		}
		ans = max(ans, maximu[0]);
		cout << ones-ans << '\n';
	}
}