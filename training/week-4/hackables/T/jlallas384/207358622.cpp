#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,q;
		cin >> n >> q;
		vector<int> a(n);
		vector<ll> pre(n);
		for(int &x: a){
			cin >> x;
		}
		for(int i = 0; i < n; i++){
			pre[i] += a[i];
			if(i + 1 < n) pre[i + 1] += pre[i];
		}
		for(int it = 0; it < q; it++){
			int s;
			cin >> s;
			vector<ll> f(n);
			for(int i = 0; i < s; i++){
				f[s - 1] += a[i];
			}
			multiset<ll> ms;
			ms.insert(f[s - 1]);
			for(int i = s; i < n; i++){
				ll ths = pre[i] - pre[i - s];
				f[i] = *ms.begin() + ths;
				if(2 * s - 1 <= i) ms.erase(ms.find(f[i - s]));
				ms.insert(f[i]);
			}
			cout << f[n - 1];
			if(it != q - 1) cout << " ";
		}
		cout << '\n';
	}
}