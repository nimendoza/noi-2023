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

    int count = 0, max1 = 0, max2 = 0, total = 0;
    for (int i = 0; i < a.size()+1; ++i) {
        if (a[i] == '1') {
            ++count;
            ++total;
        }
        else {
            if (count > max1 && count > max2) {
                max1 = count;
            } else if (count > max2 && count <= max1) {
                max2 = count;
            }
            count = 0;
        }
    }
    cout << total - (max1 + max2) << '\n';
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