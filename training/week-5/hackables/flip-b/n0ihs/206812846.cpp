#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = n;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string s2 = s;
                for (int k = i; k <= j; k++) {
                    if (s2[k] == '0') s2[k] = '1';
                    else s2[k] = '0';
                }

                vector<int> a(n + 1);

                a[0] = 0;

                for (int i = 1; i <= n; i++) {
                    a[i] = a[i - 1] + (s2[i - 1] - '0');
                }

                for (int k = 0; k < n; k++) {
                    for (int l = k; l < n; l++) {
                        int cur = a[n];
                        cur -= a[l + 1] - a[k];
                        cur += (l - k + 1) - (a[l + 1] - a[k]);
                        
                        ans = min(ans, cur);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}
