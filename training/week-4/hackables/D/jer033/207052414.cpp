#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long sumgis[200005];
long long sumhis[200005];
long long answercompil[400010];

int main()
{
	int n;
	cin >> n;
	sumgis[0]=0;
	sumhis[0]=0;
	long long holder;
	for (int i=1; i<=n; i++)
	{
		cin >> holder;
		sumgis[i]=sumgis[i-1]+holder;
	}
	for (int i=1; i<=n; i++)
	{
		cin >> holder;
		sumhis[i]=sumhis[i-1]+holder;
	}
	for (int i=1; i<=2*n; i++)
	{
		long long answer=0;
		for (int j=0; j<=n; j++)
		{
			if (i>=j and (i-j)<=n)
			{
				answer=max(answer, sumgis[j]+sumhis[i-j]);
			}
		}
		answercompil[i]=answer;
	}
	long long finalans=0;
	for (int i=1; i<=2*n; i++)
	{
		finalans=finalans^answercompil[i];
	}
	cout << finalans << '\n';
}