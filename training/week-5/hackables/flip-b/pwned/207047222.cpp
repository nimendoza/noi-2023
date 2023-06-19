#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int solve(int N, string a) {
	if (N == 1) {
		if (a[0] == '1')
			return 1;
		else
			return 0;
	}
	int count1 = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] == '1')
			count1++;
	}
	int pfsL[N + 1];	// prefix of count1 - count0
	pfsL[0] = 0;
	for (int i = 1; i <= N; i++) {
		pfsL[i] = (a[i - 1] == '1') ? pfsL[i - 1] + 1 : pfsL[i - 1] - 1;
	}
	int pfsR[N + 1];	// prefix of count1 - count0
	pfsR[N] = 0;
	for (int i = N - 1; i >= 0; i--) {
		pfsR[i] = (a[i] == '1') ? pfsR[i + 1] + 1 : pfsR[i + 1] - 1;
	}
/*
	cout<<"pfsL: ";
	for (int i = 0; i <= N; i++) {
		cout<<pfsL[i]<<" ";
	}
	cout<<endl;
	cout<<"pfsR: ";
	for (int i = 0; i <= N; i++) {
		cout<<pfsR[i]<<" ";
	}
	cout<<endl;
*/
	int ansL[N + 1];	// maximize count1 - maximum of (currct1 - currct0)
	ansL[0] = 0;
	int currmin = 0;
	int currct1 = 0;
	int maximum = 0;
	for (int i = 1; i <= N; i++) {
		maximum = max(maximum, pfsL[i] - currmin);
		currmin = min(currmin, pfsL[i]);
		if (a[i - 1] == '1')
			currct1++;
		ansL[i] = currct1 - maximum;
	}
	int ansR[N + 1];	// maximize count1 - maximum of (currct1 - currct0)
	ansR[N] = 0;
	currmin = 0;
	currct1 = 0;
	maximum = 0;
	for (int i = N - 1; i >= 0; i--) {
		maximum = max(maximum, pfsR[i] - currmin);
		currmin = min(currmin, pfsR[i]);
		if (a[i] == '1')
			currct1++;
		ansR[i] = currct1 - maximum;
	}
/*
	cout<<"ansL: ";
	for (int i = 0; i <= N; i++) {
		cout<<ansL[i]<<" ";
	}
	cout<<endl;
	cout<<"ansR: ";
	for (int i = 0; i <= N; i++) {
		cout<<ansR[i]<<" ";
	}
	cout<<endl;
*/
	int answer = 1e9;
	for (int i = 0; i <= N; i++) {
		answer = min(answer, ansL[i] + ansR[i]);
	}
	return answer;
	// minimum 1's until position
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