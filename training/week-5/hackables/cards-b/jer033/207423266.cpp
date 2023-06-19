#include <algorithm>
#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (a==0)
		return b;
	if (b==0)
		return a;
	if (a<b)
		return gcd(b, a);
	if (a%b==0)
		return b;
	return gcd(b, a%b);
}

long long vis[405];
long long prefix[405];

int main()
{
	int t, n, l;
	cin >> t;
	for (int test=1; test<=t; test++)
	{
		cin >> n >> l;
		prefix[0]=0;
		for (int i=1; i<=n; i++)
		{
			cin >> vis[i];
			prefix[i]=prefix[i-1]+vis[i];
		}
		long long bestnumer=-10000000000000;
		long long bestdenom=1;
		long long numer, denom;
		for (int i=1; i<=n; i++)
		{
			for (int j=i+l-1; j<=n; j++)
			{
				numer=prefix[j]-prefix[i-1];
				denom=j-i+1;
				if ((bestdenom*numer)>(denom*bestnumer))
				{
					bestnumer=numer+1-1;
					bestdenom=denom+1-1;
				}
			}
		}
		long long k;
		k=gcd(bestnumer, bestdenom);
		cout << bestnumer/k << '/' << bestdenom/k << '\n';
	}
}