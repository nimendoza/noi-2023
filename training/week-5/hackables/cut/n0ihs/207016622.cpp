#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, c;
        cin >> n >> c;

        vector<ll> a;

        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < c; i++) {
            if (a[n - 1] == 1) break;
            if (a[n - 1] % 2 == 0) {
                a[n - 1] = a[n - 1] / 2;
                a.push_back(a[n - 1]);
                n++;
            }
            else {
                a[n - 1] = a[n - 1] / 2;
                a.push_back(a[n - 1] + 1);
                n++;
            }
            sort(a.begin(), a.end());
        }

        cout << a[n - 1] << "\n";
    }
}

