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
    	vector<int> a;
    	int tot = 0;
    	for(int i = 0; i < n; i++){
    		char x;
    		cin >> x;
    		a.push_back(x - '0');
    		tot += a.back();
    	}
    	a.push_back(a.back() ^  1);
    	vector<pair<int,int>> b;
    	int cnt = 0;
    	for(int i = 0; i < n; i++){
    		cnt++;
    		if(a[i] != a[i + 1]){
    			b.emplace_back(a[i], cnt);
    			cnt = 0;
    		}
    	}
    	if(b[0].first == 0){
    		b.erase(b.begin());
    	}
    	int cur = tot;
    	int ans = tot;
    	for(int i = 0; i < b.size(); i++){
    		if(b[i].first == 1){
    			cur -= b[i].second;
    			ans = min(ans, cur);
    		}else{
    			if(b[i].second > b[i - 1].second){
    				cur = tot;
    			}else{
    				cur += b[i].second;
    				ans = min(ans, cur);
    			}
    		}
    	}
    	cout << ans << '\n';
    }
}