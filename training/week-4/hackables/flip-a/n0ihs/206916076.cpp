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

        int ans = 1, cur = 0, ones = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
                cur++;
            }
            else {
                cur = 0;
            }
            ans = max(ans, cur);
        }

        cout << ones - ans << "\n";
    }
}
