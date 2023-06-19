#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 5;
int f[N][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,h;
	cin >> n >> h;
	vector<int> a(n);
	for(int &x: a){
		cin >> x;
	}
	for(int i = 1; i <= h; i++){
		f[i][0] = 1e9;
	}
	for(int i = 1; i <= n; i++){
		int x = a[i - 1];
		for(int j = 0; j <= h; j++){
			f[j][i % 2] = f[j][(i + 1) % 2];
			if(j - x >= 0){
				f[j][i % 2] = min(f[j][i % 2], f[j - x][i % 2] + 1);
			}
		}
	}
	cout << f[h][n % 2];
}
