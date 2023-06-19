#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int ansforh[10000005];
int cis[35];

int main()
{
	int n, h;
	cin >> n >> h;
	for (int i=0; i<n; i++)
	{
		cin >> cis[i];
	}
	ansforh[0]=0;
	ansforh[1]=1;
	for (int i=2; i<=h; i++)
	{
		int best=20000005;
		for (int j=0; j<n; j++)
		{
			if (i>=cis[j])
			{
				best=min(best, ansforh[i-cis[j]]);
			}
		}
		ansforh[i]=best+1;
	}
	cout << ansforh[h] << '\n';
}