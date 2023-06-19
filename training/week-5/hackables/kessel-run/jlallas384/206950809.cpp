#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,h;
	cin >> n >> h;
	vector<int> a(n);
	for(int &x: a){
		cin >> x;
	}
	vector<int> f(h + 1);
	iota(f.begin(), f.end(), 0);
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= h; j++){
			if(j - a[i] >= 0){
				f[j] = min(f[j], f[j - a[i]] + 1);
			}
		}
	}
	cout << f[h];
}
