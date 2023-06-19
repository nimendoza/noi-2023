#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n; ll d;
		cin >> n >> d;
		vector<ll> a(n);
		for(ll &x: a){
			cin >> x;
		}
		ll ans = 1e18;
		ll pmx = -1e18;
		ll pmn = 1e18;
		for(int i = 0; i <= n; i++){
			ll smx = -1e18;
			ll smn = 1e18;
			if(i) pmx = max(pmx, a[i - 1]);
			if(i) pmn = min(pmn, a[i - 1]);
			for(int j = 0; j <= n && i + j <= n; j++){
				if(j) smx = max(smx, a[n - j]);
				if(j) smn = min(smn, a[n - j]);
				if(i + j){
					ans = min(ans, (n - i - j) * d + max(pmx, smx) - min(pmn, smn));
				}
			}
		}
		cout << ans << '\n';
	}
}