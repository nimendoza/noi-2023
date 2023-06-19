#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void sol() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n), c(n);
    for (int i=0; i<n; i++) cin >> v[i] >> c[i];
    
    vector<int> val(d+1,0);
    vector<bool> good(d+1,false);
    good[0] = true;
    for (int i=0; i<=d; i++) {
        for (int j=0; j<n; j++) {
            if (good[i] && i+c[j]<=d) {
                good[i+c[j]] = true;
                val[i+c[j]] = max(val[i+c[j]],val[i]+v[j]);
            }   
        }   
    }  
    int ans = 0;
    for (int i=0; i<=d; i++) ans = max(ans,val[i]);
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