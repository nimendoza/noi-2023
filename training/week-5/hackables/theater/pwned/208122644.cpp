#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

bool comp(ii a, ii b) {	// sort by increasing second value
	if (a.se < b.se)
		return true;
	if (a.se > b.se)
		return false;
	if (a.fi < b.fi)
		return true;
	return false;
}

ll solve(ll N, vector<ii> arr) {
	sort(arr.begin(), arr.end(), comp);
/*
	cout<<"arr: "<<endl;
	for (ll i = 0; i < N; i++) {
		cout<<arr[i].fi<<" "<<arr[i].se<<endl;
	}
*/
	ll total = 0;
	ll right = 0;
	for (int i = 0; i < N; i++) {
//		cout<<i<<": "<<total<<" "<<right<<endl;
		if (arr[i].fi > right) {
			total++;
			right = arr[i].se + 1;
		}
	}
	return total;
}

int main() {
	int times;
	cin>>times;
	for (int i = 0; i < times; i++) {
		ll N;
		cin>>N;
		vector<ii> arr(N);
		for (int j = 0; j < N; j++) {
			cin>>arr[j].fi>>arr[j].se;
		}
		cout<<solve(N, arr)<<endl;
	}
}