#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
		ll sum = 0, mx = -1e18;
		ll ans = 0;
		for(ll x: a){
			sum += x;
			mx = max(mx, x);
			ans = max(ans, sum - mx);
			if(sum < 0){
				sum = 0;
				mx = -1e18;
			}
		}
		cout << ans << '\n';
	}
}