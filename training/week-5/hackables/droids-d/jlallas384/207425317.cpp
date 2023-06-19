#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
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
		vector<vector<vector<ll>>> f(n, vector<vector<ll>>(n, vector<ll>(3)));
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j + i <= n; j++){
				int k = i + j - 1;
				if(i == 1){
					f[j][k][0] = f[j][k][1] = f[j][k][2] = min(0LL, a[j]);
				}else{
					f[j][k][0] = min(0LL, f[j + 1][k][0] + a[j]);
					f[j][k][1] = min(0LL, f[j][k - 1][1] + a[k]);
					f[j][k][2] = min(f[j][k][0], f[j][k][1]);
					if(i >= 3){
						f[j][k][2] = min(f[j][k][2], f[j + 1][k - 1][2]);
					}
				}
				ans = (ans + f[j][k][2] + mod) % mod;
			}
		}
		cout << (ans + mod) % mod << '\n';
	}
}