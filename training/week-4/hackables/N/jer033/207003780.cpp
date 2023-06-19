#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long ais[200005];
long long goodnumbers[200005];

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n;
		long long total = 0;
		for (int i=0; i<n; i++)
		{
			cin >> ais[i];
			total+=ais[i];
		}
		sort(ais, ais+n);
		ais[n]=ais[n-1]+100;//just ensure they are not equal
		int longstreak=1;
		int currstreak=1;
		for (int i=1; i<=n; i++)
		{
			if (ais[i]==ais[i-1])
				currstreak++;
			else
			{
				longstreak=max(longstreak, currstreak);
				currstreak=1;
			}
		}
		//iterate a 2nd time to find the longest streak(s)
		//yes, it's wasteful in time but it's easier to code
		currstreak=1;
		long long change = 0;
		int countofgn=0;//count of good numbers
		for (int i=1; i<=n; i++)
		{
			if (ais[i]==ais[i-1])
				currstreak++;
			else
			{
				if (longstreak==currstreak)
				{
					//total-2*longstreak-change=0
					//change+ais[i-1] is a good number unless change=0
					change = total-2*longstreak;
					if (change!=0)
					{
						goodnumbers[countofgn]=change+ais[i-1];
						countofgn++;
					}
				}
				currstreak=1;
			}
		}
		//good number: if it exists, we can make a streak of longstreak+1 to all be happy greedy ppl
		sort(goodnumbers, goodnumbers+countofgn);
		int aiindex=0;
		int gnindex=0;
		int existen=0;
		while (aiindex<n and gnindex<countofgn)
		{
			if (ais[aiindex] < goodnumbers[gnindex])
				aiindex++;
			else if (ais[aiindex] > goodnumbers[gnindex])
				gnindex++;
			else
			{
				aiindex=n;
				gnindex=countofgn;
				existen=1;
			}
		}
		if (longstreak==n and n>=3 and ais[0]!=0)
			cout << longstreak-1 << '\n';
		else if (existen)
			cout << longstreak+1 << '\n';
		else
			cout << longstreak << '\n';
	}
}