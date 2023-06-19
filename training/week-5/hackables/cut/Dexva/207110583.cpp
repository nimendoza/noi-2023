#include <bits/stdc++.h>
using namespace std;

#define lln long long 

// Week 4 - Spam & Han - Cut
// Status: 
// Idea: Cutting strategy is to half the longest at each turng i <= c
// Complexity: O(c nlogn) ??

int solve() {
    lln n, c; cin >> n >> c;
    vector<lln> arr;

    for (lln i=0;i<n;i++) {
        lln x; cin >> x;
        arr.push_back(x);
    }

    while (c--) {
        bool changed = false;

        lln ind=0, val = 0;
        for (lln i=0;i<arr.size();i++) {
            if (arr[i]>val) {
                ind = i;
                val = arr[ind];
            }
        }
        if (val>1) {
            lln a=floor(val/2.0), b=ceil(val/2.0);
            arr.erase(arr.begin()+ind);
            arr.push_back(a);
            arr.push_back(b);
        } else break;

        // for (lln i=0;i<arr.size();i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << '\n';
    }

    lln max = 0;
    for (lln i=0;i<arr.size();i++) {
        // cout << arr[i] << " ";
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    // cout << '\n';
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        int ans = solve();
        cout << ans << '\n';
    }

}