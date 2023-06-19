#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a){
    ll maxx = 0;
    for (int i = 0; i < n; i++){
        ll summ = 0;
        ll mx = 0;
        for (int j = i; j < n; j++){
            summ += a[j];
            mx = max(mx, a[j]);
            maxx = max(maxx, summ - mx);
        }
    }
    return maxx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << "\n";
    }
}