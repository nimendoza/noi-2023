#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000100;
ll st[4 * N];

void upd(int p,int l,int r,int i,ll x){
	if(l == r){
		st[p] = x;
	}else{
		int m = (l + r) / 2;
		if(i <= m) upd(p * 2, l, m, i, x);
		else upd(p * 2 + 1, m + 1, r, i, x);
		st[p] = min(st[p * 2], st[p * 2 + 1]);
	}
}

ll qry(int p,int l,int r,int i,int j){
	if(r < i || j < l) return 1e18;
	if(i <= l && r <= j) return st[p];
	int m = (l + r) / 2;
	return min(qry(p * 2, l, m, i, j), qry(p * 2 + 1, m + 1, r, i, j));
}

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
			ll f = 0;
			for(int i = 0; i < s; i++){
				f += a[i];
			}
			for(int i = 0; i < s - 1; i++){
				upd(1, 0, n - 1, i, 1e18);
			}
			upd(1, 0, n - 1, s - 1, f);
			for(int i = s; i < n; i++){
				upd(1, 0, n - 1, i, qry(1, 0, n - 1, i - s, i - 1) + pre[i] - pre[i - s]);
			}
			cout << qry(1, 0, n - 1, n - 1, n - 1);
			if(it != q - 1) cout << " ";
		}
		cout << '\n';
	}
}