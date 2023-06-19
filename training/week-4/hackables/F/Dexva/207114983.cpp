#include <bits/stdc++.h>
using namespace std;

#define unt __int128
#define lln long long
#define lld long double

// Week 4 - Spam & Han - Building a Droid
// Status: S
// Idea: Calculate most worth it thing to buy, then reduce from there
// Complexity: O(q)

std::ostream& operator <<(std::ostream& dest, __int128 v) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp(v < 0 ? -v : v);
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);

        if (v < 0) {
            --d;
            *d = '-';
        }
        
        int len(std::end(buffer) - d);
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }

    return dest;
}

void solve() {
    lld q, p2, p3, v1, v2, v3;
    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;
    lld p[3] = {1, p2, p3};
    lld v[3] = {v1, v2, v3};

    //calculating most worth
    string order = "";
    lld e1 = v1/1;
    lld e2 = v2/p2;
    lld e3 = v3/p3;
    
    if (e1 >= e2 && e2 >= e3) order = "012";
    else if (e1 >= e3 && e3 >= e2) order = "021";
    else if (e2 >= e1 && e1 >= e3) order = "102";
    else if (e2 >= e3 && e3 >= e1) order = "120";
    else if (e3 >= e1 && e1 >= e2) order = "201";
    else if (e3 >= e2 && e2 >= e1) order = "210";

    // cout << order << '\n';

    while (q--) {
        lln c; cin >> c;
        unt ans = 0;
        for (int i=0;i<3;i++) {
            int k = int(order[i])-int('0');
            lln val = floor(c / p[k]);
            ans += v[k]*val;
            c -= val*p[k];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}