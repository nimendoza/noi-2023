#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> v;

bool check(ll x, int lim) {
    int tot = 0;
    for(int g : v) tot += (g + x - 1) / x;
    return (tot <= lim);
}

void solve() {
    int n, c;
    cin >> n >> c;
    v.resize(n);
    for(ll &g : v) cin >> g;
    ll l = 0, r = (1LL << 60);
    while(l != r - 1) {
        (check((l + r) / 2, c + n) ? r : l) = (l + r) / 2;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
