#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> pg = {0};
    vector<ll> ph = {0};

    ll pgi = 0;
    ll phi = 0;
    for (int i = 0; i < n; i++) {
        ll gi;
        cin >> gi;

        pgi += gi;
        pg.push_back(pgi);
    }

    for (int i = 0; i < n; i++) {
        ll hi;
        cin >> hi;

        phi += hi;
        ph.push_back(phi);
    }

    ll ans = max(pg[1],ph[1]);

    if (n > 1) {
        for (int k = 2; k < 2*n + 1; k++){
            ll ai = 0;
            int i, j;
            if (k < n) {
                i = k;
                j = 0;
                do {
                    ai = max(ai,pg[i]+ph[j]);
                    i--;
                    j++;
                } while (j < k + 1);
            } else {
                i = n;
                j = k - n;
                do {
                    ai = max(ai,pg[i]+ph[j]);
                    i--;
                    j++;
                } while (j < n + 1);
            }
            ans ^= ai;
        }
    }

    cout << ans << endl;

    return 0;
}