#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    vector<ll> p(2), v(3);

    cin >> q >> p[0] >> p[1] >> v[0] >> v[1] >> v[2];

    vector<double> a(3);

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            a[i] = 1.0 / v[i]; 
        }
        else {
            a[i] = (double)p[i - 1] / v[i];
        }
    }

    while (q--) {
        ll c;
        cin >> c;

        ll ans = 0;

        while (c > 0) {
            ll cur = 0;
            for (int i = 1; i < 3; i++) {
                if (c >= p[i - 1] && a[i] < a[cur]) {
                    cur = i;
                }
            }
            if (cur == 0) {
                ans += v[cur] * c;
                c = 0;
            }
            else {
                ans += v[cur] * (c / p[cur - 1]);
                c %= p[cur - 1];
            }
        }

        cout << ans << "\n";
    }
}
