#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(ll &x: a){
		cin >> x;
	}
	for(ll &x: b){
		cin >> x;
	}
	vector<ll> p1 = a, p2 = b;
	for(int i = 0; i < n - 1; i++){
		p1[i + 1] += p1[i];
		p2[i + 1] += p2[i];
	}
	ll ans = 0;
	ll cur = 0;
	int l = 0, r = 0;
	for(int i = 0; i < n; i++){
		ll bst = max({cur + a[l], cur + b[r], p1[i], p2[i]});
		if(bst == cur + a[l]){
			cur += a[l++];
		}else if(bst == cur + b[r]){
			cur += b[r++];
		}else if(bst == p1[i]){
			cur = p1[i];
			l = i + 1;
			r = 0;
		}else{
			cur = p2[i];
			l = 0;
			r = i + 1;
		}
		ans ^= cur;
	}
	for(int i = 0; i < n; i++){
		ll bst = max({p1.back() + p2[i], p1[i] + p2.back()});
		if(l < n && r == n && cur + a[l] > bst){
			cur += a[l++];
		}else if(r < n && l == n && cur + b[r] > bst){
			cur += b[r++];
		}else if(l < n && r < n){
			if(a[l] > b[r]){
				cur += a[l++];
			}else{
				cur += b[r++];
			}
		}else if(bst == p1.back() + p2[i]){
			l = n;
			r = i + 1;
			cur = bst;
		}else{
			l = i + 1;
			r = n;
			cur = bst;
		}
		ans ^= cur;
	}
	cout << ans << '\n';
}