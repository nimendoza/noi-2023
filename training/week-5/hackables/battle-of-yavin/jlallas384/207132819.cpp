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
		vector<int> f(d + 1, -1e9);
		f[d] = 0;
		for(int i = 0; i < n; i++){
			int v,c;
			cin >> v >> c;
			for(int j = d; j >= c; j--){
				f[j - c] = max(f[j - c], f[j] + v);
			}
		}
		cout << *max_element(f.begin(), f.end()) << '\n';
	}
}