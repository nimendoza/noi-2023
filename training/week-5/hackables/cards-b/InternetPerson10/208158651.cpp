#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

__float128 abs(__float128 x) {
    if(x < 0) return -x;
    else return x;
}

__float128 eps = 1e-12;

vector<__float128> v, v2;
vector<long double> v3;

void solve() {
    int n, k;
    cin >> n >> k;
    v.resize(n+1);
    v3.resize(n+1);
    v[0] = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i+1] = (__float128)x + v[i];
    }
    v2 = v;
    __float128 l = 0, r = 1000000000001LL;
    for(int i = 0; i <= n; i++) {
        v[i] = v2[i];
        v3[i] = v[i];
    }
    for(int z = 0; z < 40; z++) {
        long double x = (l + r) / 2;
        long double mi = 0;
        bool ok = false;
        long double g = 0;
        for(int i = 0; i <= n && !ok; i++) {
            v3[i] -= g;
            g += x;
            if(i >= k) {
                if(v3[i-k] < mi) mi = v3[i-k];
                if(v3[i] > mi) {
                    ok = true;
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            v3[i] = v2[i];
        }
        if(ok) l = x;
        else r = x;
    }
    for(int z = 0; z < 50; z++)  {
        __float128 x = (l + r) / 2;
        __float128 mi = 0;
        bool ok = false;
        __float128 g = 0;
        for(int i = 0; i <= n && !ok; i++) {
            v[i] -= g;
            g += x;
            if(i >= k) {
                if(v[i-k] < mi) mi = v[i-k];
                if(v[i] > mi) {
                    ok = true;
                }
            }
        }
        for(int i = 0; i <= n; i++) {
            v[i] = v2[i];
        }
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
