#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// 100 muna. wut??

ll ans[900001];
ll g[4001], h[400001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g[0] = h[0] = 0;
    for(int i = 1; i <= n; i++) cin >> g[i];
    for(int i = 1; i <= n; i++) cin >> h[i];
    ll a, b;
    a = b = 0;
    for(int i = 0; i <= n; i++) {
        a += g[i];
        b = 0;
        for(int j = 0; j <= n; j++) {
            b += h[j];
            ans[i+j] = max(ans[i+j], a + b);
        }
    }
    ll x = 0;
    for(int i = 1; i <= 2 * n; i++) {
        x ^= ans[i];
    }
    cout << x << '\n';
}
