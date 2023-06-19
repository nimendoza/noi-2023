#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> bottles;
    int n, h; cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        ll b; cin >> b;
        bottles.push_back(b);
    }
    sort(bottles.rbegin(), bottles.rend());

    int count = 0; ll total = 0;
    for (int i = 0; i < bottles.size(); ++i) {
        if (bottles[i] > h) continue;
        while (total < h) {
            total += bottles[i];
            count++;
        }
        if (total > h) { total -= bottles[i]; count--; }
    }

    cout << count << '\n';
}