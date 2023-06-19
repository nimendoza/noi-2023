#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve(vector<pair<ll,ll>> ps) {
    map<pair<ll,ll>,int> conflicts;
    for (auto [i, j] : ps) {
        if (conflicts[{i, j}] == 0) {
            for (auto [I, J] : ps) {
                conflicts[{i, j}] += !(J < i || j < I);
            }
        }
    }
    set<pair<ll,ll>> collected;
    sort(ps.begin(), ps.end(), [&](auto a, auto b) {
        ll da = conflicts[a];
        ll db = conflicts[b];
        if (da != db) return da < db;
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    });
    for (auto [i, j] : ps) {
        auto it = collected.upper_bound({i, j});
        if (it == collected.end() || j < it->first) {
            if (it == collected.begin() || (--it)->second < i) {
                collected.emplace(i, j);
            }
        }
    }
    return collected.size();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<ll,ll>> ps; ps.reserve(n);
        for (int i = 0; i < n; i++) {
            ll l, r;
            cin >> l >> r;
            ps.emplace_back(l, r);
        }
        cout << solve(ps) << '\n';
    }
}
