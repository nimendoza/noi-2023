#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define lln long long
#define lld long double
#define INF (unsigned)!((int)0)

// Week 4 - Spam & Han - (S) Battle of Yavin
// Status:
// Idea: similar to finding most "worth it" of building-a-droid (this is a generalized version of that problem)
// Complexity: O(n log n)

int solve() {
    lln n, d; cin >> n >> d;
    vector<tuple<lln, lln, lld> > droids;
    for (lln i=0; i<n; i++) {
        lln a, b; cin >> a >> b;
        droids.push_back(make_tuple(a, b, a*1.0/b));
    }

    sort(droids.begin(), droids.end(),
    [](const tuple<lln,lln, lld>& a, const tuple<lln, lld, lld>& b) -> bool
    {
        return std::get<2>(a) > std::get<2>(b);
    });

    lln ans = 0;
    for (lln i=0; i<n; i++) {
        ans += floor(d/get<1>(droids[i])) * get<0>(droids[i]);
        d %= get<1>(droids[i]);
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
}