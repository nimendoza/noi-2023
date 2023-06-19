#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(int n, vector<ll> &a){
    int mx = 1;
    ll summ = 0;
    map<ll, int> cnt;
    for (int i = 0; i < n; i++){
        summ += a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++){
        int curr = cnt[summ - a[i]] + ((a[i] == summ - a[i]) ? 0 : 1);
        mx = max(mx, curr);
    }
    for (auto &[k, v]: cnt){
        mx = max(mx, v);
    }
    if (cnt[a[0]] == n){
        if (a[0] == 0 || n <= 2) return n;
        return n - 1;
    }
    return mx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> a(n);
        for (ll &i: a) cin >> i;
        cout << solve(n, a) << "\n";
    }
}