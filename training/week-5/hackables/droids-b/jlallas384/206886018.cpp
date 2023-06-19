#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for(ll &x: a){
			cin >> x;
		}
		for(ll &x: b){
			cin >> x;
		}
		vector<vector<ll>> f(n + 1, vector<ll>(k + 1, -1e18));
		f[0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= k; j++){
				f[i][j] = f[i - 1][j];
				if(j){
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i - 1]);
				}
				if(j >= 2){
					f[i][j] = max(f[i][j], f[i - 1][j - 2] + a[i - 1] + b[i - 1]);
				}
			}
		}
		cout << f[n][k] << '\n';
	}
}