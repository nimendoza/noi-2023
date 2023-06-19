#include <bits/stdc++.h>
using namespace std;

// Week 4 - Spam & Han - Flip B
// Status: WA (might miss some edge case)
// Idea: Double brute force - O(n^2)

string move(string s, int n, int m) {
    int p1[n+1]; p1[0] = 0;
    int p0[n+1]; p0[0] = 0;
    for (int i=1;i<n+1;i++) {
        if (s[i-1]=='1') p1[i] = p1[i-1] + 1;
        else p1[i] = p1[i-1];

        if (s[i-1]=='0') p0[i] = p0[i-1] + 1;
        else p0[i] = p0[i-1];
    }

    if (p1[n]==0 && m==1) {
        s[0] = '1';
        return s;
    }
    else if (n==1 && s[0]=='0' && m==2) {
        s[0] = '1';
        return s;
    }

    int best = 0, besti = 0, bestj = 0;
    bool moved = false;
    string best_s = s;
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            int a = p1[j+1] - p1[i]; //1s
            int b = p0[j+1] - p0[i]; //0s

            if (a-b > best) {
                best = a-b;
                besti = i;
                bestj = j;
                moved = true;
            }
        }
    }

    if (moved) {
        for (int l=besti;l<=bestj;l++) {
            if (s[l]=='1') s[l] = '0';
            else s[l] = '1';
        }
    }

    return s;
}

int solve() {
    int n; cin >> n;
    string s; cin >> s;

    s = move(s, n, 1);
    // cout << s <<'\n';
    s = move(s, n, 2);
    // cout << s <<'\n';

    int ans = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='1') ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}