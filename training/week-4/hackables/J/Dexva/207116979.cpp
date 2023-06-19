#include <bits/stdc++.h>
using namespace std;

#define lln long long

// Week 4 - Spam & Han - Cards-A
// Status: All subtasks AC (200 pts.)
// Idea: Calculate most worth it thing to buy, then reduce from there
// Complexity: O(q)

int solve() {
    lln n; cin >> n;
    lln a[n];
    for (lln i=0;i<n;i++) cin >> a[i];

    vector<lln> arr;
    for (lln i=0;i<n;i++) {
        for (lln j=i;j<n;j++) {
            //from a[i]...a[j]
            lln sum = 0, max = 0;
            for (lln k=i;k<=j;k++) {
                sum += a[k];
                if (a[k]>max) max=a[k];
            }

            arr.push_back(sum-max);
            // cout << best << '\n';
        }
    }

    lln best = *max_element(arr.begin(), arr.end());

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int res = solve();
        cout << res << '\n';
    }

    return 0;
}