#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
    int n, c; cin >> n >> c;
    priority_queue<ll> sticks; sticks.push(0);
    for (int i = 0; i < n; ++i) {
        ll l; cin >> l;
        sticks.push(l);
    }

    while (c > 0) {
        if (c == 0) break;
        sticks.push(sticks.top()/2);
        sticks.push(ceil(double(sticks.top())/2));
        sticks.pop();
        c--;
    }

    ll big = 0;
    for (int i = 0; i < sticks.size(); ++i) {
        ll comp = sticks.top(); sticks.pop();
        big = max(big, comp);
    }

    cout << big << '\n';
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