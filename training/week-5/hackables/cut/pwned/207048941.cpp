#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll N, C;
vector<ll> lengths;

bool check(ll x) {	// max length mid, use at most C?
//	cout<<"at "<<x<<endl;
	ll total = 0;
	for (int i = 0; i < N; i++) {
		total += (lengths[i] + x - 1) / x;
	}
//	cout<<"total: "<<total<<endl;
	if (total <= C)
		return true;
	return false;
}

ll solve() {
	C++;	// split into C sticks instead
	ll low = 1;
	ll high = 1e18;
	ll ans = -1;	// possible to split with max length = ans
	// binary search
	while (low <= high) {	// false, false, false, true, true, true
		ll mid = (low + high) / 2;
		if (check(mid)) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	int times;
	cin>>times;
	for (int i = 0; i < times; i++) {
		cin>>N>>C;
		lengths.clear();
		lengths.resize(N);
		for (int j = 0; j < N; j++) {
			cin>>lengths[j];
		}
		cout<<solve()<<endl;
	}
}