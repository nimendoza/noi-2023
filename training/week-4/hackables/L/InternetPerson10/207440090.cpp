#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = {x, -y};
    }
    sort(v.rbegin(), v.rend());
    ll curr_last = 100000000000000LL;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(abs(v[i].second) < curr_last) {
            ans++;
            curr_last = v[i].first;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
