#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll inf = -9e18;

void sol() {
    int n;
    cin >> n;
    ll sum = 0, best = inf, r = -1;
    vector<ll> v(n);
    for (auto &e:v) cin >> e;
    for (int i=0; i<n; i++) {
        ll add = sum+v[i];
        sum = max(v[i],add);
        if (best <= sum) {
            best = sum;
            r = i;
        }   
    }
    
    int l = 0;
    sum = 0;
    for (int i=r; i>=0; i--) {
        sum += v[i];
        if (sum == best) {
            l = i;
            break;
        }   
    }   
    vector<ll> p;
    for (int i=l; i<=r; i++) p.push_back(v[i]);
    
    sort(p.rbegin(),p.rend());
    best -= p[0];
    cout << best;
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