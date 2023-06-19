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
	vector<int> f(h + 1, 1e9);
	f[0] = 0;
	for(int x: a){
		vector<int> g(h + 1, 1e9);
		for(int i = 0; i <= h; i++){
			g[i] = f[i];
			if(i - x >= 0){
				g[i] = min(g[i], g[i - x] + 1);
			}
		}
		f = g;
	}
	cout << f[h];
}
