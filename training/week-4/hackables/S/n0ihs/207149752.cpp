#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<tuple<int, int>> a(n);
        vector<double> b(n);

        for (int i = 0; i < n; i++) {
            cin >> get<0>(a[i]) >> get<1>(a[i]);
            b[i] = (double)get<1>(a[i]) / get<0>(a[i]);
        }

        int ans = 0;
        while (d >= get<1>(a[0])) {
            int cur = -1;
            for (int i = 0; i < n; i++) {
                if ((cur == -1 || b[i] < b[cur]) && d >= get<1>(a[i])) {
                    cur = i;
                }
            }
            ans += get<0>(a[cur]) * (d / get<1>(a[cur]));
            d %= get<1>(a[cur]);
        }

        cout << ans << "\n";
    }
}
