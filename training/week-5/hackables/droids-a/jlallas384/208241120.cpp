#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	vector<ll> ans(2 * n + 1);
	ll sa = 0;
	for(int i = 0; i <= n; i++){
		sa += a[i];
		ll sb = 0;
		for(int j = 0; j <= n; j++){
			sb += b[j];
			ans[i + j] = max(ans[i + j], sa + sb);
		}
	}
	ll fans = 0;
	for(ll x: ans){
		fans ^= x;
	}
	cout << fans << '\n';
}