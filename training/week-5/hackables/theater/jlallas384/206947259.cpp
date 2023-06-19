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
		vector<pair<ll,ll>> a(n);
		for(auto &[x,y]: a){
			cin >> x >> y;
		}
		a.emplace_back(1e13, 1e13);
		priority_queue<pair<ll,int>> pq;
		pq.emplace(0, 0);
		sort(a.begin(), a.end());
		int cur = 0;
		for(auto [l,r]: a){
			while(pq.size() && -pq.top().first < l){
				cur = max(cur, pq.top().second);
				pq.pop();
			}
			pq.emplace(-r, cur + 1);
		}
		cout << cur << '\n';
	}
}
