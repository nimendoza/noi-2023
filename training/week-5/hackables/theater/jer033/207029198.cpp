#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long riatd[200005];//r inflated and then deflated
long long oldli[200005];//l_is matching orig riatd
long long newli[200005];//l_is matching new riatd

int main()
{
	int t, n;
	long long l, r;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n;
		for (int i=0; i<n; i++)
		{
			cin >> l >> r;
			riatd[i]=300000*r+i;
			oldli[i]=l;
		}
		sort(riatd, riatd+n);
		for (int i=0; i<n; i++)
			newli[i]=oldli[riatd[i]%300000];
		for (int i=0; i<n; i++)
			riatd[i]=riatd[i]/300000;
		long long occupied=0;
		int happy=0;
		for (int i=0; i<n; i++)
		{
			if (newli[i]>occupied)
			{
				happy++;
				occupied=riatd[i];
			}
		}
		cout << happy << '\n';
	}
}