#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bi = __int128;

struct frac{
	ll num, denum;
	frac(ll num, ll denum): num(num), denum(denum){}
};

bool comp(frac a, frac b){
	if((bi) a.num * b.denum != (bi) b.num * a.denum){
		return (bi) a.num * b.denum < (bi) b.num * a.denum;
	}
	return a.denum > b.denum;
}

void print(__int128 x) {
    if (x > 9) print(x / 10);
    cout << (char) (x % 10 + '0');
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	vector<frac> a;
	vector<ll> b(3), c(3);
	b[0] = 1;
	cin >> b[1] >> b[2] >> c[0] >> c[1] >> c[2];
	for(int i = 0; i < 3; i++){
		a.push_back(frac(c[i], b[i]));
	}
	sort(a.rbegin(), a.rend(), comp);
	while(q--){
		ll c;
		cin >> c;
		bi ans = 0;
		for(auto x: a){
			ans += (bi) c / x.denum * x.num;
			c %= x.denum;
		}
		print(ans);
		cout << '\n';
	}
}