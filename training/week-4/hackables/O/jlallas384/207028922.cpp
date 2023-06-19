#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500500;
int f[N][2];
vector<int> g[N];

int dfs(int v,int p,int tk){
	if(f[v][tk] != -1) return f[v][tk];
	int ths = tk;
	for(int u: g[v]) if(u != p){
		if(tk){
			ths += dfs(u, v, 0);
		}else{
			ths += max(dfs(u, v, 0), dfs(u, v, 1));
		}
	}
	return f[v][tk] = ths;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	memset(f, -1, sizeof(f));
	for(int i = 1; i < n; i++){
		int x;
		cin >> x, x--;
		g[x].push_back(i);
		g[i].push_back(x);
	}
	cout << max(dfs(0, -1, 0), dfs(0, -1, 1));
}
