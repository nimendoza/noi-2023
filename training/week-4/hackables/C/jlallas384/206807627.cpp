#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,c;
		cin >> n >> c;
		vector<int> a(n);
		for(int &x: a){
			cin >> x;
		}
		int ans = 0;
		int lo = 1, hi = (1 << 30);
		while(lo <= hi){
			int mi = (lo + hi) / 2;
			ll ths = 0;
			for(int x: a){
				ths += (x + mi - 1) / mi - 1;
			}
			if(ths <= c){
				hi = mi - 1;
				ans = mi;
			}else{
				lo = mi + 1;
			}
		}
		cout << ans << '\n';
	}
}