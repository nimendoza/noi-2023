#include <bits/stdc++.h>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

#define lln long long

// Week 4 - Spam & Han - (L)Theater
// Status: 1
// Idea: 
// Complexity: 

int solve() {
    lln n, ans = 0; cin >> n;
    vector<tuple<lln, lln> > arr;
    for (int i=0;i<n;i++) {
        lln l, r; cin >> l >> r;
        arr.push_back(std::make_tuple(l,r));
    }

    sort(arr.begin(),arr.end(),
    [](const tuple<lln,lln>& a,
    const tuple<lln, lln>& b) -> bool
    {
        return std::get<1>(a) < std::get<1>(b);
    });

    lln curend = 0;
    for (lln i=0;i<n;i++) {
        // cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << '\n';
        if(get<0>(arr[i]) > curend) {
            ans++;
            curend = get<1>(arr[i]);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lln t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}