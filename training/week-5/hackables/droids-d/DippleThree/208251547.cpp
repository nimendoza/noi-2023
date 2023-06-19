#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 998244353;

ll solve(int n, vector<ll> &a){
    ll summ = 0;
    for (int i = 0; i < n; i++){
        ll mn = 0;
        ll currsum = 0;
        for (int j = i; j < n; j++){
            currsum += a[j];
            currsum = min(currsum, 0LL);
            mn = min(mn, currsum);
            summ += mn;
        }
        summ %= mod;
    }
    return (summ % mod + mod) % mod;
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