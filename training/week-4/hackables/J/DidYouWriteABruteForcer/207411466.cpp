#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct RangeMax {
    vector<ll> a;
    RangeMax(const vector<ll>& a): a(a) {}

    int operator()(int i, int j) {
        assert(i < j);
        return distance(a.begin(), max_element(a.begin() + i, a.begin() + j));
    }
};

ll solve(const vector<ll>& a) {
    RangeMax maxs(a);
    vector<ll> sums = {0LL};
    for (ll v : a) sums.push_back(sums.back() + v);
    priority_queue<pair<int,int>> ranges;
    ranges.emplace(int(a.size()), 0);
    ll ans = 0;
    for (int it = 0; it < 100; it++) {
        auto [sz, i] = ranges.top(); ranges.pop();
        if (!sz) break;
        int j = i + sz;
        int x = maxs(i, j), y = x+1;
        ranges.emplace(x - i, i);
        ranges.emplace(j - y, y);
        ll bestl = 0, bestr = 0;
        for (int I = i; I <= x; I++) bestl = max(bestl, sums[x] - sums[I]);
        for (int J = y; J <= j; J++) bestr = max(bestr, sums[J] - sums[y]);
        ans = max(ans, bestl + bestr);
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
