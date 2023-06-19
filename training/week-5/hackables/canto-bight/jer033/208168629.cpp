#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int poss[100000005];
int brutef[140271782];

int main()
{
	int t, n, a;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n >> a;
		if (a<=1000000 or n>27)
		{
			for (int i=0; i<=a+3; i++)
			{
				poss[a]=0;
			}
			poss[0]=1;
			int ci;
			int currmax=0;
			for (int i=0; i<n; i++)
			{
				cin >> ci;
				for (int j=a-ci; j>=0; j--)
				{
					poss[ci+j]+=poss[j];
				}
				currmax+=ci;
			}
			int done=0;
			int counter=a+1;
			while (not done)
			{
				counter--;
				done+=poss[counter];
			}
			cout << counter << '\n';
		}
		else
		{
			int add=1;
			int ci;
			int currmax=0;
			brutef[0]=0;
			for (int i=1; i<=n; i++)
			{
				cin >> ci;
				for (int j=0; j<add; j++)
				{
					brutef[j+add]=brutef[j]+ci;
					if (brutef[j+add] <= a)
						currmax=max(currmax, brutef[j+add]);
				}
				add=2*add;
			}
			cout << currmax << '\n';
		}
	}
	//retest to see whether the test cases are updated
}