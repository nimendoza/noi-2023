#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod =  998'244'353;

ll solve(ll n, ll w, ll f0, const vector<ll>& a) {
    n = min(n, 1LL << 24);
    ll f = f0 % a.size();
    deque<ll> ts;
    for (int i = 0; i < n; i++) {
        f = f * f % a.size();
        if (ll v = a[f] + w * (i + 1); v) {
            if (!ts.empty() && (ts.back() > 0) == (v > 0)) {
                ts.back() += v;
            } else {
                ts.emplace_back(v);
            }
        }
    }
    ll ans = 0;
    if (!ts.empty() && ts.back() > 0) ts.pop_back();
    if (!ts.empty() && ts.front() > 0) ts.pop_front();
    if (!ts.empty()) {
        assert(ts.back() < 0);
        assert(ts.front() < 0);
        int mn = distance(ts.begin(), min_element(ts.begin(), ts.end()));
        assert(ts[mn] < 0);
        int l = mn, r = mn + 1;
        while (l >= 2 && ts[l - 2] + ts[l - 1] <= 0) l -= 2;
        while (r + 2 <= ts.size() && ts[r] + ts[r + 1] <= 0) r += 2;
        ans = min(ans, accumulate(ts.begin() + l, ts.begin() + r, 0LL));
        assert(ans < 0);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n, w, k, f0; cin >> n >> w >> k >> f0;
        vector<ll> a(k);
        for (ll& v : a) cin >> v;
        cout << (solve(n, w, f0, a) % mod + mod) % mod << '\n';
    }
}
