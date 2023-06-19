#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int LG = 20;
int lg(ll n) {
    return __builtin_clzll(1LL) - __builtin_clzll(1LL | n); // number of leading zeroes, compared with 1
}

struct RangeMax {
    vector<vector<pair<ll,int>>> mx;
    RangeMax(const vector<ll>& a): mx(LG, vector<pair<ll,int>>(a.size())) {
        for (int i = 0; i < a.size(); i++) {
            mx[0][i] = {a[i], i};
        }
        for (int l = 1; l < LG; l++) {
            mx[l] = mx[l - 1];
            for (int i = 0, j = 1 << l - 1; j < a.size(); i++, j++) {
                mx[l][i] = max(mx[l][i], mx[l - 1][j]);
            }
        }
    }

    int operator()(int i, int j) {
        assert(0 <= i && i < j && j <= mx[0].size());
        int l = lg(j - i);
        assert(l < LG);
        auto [m, x] = max(mx[l][i], mx[l][j - (1 << l)]);
        return x;
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
        int bi = i, bj = j;
        for (int J = i + 1; J <= j; J++) {
            int I = nsmaxs(i, J);
            if (sums[bj] - sums[bi] < sums[J] - sums[I]) {
                bi = I; bj = J;
            }
        }
        int bx = maxs(bi, bj), by = bx+1;
        ans = max(ans, sums[bj] - sums[bi] - a[bx]);
        ranges.emplace(j - by, by);
        ranges.emplace(bx - i, i);
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
