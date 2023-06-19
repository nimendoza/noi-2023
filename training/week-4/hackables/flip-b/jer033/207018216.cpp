#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char binstr[200005];
int prefix[200005];
int maximu[200005];
int ranger[200005];

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=1; testcase<=t; testcase++)
	{
		cin >> n >> binstr;
		for (int rand=1; rand<=2; rand++)
		{
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
			ranger[n-1]=n-1;
			for (int i=n-2; i>=0; i--)
			{
				if (prefix[i]>maximu[i+1])
				{
					ranger[i]=i;
				}
				else
				{
					ranger[i]=ranger[i+1];
				}
				maximu[i]=max(maximu[i+1], prefix[i]);
			}
			int ans=0;
			int bestplace=-1;
			for (int i=0; i<n; i++)
			{
				if (maximu[i]-prefix[i] > ans)
				{
					ans = max(ans, maximu[i]-prefix[i]);
					bestplace=i;
				}
			}
			for (int i=bestplace+1; i<=ranger[bestplace]; i++)
			{
				if (binstr[i]=='0')
					binstr[i]='1';
				else
					binstr[i]='0';
			}
			/*for (int i=0; i<n; i++)
			{
				cout << binstr[i];
			}
			cout << '\n';*/
		}
		int ones=0;
		for (int i=0; i<n; i++)
		{
			if (binstr[i]=='1')
				ones++;
		}
		cout << ones << '\n';
	}
}