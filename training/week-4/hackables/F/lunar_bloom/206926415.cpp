#include <bits/stdc++.h>
using lli = long long int;
using gnt = __int128;

std::ostream& operator <<(std::ostream& dest, gnt v) {
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

struct value {
    gnt v;

    value() : v(-1) {}
};

std::map<lli, value> dp;

auto solve(std::array<lli, 3>& p, std::array<lli, 3>& v, lli c, gnt n) {
    if (dp[c].v != -1) {
        return dp[c].v;
    }

    if (!c) {
        return n;
    }

    return dp[c].v = std::max(
        solve(p, v, c - p[0], n) + v[0],
        std::max(
            (c >= p[1] ? solve(p, v, c - p[1], n) + v[1] : gnt{}),
            (c >= p[2] ? solve(p, v, c - p[2], n) + v[2] : gnt{})
        )
    );
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q; std::cin >> q;
    std::array<lli, 3> p{1, 2, 3}; std::cin >> p[1] >> p[2];
    std::array<lli, 3> v{1, 1, 1};
    for (lli& x : v) {
        std::cin >> x;
    }

    for (int _{}; _ < q; ++_) {
        lli c; std::cin >> c;
        std::cout << solve(p, v, c, 0) << '\n';
    }
}
