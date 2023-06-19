#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> v, int s){
    vector<ll> ssum(n);
    for (int i = 0; i < s; i++){
        ssum[0] += v[i];
    }
    for (int i = s; i < n; i++){
        ssum[i - s + 1] = ssum[i - s] + v[i] - v[i - s];
    }
    vector<ll> dp(n, 1e18);
    dp[s - 1] = ssum[0];
    for (int i = s; i < n; i++){
        for (int j = 1; j <= s; j++){
            dp[i] = min(dp[i], dp[i - j]);
        }
        dp[i] += ssum[i - s + 1];
    }
    return dp[n - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n, q; cin >> n >> q;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        while (q--){
            int s; cin >> s;
            cout << solve(n, v, s);
            if (q != 0) cout << " ";
        }
        cout << "\n";
    }
}