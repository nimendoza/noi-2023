#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<pair<int,int>> a(n);
		int mx = 0, my = 0;
		map<int,int> mpx, mpy;
		for(auto &[x,y]: a){
			cin >> x >> y;
			mpx[x] = mpx.size();
			mpy[y] = mpy.size();
			mx = max(mx, mpx[x]);
			my = max(my, mpy[y]);
			x = mpx[x];
			y = mpy[y];
		}
		vector<vector<int>> f(mx + 1, vector<int>(my + 1, 1e9));
		f[0][0] = 0;
		for(int i = 0; i <= mx; i++){
			for(int j = 0; j <= my; j++){
				if(i > 0){
					int cnt = 0;
					for(auto [x,y]: a){
						cnt |= (x == i && y > j);
					}
					f[i][j] = f[i - 1][j] + cnt;
				}
				if(j > 0){
					int cnt = 0;
					for(auto [x,y]: a){
						cnt |= (y == j && x > i);
					}
					f[i][j] = min(f[i][j], f[i][j - 1] + cnt);
				}
			}
		}
		cout << f[mx][my] << '\n';
	}
}
