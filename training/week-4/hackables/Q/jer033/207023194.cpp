#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int poss[100000005];

int main()
{
	int t, n, a;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n >> a;
		for (int i=0; i<=a+3; i++)
		{
			poss[a]=0;
		}
		poss[0]=1;
		int ci;
		for (int i=0; i<n; i++)
		{
			cin >> ci;
			for (int j=a-ci; j>=0; j--)
			{
				poss[ci+j]+=poss[j];
			}
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
}