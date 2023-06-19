#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(vector<ll>& vs, ll s) {
    sort(vs.rbegin(), vs.rend());
    ll t = 0;
    for (ll v : vs) {
        if (t + v <= s) t += v;
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; ll s; cin >> n >> s;
        vector<ll> vs(n);
        for (ll& v : vs) cin >> v;
        cout << solve(vs, s) << '\n';
    }
}
