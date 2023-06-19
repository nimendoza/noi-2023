#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;

ll solve(int N, vi g, vi h) {
	ll pfs1[N + 1];
	ll pfs2[N + 1];
	pfs1[0] = 0;
	pfs2[0] = 0;
	for (int i = 1; i <= N; i++) {
		pfs1[i] = pfs1[i - 1] + g[i - 1];
		pfs2[i] = pfs2[i - 1] + h[i - 1];
	}
	ll ans[2 * N + 1];
	for (int i = 0; i <= 2 * N; i++) {
		ans[i] = 0;
		for (int j = 0; j <= i; j++) {	// j for Greedo, i - j for Han
			if (j > N || i - j > N)
				continue;
			int k = i - j;	// count for Han
			ans[i] = max(ans[i], pfs1[j] + pfs2[k]);
		}
	}
/*
	cout<<"ans: "<<endl;
	for (int i = 0; i <= 2 * N; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
*/
	ll xr = 0;
	for (int i = 0; i <= 2 * N; i++) {
		xr ^= ans[i];
	}
	return xr;
}

int main() {
	int N;
	cin>>N;
	vi g(N);
	for (int i = 0; i < N; i++) {
		cin>>g[i];
	}
	vi h(N);
	for (int i = 0; i < N; i++) {
		cin>>h[i];
	}
	cout<<solve(N, g, h)<<endl;
}