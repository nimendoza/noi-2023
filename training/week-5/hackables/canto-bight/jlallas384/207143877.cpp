#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bitset<1'000'000'01> bs;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,a;
		cin >> n >> a;

		bs[0] = true;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			bs |= (bs << x);
		}
		for(int i = a; i >= 1; i--) if(bs[i]){
			cout << i << endl;
			break;
		}
		bs.reset();
	}
}