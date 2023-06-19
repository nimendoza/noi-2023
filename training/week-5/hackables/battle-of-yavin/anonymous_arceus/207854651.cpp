#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

vector<pair<int, int>> TIE;

void solve() {
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        int f, s; cin >> f >> s;
        TIE.emplace_back(f, s);
    }
    sort(TIE.rbegin(), TIE.rend());

    int total = 0;
    for (const auto& i : TIE) {
        while (d > 0) {
            total += i.first;
            d -= i.second;
        }
        if (d < 0) { total -= i.first; d += i.second; }
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}