#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

void solve(int n) {
    vector<pair<ll, ll>> groups;

    for (int i = 0; i < n; ++i) {
        ll f, s; cin >> f >> s;
        groups.emplace_back(f, s);
    }
    sort(groups.begin(), groups.end(), [](auto p1, auto p2) {
        return p1.second < p2.second;
    });

    ll count = 1;
    auto start = groups[0];
    for (int i = 1; i < groups.size(); ++i) {
        if (groups[i].first <= start.second) continue;
        start = groups[i];
        count ++;
    }

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n; cin >> t >> n;
    while (t > 0) {
        solve(n);
        t--;
    }
}