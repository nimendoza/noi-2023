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
    std::string v;

    value() : v("-1") {}
};

std::map<std::string, value> dp;

std::array<char, 64> constexpr encode_table{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', '+', '/'};

std::map<char, int> decode_table{};

auto convert(gnt g) {
    std::vector<char> result{};
    while (g) {
        result.push_back(encode_table[g % 64]);
        g /= 64;
    }

    return std::string(begin(result), end(result));
}

auto convert(std::string s) {
    gnt result{};
    for (int i{}; i < s.size(); ++i) {
        result += decode_table[s[i]] * gnt(std::pow(64, i));
    }

    return result;
}

auto solve(std::array<lli, 3>& p, std::array<lli, 3>& v, lli c, gnt n) {
    if (dp[convert(gnt(c))].v != "-1") {
        return convert(dp[convert(gnt(c))].v);
    }

    if (!c) {
        return n;
    }

    return convert(dp[convert(gnt(c))].v = convert(std::max(
        solve(p, v, c - p[0], n) + v[0],
        std::max(
            (c >= p[1] ? solve(p, v, c - p[1], n) + v[1] : gnt{}),
            (c >= p[2] ? solve(p, v, c - p[2], n) + v[2] : gnt{})
        )
    )));
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i{}; i < encode_table.size(); ++i) {
        decode_table[encode_table[i]] = i;
    }

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
