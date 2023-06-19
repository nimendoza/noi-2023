#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll tot_s = 0;
    map<ll, int> ma;
    ma.clear();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ma[x]++;
    }
    ll ans = 1;
    for(auto p : ma) {
        ll x = p.first;
        ll c = p.second;
        if(c == n) {
            if(c == 0) ans = n;
            else ans = max(ans, (ll)n - 1);
        }
        else if(tot_s == x) ans = max(ans, c);
        else if(ma.count(tot_s)) ans = max(ans, c+1);
        else ans = max(ans, c);
    }
    cout << ans << '\n';
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
