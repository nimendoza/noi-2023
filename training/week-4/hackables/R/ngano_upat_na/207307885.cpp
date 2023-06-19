#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int inf = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> v(n), c(n);
        
        vector<int> good(500001,inf);
        for (int i=0; i<n; i++) cin >> v[i] >> c[i];
        
        good[0] = 0;
        for (int i=1; i<=500000; i++) {
            for (int j=0; j<n; j++) {
                if (i-v[j]>=0) {
                    good[i] = min(good[i],good[i-v[j]]+c[j]);
                }
            }   
        }   
        int ans = inf;
        for (int i=d; i<=500000; i++) {
            ans = min(ans,good[i]);
        }   
        cout << ans;
        if (t != 0) cout << '\n';
    }
}   