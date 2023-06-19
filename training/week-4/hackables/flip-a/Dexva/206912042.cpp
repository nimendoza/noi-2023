#include <bits/stdc++.h>
using namespace std;

// Week 4 - Spam & Han - Flip A (https://codeforces.com/gym/444888/problem/A)
// Status: Subtask 1 AC, Subtask 2 AC, Subtack 3 TLE
// Idea: Find longest contigious substring containing 1's only (this has edge cases wrong answers)

int solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ones = 0, best = 0, contigious = 0;
    for (int i=1;i<n+1;i++) {
        if (s[i-1]=='1') {
            ones++;
            contigious++;
        }
        else {
            if (contigious>best) best = contigious;
            contigious = 0;
        }
    }
    if (contigious>best) best = contigious;
    contigious = 0;

    return ones-best;
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