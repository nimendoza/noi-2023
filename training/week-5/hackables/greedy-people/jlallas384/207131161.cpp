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
		map<int,int> mp;
		int has = 0;
		ll sum = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			mp[x]++;
			has |= x == 0;
			sum += x;
		}
		int ans = 0;
		for(auto [x,y]: mp){
			ans = max(ans, min(y, n - 1) + (x == sum && has));
		}
		cout << ans << '\n';
	}
}