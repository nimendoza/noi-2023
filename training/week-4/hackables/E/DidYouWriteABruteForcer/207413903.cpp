#include <bits/stdc++.h>
using namespace std;

using ll = long long;


ll solve(int k, const vector<ll>& b, const vector<ll>& d) {
    int n = b.size();
    assert(n == d.size());
    vector<pair<ll,ll>> ts;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        ts.emplace_back(b[i] + d[i], -b[i]);
        total += b[i] + d[i];
    }
    sort(ts.begin(), ts.end());
    priority_queue<pair<ll,int>> pending;
    int tk = k - 2*n;
    ll ans = -1;
    for (int i = 0; i <= n; i++) {
        if (tk >= 0) ans = max(ans, total);
        if (i < n) {
            total -= ts[i].first;
            pending.emplace(-ts[i].second, i);
            for (int it = 0; it < 2; it++) if (++tk > 0) {
                auto [vl, ix] = pending.top(); pending.pop();
                total += vl;
                if (ix < n) pending.emplace(ts[ix].first + ts[ix].second, ix + n);
            }
        }
    }
    assert(ans >= 0);
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    for (cin >> t; t--;) {
        int n, k; cin >> n >> k;
        vector<ll> b(n), d(n);
        for (ll& v : b) cin >> v;
        for (ll& v : d) cin >> v;
        cout << solve(k, b, d) << '\n';
    }
}
