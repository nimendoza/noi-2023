#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int l, int r, vector<ll> &a){
	if(l == r){
		return 0;
	}
	int m = (l + r) / 2;
	ll ans = -1e18;
	ll sum1 = 0, mx1 = -1e18;
	ll sum2 = 0, mx2 = -1e18, mxsum = -1e18;
	int it = m + 1;
	for(int i = m; i >= l; i--){
		sum1 += a[i];
		mx1 = max(mx1, a[i]);
		while(it <= r && max(mx2, a[it]) <= mx1){
			mx2 = max(mx2, a[it]);
			sum2 += a[it];
			mxsum = max(mxsum, sum2);
			it++;
		}
		ans = max(ans, sum1 + mxsum - mx1);
	}
	return max({ans, f(l, m, a), f(m + 1, r, a)});
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(ll &x: a){
			cin >> x;
		}
		ll ans = f(0, n - 1, a);
		reverse(a.begin(), a.end());
		cout << max(ans, f(0, n - 1, a)) << '\n';
	}
}