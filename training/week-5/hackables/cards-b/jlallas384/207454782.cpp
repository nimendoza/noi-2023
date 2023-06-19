#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000100;

ll pre[N], f[N];
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--){
		int n,l;
		cin >> n >> l;
		vector<ll> a(n);
		for(ll &x: a){
			cin >> x;
		}
		ll num = 0, den = 1;
		for(int i = 0; i < n; i++){
			ll sum = 0;
			for(int j = i; j < n; j++){
				sum += a[j];
				if(j - i + 1 >= l){
					if(num * (j - i + 1) < sum * den){
						num = sum;
						den = (j - i + 1);
					}
				}
			}
		}
		ll g = __gcd(num, den);
		cout << num / g << "/" << den / g << '\n';
	}
}