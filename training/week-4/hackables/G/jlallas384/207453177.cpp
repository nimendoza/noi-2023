#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bi = __int128;

void print(__int128 x) {
    if (x > 9) print(x / 10);
    cout << (char) (x % 10 + '0');
}

const int mod = 998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n, w, k,  f;
		cin >> n >> w >> k >> f;
		vector<ll> b(k);
		for(ll &x: b){
			cin >> x;
		}
		vector<bi> a(n);
		for(int i = 0; i < n; i++){
			f = (ll) f * f % k;
			a[i] = b[f] + w * (i + 1);
		}
		bi cur = 0, ans = 0;
		for(int i = 0; i < n; i++){
			cur += a[i];
			ans = min(ans, cur);
			if(cur > 0) cur = 0;
		}
		ans = ((ans + mod) % mod + mod) % mod;
		print(ans);
		cout << '\n';
	}
}