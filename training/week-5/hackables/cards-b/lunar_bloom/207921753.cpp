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
    std::vector<gnt> sum(begin(v), end(v));
    for (int i{1}; i < n; ++i) {
        sum[i] += sum[i - 1];
    }

    fraction best(-1, 1);
    for (int k{l}; k <= n; ++k) {
        gnt max{sum[k - 1]};
        for (int i{k}; i < n; ++i) {
            max = std::max(max, sum[i] - sum[i - k]);
        }

        best = std::max(best, fraction(max, k));
    }

    return best.str();
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
