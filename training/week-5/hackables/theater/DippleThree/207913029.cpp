#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(int n, vector<pair<ll, ll>> &a){
    vector<pair<ll, ll>> b(n);
    for (int i = 0; i < n; i++){
        b[i] = {a[i].second, a[i].first};
    }
    sort(b.begin(), b.end());
    int ans = 0;
    ll recent = 0;
    for (int i = 0; i < n; i++){
        if (b[i].second > recent){
            ans++;
            recent = b[i].first;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }
        cout << solve(n, a) << "\n";
    }
}