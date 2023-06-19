#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long int;

std::ostream &operator<<(std::ostream &dest, __int128 v) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp(v < 0 ? -v : v);
        char buffer[128];
        char *d = std::end(buffer);
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

__int128 MOD = 998244353;

__int128 modnegpos(__int128 a) {
    if (a < 0) {
        return ((a % MOD) + MOD) % MOD;
    } else {
        return a % MOD;
    }
}
__int128 minval;


int main() {
    int t;
    cin >> t;
    int n, w, k, f0;
    for (int p = 0; p < t; p++) {
        cin >> n >> w >> k >> f0;
        //get a array
        vector<__int128> As;
        As.resize(k);
        __int128 val;
        ll temp;
        for (int i = 0; i < k; i++) {
            cin >> temp;
            val = temp;
            As[i] = val;
        }

        //create f values I need CAREFUL ABOUT THE MOD!
        vector<__int128> fvals;
        fvals.resize(n + 1);
        fvals[0] = f0;
        for (int i = 1; i <= n; i++) {
            fvals[i] = ((fvals[i - 1] % k) * (fvals[i - 1] % k)) % k;
        }

        vector<__int128> Droids;
        __int128 total = 0, assignval;//for later
        for (int i = 1; i <= n; i++) {
            assignval = As.at(fvals.at(i)) + (w * i);
            Droids.push_back(assignval);
            total += assignval;
        }
        minval = 0;
        __int128 minrn = 0;
        for(auto elem: Droids){
            minrn = min(minrn + elem, elem);
            minval = min(minval,minrn);
        }
        cout << modnegpos(minval) << endl;
    }
    return 0;
}
