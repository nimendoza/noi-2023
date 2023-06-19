#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int solve(int N, string a) {
	int count1 = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] == '1')
			count1++;
	}
	int pfs[N + 1];	// prefix of count1 - count0
	pfs[0] = 0;
	for (int i = 1; i <= N; i++) {
		pfs[i] = (a[i - 1] == '1') ? pfs[i - 1] + 1 : pfs[i - 1] - 1;
	}
/*
	cout<<"pfs: ";
	for (int i = 0; i <= N; i++) {
		cout<<pfs[i]<<" ";
	}
	cout<<endl;
*/
	int currmin = 0;
	int maximum = -1e9;
	for (int i = 1; i <= N; i++) {
//		cout<<i<<": "<<pfs[i] - currmin<<endl;
		maximum = max(maximum, pfs[i] - currmin);
		currmin = min(currmin, pfs[i]);
	}
	return (count1 - maximum);
}

int main() {
	int times;
	cin>>times;
	for (int i = 0; i < times; i++) {
		int N;
		cin>>N;
		string a;
		cin>>a;
		cout<<solve(N, a)<<endl;
	}
}