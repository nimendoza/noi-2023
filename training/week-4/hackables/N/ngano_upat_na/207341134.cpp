#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void sol() {
    int n;
    cin >> n;
    vector<ll> v(n);
    multiset<ll> ms;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        ms.insert(v[i]);
    }   
    int ans = 0;
    for (int i=0; i<n; i++) {
        int a = ms.count(v[i]);
        ans = max(ans,a);
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