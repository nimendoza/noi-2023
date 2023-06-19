#include <algorithm>
#include <iostream>
using namespace std;

long long arr[300005];
long long arrsum[300005];

int main()
{
	int t, n;
	cin >> t;
	for (int testcase=0; testcase<t; testcase++)
	{
		cin >> n;
		arrsum[0]=0;
		for (int i=1; i<=n; i++)
		{
			cin >> arr[i];
			arrsum[i]=arrsum[i-1]+arr[i];
			//sum of numbers from index a to b is arrsum[b]-arrsum[a-1]
		}
		long long answer=0;
		long long curren, maxim;
		for (int i=1; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				curren=arrsum[j]-arrsum[i-1];
				maxim=-1000000000005;
				for (int k=i; k<=j; k++)
				{
					maxim=max(maxim, arr[k]);
				}
				curren=curren-maxim;
				answer=max(answer, curren);
			}
		}
		cout << answer << '\n';
	}
}