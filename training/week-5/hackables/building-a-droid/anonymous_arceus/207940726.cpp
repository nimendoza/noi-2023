#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> value;

void print128(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print128(x / 10);
    char digit = x%10 + '0';
    cout << digit;
}

void solve() {
    ll credit; cin >> credit;
    __int128 ans = 0;

    for (int i = 0; i < value.size(); ++i) {
        while (credit > 0) {
            ans += value[i].first;
            credit -= value[i].second;
        }
        if (credit < 0) { ans -= value[i].first; credit += value[i].second; }
    }
    print128(ans); cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q, p2, p3, v1, v2, v3; cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;
    value.emplace_back(v1, 1); value.emplace_back(v2, p2); value.emplace_back(v3, p3);

    sort(value.rbegin(), value.rend(), [](auto x, auto y) {
        return (double)x.first/(double)x.second < (double)y.first/(double)y.second;
    });

    while (q > 0) {
        solve();
        q--;
    }
}