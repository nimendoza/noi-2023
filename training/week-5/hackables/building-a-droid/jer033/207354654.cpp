#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int q;
	long long p2, p3, v1, v2, v3, c;
	cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;
	for (int test=0; test<q; test++)
	{
		cin >> c;
		long long best=0;
		for (int i=0; i<=(c/p2); i++)
		{
			for (int j=0; j<=(c-i*p2)/p3; j++)
			{
				best=max(best, i*v2+j*v3+(c-i*p2-j*p3)*v1);
			}
		}
		cout << best << '\n';
	}
}