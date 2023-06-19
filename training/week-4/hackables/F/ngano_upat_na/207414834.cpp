#include "bits/stdc++.h"
using namespace std;
using ll = long long;  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll q, p2, p3, v1, v2, v3;
    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;
    
    ll c[3] = {1, p2, p3}, v[3] = {v1, v2, v3};
    vector<ll> dp(2000001,0);
    for (int i=1; i<=2000000; i++) {
        for (int j=0; j<3; j++) {
            if (i - c[j] >= 0) {
                ll cst = dp[i - c[j]] + v[j];
                dp[i] = max(dp[i],cst);
            }   
        }   
    }   
    
    while (q--) {
        ll C;
        cin >> C;
        cout << dp[C];
        
        if (q != 0) cout << '\n';
    }   
}   