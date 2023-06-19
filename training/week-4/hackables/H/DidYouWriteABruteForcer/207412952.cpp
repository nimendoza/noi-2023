#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod =  998'244'353;

ll solve_one(const vector<ll>& a) {
    deque<ll> ts;
    for (ll v : a) if (v) {
        if (!ts.empty() && (ts.back() > 0) == (v > 0)) {
            ts.back() += v;
        } else {
            ts.emplace_back(v);
        }
    }
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
        return accumulate(ts.begin() + l, ts.begin() + r, 0LL);
    }
    return 0LL;
}

ll solve(const vector<ll>& a) {
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j <= a.size(); j++) {
            ans += solve_one({a.begin() + i, a.begin() + j});
            ans %= mod;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (ll& v : a) cin >> v;
        cout << (solve(a) % mod + mod) % mod << '\n';
    }
}
