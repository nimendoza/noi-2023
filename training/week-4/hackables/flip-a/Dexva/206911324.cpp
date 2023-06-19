#include <bits/stdc++.h>
using namespace std;

// Week 4 - Spam & Han - Flip A (https://codeforces.com/gym/444888/problem/A)
// Status: 
// Idea: 

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    int p1[n+1]; p1[0] = 0;
    int p0[n+1]; p0[0] = 0;
    for (int i=1;i<n+1;i++) {
        if (s[i-1]=='1') p1[i] = p1[i-1] + 1;
        else p1[i] = p1[i-1];

        if (s[i-1]=='0') p0[i] = p0[i-1] + 1;
        else p0[i] = p0[i-1];
    }

    // for (int i=0;i<n+1;i++) {
    //     cout << p1[i] << " ";
    // }
    // cout << '\n';
    // for (int i=0;i<n+1;i++) {
    //     cout << p0[i] << " ";
    // }
    // cout << '\n';

    int best = 0;
    string best_s = s;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int a = p1[j+1] - p1[i]; //1s
            int b = p0[j+1] - p0[i]; //0s

            // best_s = s.substr(i, j-i+1);

            if (a-b > best) best = a-b;

            // cout << a << " " << b << " " << best_s << '\n';
        }
    }

    // cout << best_s << '\n';

    return p1[n]-best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int result = solve();
        cout << result << '\n';
    }

    return 0;
}