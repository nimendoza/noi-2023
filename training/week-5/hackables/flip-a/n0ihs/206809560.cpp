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

        vector<int> a(n + 1);

        a[0] = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] + (s[i - 1] - '0');
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cur = a[n];
                cur -= a[j + 1] - a[i];
                cur += (j - i + 1) - (a[j + 1] - a[i]);
                ans = min(ans, cur); 
            }
        }

        cout << ans << "\n";
    }
}
