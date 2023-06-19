#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 61;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> vs(n), sm = {0LL};
    for (ll& v: vs) {
        cin >> v;
        sm.push_back(sm.back() + v);
    }
    for (int qq = 1; qq <= q; qq++) {
        int k; cin >> k;
        ll ans = INF;
        for (int i = n - k; i >= 0; i -= k) {
            int j = i + ((-i) % k + k) % k;
            ans = min(ans, sm[n] - sm[i] + sm[j] - sm[0]);
        }
        cout << ans << (qq == q ? '\n' : ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    for (cin >> t; t--; solve());
}
