#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++){
        int mnj = max(0, i - n);
        int mxj = min(i, n);
        ll mx = 0;
        for (int j = mnj; j <= mxj; j++){
            mx = max(mx, a[j] + b[i - j]);
        }
        ans ^= mx;
    }
    cout << ans << "\n";
}