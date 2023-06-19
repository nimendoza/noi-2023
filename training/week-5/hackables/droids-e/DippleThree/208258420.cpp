#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(int n, ll d, vector<ll> a){
    ll minn = d * (n - 1);
    ll mn = a[n - 1];
    ll mx = a[n - 1];
    for (int i = n - 2; i >= 1; i--){
        if (a[i] > mx){
            mx = a[i];
        }
        else if (a[i] < mn){
            mn = a[i];
        }
        minn = min(minn, mx - mn + d * (i));
    }
    mn = a[0];
    mx = a[0];
    for (int i = 0; i < n - 1; i++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        ll tmn = mn;
        ll tmx = mx;
        minn = min(minn, mx - mn + d * (n - 1 - i));
        for (int j = n - 1; j > i; j--){
            tmn = min(tmn, a[j]);
            tmx = max(tmx, a[j]);
            minn = min(minn, tmx - tmn + d * (j - i - 1));
        }
    }
    return minn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; ll d; cin >> n >> d;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, d, a) << "\n";
    }
}