#include <bits/stdc++.h>
using namespace std;

// Week 4 - Spam & Han - Flip A (https://codeforces.com/gym/444888/problem/A)
// Status: Subtask 1 AC, Subtask 2 AC, Subtack 3 TLE
// Idea: Brute force with prefix sums optimization - O(n^2) complexity

string move2(string s, int n) {
    string s2 = s;
    int p1[n+1]; p1[0] = 0;
    int p0[n+1]; p0[0] = 0;
    for (int i=1;i<n+1;i++) {
        if (s[i-1]=='1') p1[i] = p1[i-1] + 1;
        else p1[i] = p1[i-1];

        if (s[i-1]=='0') p0[i] = p0[i-1] + 1;
        else p0[i] = p0[i-1];
    }

    int best = 0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int a = p1[j+1] - p1[i]; //1s
            int b = p0[j+1] - p0[i]; //0s

            if (a-b > best) {
                best = a-b;
                s2 = s;
                for (int k=i;k<=j;k++) {
                    if (s[k]=='1') s2[k] = '0';
                    else s2[k] = '1';
                }
            }

        }
    }
    return s2;
}

int move(string s, int n) {
    // int p1[n+1]; p1[0] = 0;
    // int p0[n+1]; p0[0] = 0;
    // for (int i=1;i<n+1;i++) {
    //     if (s[i-1]=='1') p1[i] = p1[i-1] + 1;
    //     else p1[i] = p1[i-1];

    //     if (s[i-1]=='0') p0[i] = p0[i-1] + 1;
    //     else p0[i] = p0[i-1];
    // }
    int ones = 0;
    for (int k=0;k<n;k++) {
        if (s[k]=='1') ones++;
    }

    int best = 0;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            string s2 = s;
            for (int k=i;k<=j;k++) {
                if (s[k]=='1') s2[k] ='0';
                else s2[k] ='1';
            }
            // cout << s2 << '\n';
            string res = move2(s2, n);

            // cout << res << '\n';

            int counto = 0;
            for (int k=0;k<s.length();k++) {
                if (res[k]=='0') counto++;
            }

            if (counto > best) best = counto;
        }
    }

    return n-best;
}

int solve() {
    int n; cin >> n;
    string s; cin >> s;

    return move(s, n);
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