#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// typedef long double ld;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int c; cin >> c;
        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int l = 1, r = (1 << 30);
        while (l < r){
            ll m = (l + r) / 2;
            ll cnt = 0;
            for (int i = 0; i < n; i++){
                cnt += (a[i] - 1LL) / m;
            }
            if (cnt > c){
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << l << "\n";
    }
}