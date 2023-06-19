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
		int ans = 0;
		for(auto x: a){
			ans +=  d / x.denum * x.num;
			d %= x.denum;
		}
		cout << ans << '\n';
	}
}