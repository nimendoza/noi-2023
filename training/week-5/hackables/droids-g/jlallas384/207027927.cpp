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
		vector<vector<int>> sumx(mx + 1, vector<int>(my + 2)), sumy(my + 1, vector<int>(mx + 2));
		vector<vector<int>> f(mx + 1, vector<int>(my + 1, 1e9));
		for(auto [x,y]: a){
			sumx[x][y] = 1;
			sumy[y][x] = 1;
		}
		for(int x = 0; x <= mx; x++){
			for(int i = my; i >= 0; i--){
				sumx[x][i] |= sumx[x][i + 1];
			}
		}
		for(int y = 0; y <= my; y++){
			for(int i = mx; i >= 0; i--){
				sumy[y][i] |= sumy[y][i + 1];
			}
		}
		f[0][0] = 0;
		for(int i = 0; i <= mx; i++){
			for(int j = 0; j <= my; j++){
				if(i > 0){
					f[i][j] = f[i - 1][j] + sumx[i][j + 1];
				}
				if(j > 0){
					f[i][j] = min(f[i][j], f[i][j - 1] + sumy[j][i + 1]);
				}
			}
		}
		cout << f[mx][my] << '\n';
	}
}
