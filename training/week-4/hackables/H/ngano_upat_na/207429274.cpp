#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll inf = -9e18;
const ll mod = 998244353;

void sol() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> v(n);
    for (auto &e:v) {
        cin >> e;
        e *= -1;
    }
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            ll sum = 0, best = 0;
            for (int k=i; k<=j; k++) {
                ll add = sum + v[k];
                sum = max(add,v[k]);
                best = max(best,sum);
            }   
            ans += (-best);
            ans %= mod;
        }   
    }   
    if (ans < 0) {
        ans = mod + ans;
    }   
    cout << ans;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
        if (t != 0) cout << '\n';
    }
}   