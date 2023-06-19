#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

void solve() {
    int n; string a;
    cin >> n >> a;

    int count = 0, max = 0, otherCount = 0;
    for (int i = 0; i < a.size()+1; ++i) {
        if (a[i] == '1') {
            ++count;
            ++otherCount;
        }
        else {
            if (count > max) max = count;
            count = 0;
        }
    }
    cout << otherCount - max << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t > 0) {
        solve();
        --t;
    }
}