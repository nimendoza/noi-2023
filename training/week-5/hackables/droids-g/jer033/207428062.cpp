#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int xis[5005];
int yis[5005];
int used[5005];

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n;
		for (int i=1; i<=n; i++)
		{
			cin >> xis[i] >> yis[i];
		}
		int a=1<<n;
		int best=n+500;
		for (int i=1; i<=a; i++)//solve for each config of choose x/y for each droid
		{
			for (int k=0; k<=n; k++)
			{
				used[k]=0;
			}
			int j=i+1-1;
			int coun=0;
			int nexx;
			for (int k=1; k<=n; k++)
			{
				if (j%2==0)
					nexx=xis[k];
				else
					nexx=yis[k]*-1;
				int found = 0;
				for (int l=0; l<=n; l++)
				{
					if (used[l]==nexx)
						found=1;
				}
				if (found==0)
				{
					used[coun]=nexx;
					coun++;
				}
				j/=2;
			}
			best=min(best, coun);
		}
		cout << best << '\n';
	}
}