#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char binstr[200005];
char newstr[200005];
//arrays that I used in FlipA
int prefix[200005];
int maximu[200005];

//Notes on Solution
//half brute force
//O(n^3) so should get up to subtask 3

//NOTE TO HACKERS
//If this passes subtask 4 or 5 then you can probably TLE it
//Also, congrats for finding this free hacking tip: Hack submission 207354654 (Problem F) by forcing it to use 128 bit integers

int flipa(int n, char ranstr[200005], int prefix[200005], int maximu[200005])
{
	int ones=0;
	int total=0;
	for (int i=0; i<n; i++)
	{
		if (ranstr[i]=='1')
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
	if (ones!=0)
		return ones-ans;
	else
		return 1;
}

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=1; testcase<=t; testcase++)
	{
		cin >> n >> binstr;
		int finalans=n+1;
		for (int i=0; i<n; i++)
		{
			for (int j=i; j<n; j++)
			{
				for (int k=0; k<n; k++)
				{
					if (k<i or k>j)
					{
						newstr[k]=binstr[k];
					}
					else
					{
						if (binstr[k]=='1')
							newstr[k]='0';
						else
							newstr[k]='1';
					}
				}
				finalans=min(finalans, flipa(n, newstr, prefix, maximu));
			}
		}
		cout << finalans << '\n';
	}
}