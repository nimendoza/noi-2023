#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int LG = 20;
int lg(ll n) {
    return __builtin_clzll(1LL) - __builtin_clzll(1LL | n); // number of leading zeroes, compared with 1
}

struct RangeMax {
    vector<vector<ll>> mx;
    RangeMax(const vector<ll>& a): mx(LG, vector<ll>(a.size())) {
        mx[0] = a;
        for (int l = 1; l < LG; l++) {
            mx[l] = mx[l - 1];
            for (int i = 0, j = 1 << l - 1; j < a.size(); i++, j++) {
                mx[l][i] = max(mx[l][i], mx[l - 1][j]);
            }
        }
    }

    ll operator()(int i, int j) {
        assert(0 <= i && i < j && j <= mx[0].size());
        int l = lg(j - i);
        assert(l < LG);
        return max(mx[l][i], mx[l][j - (1 << l)]);
    }
};

ll solve(const vector<ll>& a) {
    RangeMax maxs(a);
    vector<ll> sums = {0LL};
    for (ll v : a) sums.push_back(sums.back() + v);
    vector<ll> nsums; nsums.reserve(sums.size());
    for (ll v : sums) nsums.push_back(-v);
    RangeMax smaxs(sums), nsmaxs(nsums);
    priority_queue<pair<int,int>> ranges;
    ranges.emplace(int(a.size()), 0);
    ll ans = 0;
    for (int it = 0; it < 100; it++) {
        auto [sz, i] = ranges.top(); ranges.pop();
        if (!sz) break;
        int j = i + sz;
        ll mx = maxs(i, j);
        int last = i;
        for (int u = i, v = i + 1; v <= j; u++, v++) {
            if (a[u] == mx) {
                ranges.emplace(u - last, last);
                last = v;
                ans = max(ans, sums[u] + nsmaxs(i, u + 1) + smaxs(v, j + 1) - sums[v]);
            }
        }
        ranges.emplace(j - last, last);
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
        cout << solve(a) << '\n';
    }
}
