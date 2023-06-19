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
  		vector<vector<int>> f(n + 1, vector<int>(5, 1e9));
  		f[0][0] = 0;
  		for(int i = 1; i <= n; i++){
  			char x;
  			cin >> x;
  			if(n == 1){
  				f[1][4] = (x == '1');
  				break;
  			}
  			f[i][0] = f[i - 1][0] + (x == '1');
  			f[i][1] = f[i - 1][0] + (x == '0');
  			f[i][1] = min(f[i][1], f[i - 1][1] + (x == '0'));
  			f[i][2] = min(f[i - 1][2] + (x == '1'), f[i][1]);

  			f[i][3] = f[i - 1][2] + (x == '0');

  			f[i][3] = min(f[i][3], f[i - 1][3] + (x == '0'));
  			f[i][4] = min(f[i - 1][4] + (x == '1'), f[i][3]);
  		}
  		cout << f[n][4] << '\n';
    }
}