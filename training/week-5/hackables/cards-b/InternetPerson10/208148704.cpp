#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

long double eps = 1e-8;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long double> v(n+1);
    v[0] = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i+1] = (long double)x + v[i];
    }
    long double l = 0, r = 10000000000000LL;
    for(int z = 0; z < 100; z++)  {
        long double x = (l + r) / (long double)(2);
        long double mi = 0;
        bool ok = false;
        for(int i = 0; i <= n; i++) {
            v[i] -= i * x;
            if(i >= k) {
                mi = min(mi, v[i-k]);
                if(v[i] > mi) ok = true;
            }
        }
        for(int i = 0; i <= n; i++) {
            v[i] += i * x;
        }
        if(ok) l = x;
        else r = x;
    }
    long double g = 0;
    long double best = 1, ans = 0;
    for(int i = 1; i <= n; i++) {
        g = l * i;
        if(abs(g - round(g)) < best) {
            ans = i;
            best = abs(g - round(g));
        }
    }
    cout << (ll)round(l * ans) << '/' << ans << '\n';
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
