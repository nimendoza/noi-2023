#include <bits/stdc++.h>
using lli = long long int;
using gnt = __int128;

auto& operator <<(std::stringstream& dest, gnt v) {
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

struct fraction {
    gnt numerator;
    gnt denominator;

    fraction(gnt n, gnt d) : numerator{n}, denominator{d} {}

    friend bool operator <(fraction a, fraction b) {
        if (a.denominator == b.denominator) {
            return a.numerator < b.numerator;
        }

        if (a.numerator * b.denominator == b.numerator * a.denominator) {
            return a.denominator > b.denominator;
        }
        
        return a.numerator * b.denominator < b.numerator * a.denominator;
    }

    auto str() {
        simplify();

        std::stringstream n{}; n << numerator;
        std::stringstream d{}; d << denominator;
        std::stringstream r{}; r << n.str() << '/' << d.str();
        
        return r.str();
    }

    void simplify() {
        auto k{std::__gcd(numerator, denominator)};

        numerator /= k;
        denominator /= k;
    }
};

auto solve(const int& n, const int& l, const std::vector<lli>& v) {
    gnt** dp{new gnt*[n + 1]};
    for (int i{1}; i <= n; ++i) {
        dp[i] = new gnt[n - i + 2];

        dp[1][i] = v[i - 1];
    }

    fraction max(-1, 1);
    if (l == 1) {
        max.numerator = *std::max_element(dp[1] + 1, dp[1] + n + 1);
    }

    for (int k{2}; k <= n; ++k) {
        for (int i{1}; i <= n - k + 1; ++i) {
            dp[k][i] = dp[k - 1][i] + dp[1][k + i - 1];
        }

        if (l <= k) {
            max = std::max(max, fraction(*std::max_element(dp[k] + 1, dp[k] + n - k + 2), k));
        }
    }

    return max.str();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int l; std::cin >> l;
        std::vector<lli> v(n);
        for (lli& x : v) {
            std::cin >> x;
        }

        std::cout << solve(n, l, v) << '\n';
    }
}
