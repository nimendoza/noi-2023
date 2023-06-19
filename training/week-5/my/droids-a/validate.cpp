#include <bits/stdc++.h>
using gnt = __int128;

auto parse(const std::string& input) {
    auto find_e = [&]() {
        for (std::size_t i{}; i < input.size(); ++i) {
            if (input[i] == 'e' || input[i] == 'E') {
                return gnt(i);
            }
        }

        return gnt(-1);
    };

    auto endex{find_e()};

    gnt result{};
    gnt zero_count{};
    if (endex != -1) {
        std::vector<char> zeroes{};
        for (std::size_t i(endex + 1); i < input.size(); ++i) {
            zeroes.push_back(input[i]);
        }

        std::reverse(begin(zeroes), end(zeroes));

        for (std::size_t i{}; i < zeroes.size(); ++i) {
            zero_count += gnt(zeroes[i] - '0') * std::pow(10, i);
        }
    }

    std::vector<char> digits{};
    for (std::size_t i{}; i < (endex == -1 ? input.size() : endex); ++i) {
        digits.push_back(input[i]);
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

auto input() {
    std::string input;
    if (!(std::cin >> input)) {
        std::cerr << "No input was received.\n";
        exit(EXIT_FAILURE);
    }

    return parse(input);
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    gnt N{parse(argv[2])};
    gnt V{parse(argv[3])};
    gnt L{parse(argv[4])};
    
    std::freopen(argv[1], "r", stdin);

    gnt n{input()};
    if (N < n) {
        std::cerr << "Value of n is invalid.\n";
        exit(EXIT_FAILURE);
    }

    std::vector<gnt> g(n);
    for (gnt& x : g) {
        x = input();

        if (V < x) {
            std::cerr << "Value of g[i] is invalid.\n";
            exit(EXIT_FAILURE);
        }
    }

    std::vector<gnt> h(n);
    for (gnt& x : h) {
        x = input();

        if (V < x) {
            std::cerr << "Value of h[i] is invalid.\n";
            exit(EXIT_FAILURE);
        }
    }

    for (gnt i{}; i < n - 1; ++i) {
        if (h[i] * (2 * h[i] + 1) < h[i + 1] * (h[i] + h[i + 1] + 1)) {
            L -= i + 1;
        }

        if (L < 0) {
            std::cerr << "The constraint for h[i] was not followed.\n";
            exit(EXIT_FAILURE);
        }
    }

    std::cerr << "The input is valid! :)\n";
}
