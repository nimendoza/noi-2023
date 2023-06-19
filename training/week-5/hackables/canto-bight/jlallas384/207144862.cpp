#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1'000'000'01;
bitset<N> bs;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,a;
		cin >> n >> a;

		bs[N - 1] = true;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			bs |= (bs >> x);
		}
		cout << N - 1 - bs._Find_next(N - a - 1) << endl;
		bs.reset(); 
	}
}