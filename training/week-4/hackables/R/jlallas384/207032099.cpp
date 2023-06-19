#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct frac{
	int num, denum;
	frac(int num, int denum): num(num), denum(denum){}
};

bool comp(frac a, frac b){
	if(a.num * b.denum != b.num * a.denum){
		return a.num * b.denum < b.num * a.denum;
	}
	return a.denum > b.denum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n, d;
		cin >> n >> d;
		vector<frac> a;
		for(int i = 0; i < n; i++){
			int v,c;
			cin >> v >> c;
			a.push_back(frac(v,c));
		}
		sort(a.rbegin(), a.rend(), comp);
		int cur = 0;
		int ans = 1e9;
		for(auto x: a){
			ans = min(ans, cur + (d + x.num - 1) / x.num * x.denum);
			cur += d / x.num * x.denum;
			d %= x.num;
		}
		cout << ans << '\n';
	}
}