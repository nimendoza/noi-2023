#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

priority_queue<ll> bottles;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll h; cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        ll b; cin >> b;
        bottles.push(b);
    }

    int count = 0; ll total = 0;
    for (int i = 0; i < n; ++i) {
        if (total == h) break;
        if (bottles.top() <= h) {
            while (total <= h) {
                total += bottles.top();
                count++;
            }
            if (total > h) { total -= bottles.top(); count--; }
        }
        bottles.pop();
    }

    cout << count << '\n';
}