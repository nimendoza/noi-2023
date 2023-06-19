#include <bits/stdc++.h>
using gnt = __int128;

auto& operator <<(std::ostream& dest, gnt v) {
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

auto parse(const char* input) {
    auto find_e = [](const std::string& input) {
        for (std::size_t i{}; i < input.size(); ++i) {
            if (input[i] == 'e' || input[i] == 'E') {
                return gnt(i);
            }
        }

        return gnt(-1);
    };

    std::string string(input);
    auto endex{find_e(string)};

    gnt result{};
    gnt zero_count{};
    if (endex != -1) {
        std::vector<char> zeroes{};
        for (std::size_t i(endex + 1); i < string.size(); ++i) {
            zeroes.push_back(string[i]);
        }

        std::reverse(begin(zeroes), end(zeroes));

        for (std::size_t i{}; i < zeroes.size(); ++i) {
            zero_count += gnt(zeroes[i] - '0') * std::pow(10, i);
        }
    }

    std::vector<char> digits{};
    for (std::size_t i{}; i < (endex == -1 ? string.size() : endex); ++i) {
        digits.push_back(string[i]);
    }

    for (gnt i{}; i < zero_count; ++i) {
        digits.push_back('0');
    }

    std::reverse(begin(digits), end(digits));

    for (std::size_t i{}; i < digits.size(); ++i) {
        result += gnt(digits[i] - '0') * std::pow(10, i);
    }

    return result;
}

auto get_generator(std::default_random_engine& engine, gnt l, gnt r) {
    std::uniform_int_distribution<gnt> generator(l, r); generator(engine);

    return generator;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::default_random_engine engine(parse(argv[1]));

    auto N{get_generator(engine, 1, parse(argv[2]))};
    auto V{get_generator(engine, 1, parse(argv[3]))};
    auto limit{parse(argv[4])};

    gnt n{N(engine)};

    std::cout << n << '\n';

    for (int i{}; i < n; ++i) {
        std::cout << V(engine) << (i == n - 1 ? '\n' : ' ');
    }


    std::vector<gnt> h(n, V(engine));
    for (int i{}; i < n; ++i) {
        if (limit <= 0) {
            auto v{get_generator(engine, 1, h[i - 1])};
            h[i] = v(engine);
        } else {
            h[i] = V(engine);
            if (h[i] > h[i - 1]) {
                limit -= i;
            }
        }

        std::cout << h[i] << (i == n - 1 ? '\n' : ' ');
    }
}
