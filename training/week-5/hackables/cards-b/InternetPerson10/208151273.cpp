#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

__float128 eps = 1e-8;

__float128 abs(__float128 x) {
    if(x < 0) return -x;
    else return x;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<__float128> v(n+1), v2;
    v[0] = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i+1] = (__float128)x + v[i];
    }
    v2 = v;
    __float128 l = 0, r = 10000000000000LL;
    for(int z = 0; z < 100; z++)  {
        __float128 x = (l + r) / (__float128)(2);
        __float128 mi = 0;
        bool ok = false;
        __float128 g = 0;
        for(int i = 0; i <= n; i++) {
            v[i] -= g;
            g += x;
            if(i >= k) {
                mi = min(mi, v[i-k]);
                if(v[i] > mi) {
                    ok = true;
                    break;
                }
            }
        }
        v = v2;
        if(ok) l = x;
        else r = x;
    }
    __float128 g = 0;
    __float128 best = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        g = l * i;
        __float128 h = abs(g - round((long double)g));
        if(h < best) {
            ans = i;
            best = abs(h);
        }
    }
    cout << (ll)round((long double)l * ans) << '/' << ans << '\n';
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
