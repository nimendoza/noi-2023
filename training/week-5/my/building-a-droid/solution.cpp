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

struct fraction {
    gnt numerator;
    gnt denominator;

    fraction(gnt n, gnt d) : numerator{n}, denominator{d} {}

    friend bool operator <(fraction a, fraction b) {
        return a.numerator * b.denominator < b.numerator * a.denominator;
    }
};

auto solve(std::array<lli, 3>& p, std::array<lli, 3>& v, lli c, gnt n) {
    std::priority_queue<fraction> pq{};
    for (int i{}; i < 3; ++i) {
        pq.push(fraction(v[i], p[i]));
    }

    gnt result{};
    while (pq.size()) {
        fraction top{pq.top()}; pq.pop();
        result += c / top.denominator * top.numerator;
        c %= top.denominator;
    }

    return result;
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
