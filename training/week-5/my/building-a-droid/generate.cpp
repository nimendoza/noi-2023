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

    auto Q{get_generator(engine, 1, parse(argv[2]))};

    gnt q{Q(engine)};

    std::cout << q << ' ';

    auto P2{get_generator(engine, 2, parse(argv[3]) - 1)};

    gnt p2{P2(engine)};

    std::cout << p2 << ' ';

    auto P3{get_generator(engine, p2 + 1, parse(argv[3]))};

    gnt p3{P3(engine)};

    std::cout << p3 << ' ';

    auto V1{get_generator(engine, 0, parse(argv[4]) - 2)};

    gnt v1{V1(engine)};

    std::cout << v1 << ' ';

    auto V2{get_generator(engine, v1 + 1, parse(argv[4]) - 1)};

    gnt v2{V2(engine)};

    std::cout << v2 << ' ';

    auto V3{get_generator(engine, v2 + 1, parse(argv[4]))};

    gnt v3{V3(engine)};

    std::cout << v1 << '\n';

    auto C{get_generator(engine, 1, parse(argv[5]))};

    for (gnt i{}; i < q; ++i) {
        std::cout << C(engine) << '\n';
    }
}
