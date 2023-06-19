#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,d;
		cin >> n >> d;
		vector<int> f(d * 2 + 10, 1e9);
		f[0] = 0;
		for(int i = 0; i < n; i++){
			int v,c;
			cin >> v >> c;
			for(int j = 0; j <= 2 * d; j++) if(j + v < f.size()){
				f[j + v] = min(f[j + v], f[j] + c);
			}
		}
		int ans = 1e9;
		for(int i = d; i < f.size(); i++){
			ans = min(ans, f[i]);
		}
		cout << ans << '\n';
	}
}