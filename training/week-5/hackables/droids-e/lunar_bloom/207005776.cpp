#include <bits/stdc++.h>
using lli = long long int;

auto solve(int& n, lli& d, lli*& h) {
    lli result(LONG_LONG_MAX);
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            if (!(j - i + 1 < n)) {
                break;
            }

            lli min{std::min(
                (i ? *std::min_element(h, h + i) : LONG_LONG_MAX),
                (j == n - 1 ? LONG_LONG_MAX : *std::min_element(h + j + 1, h + n))
            )};

            lli max{std::max(
                (i ? *std::max_element(h, h + i) : LONG_LONG_MIN),
                (j == n - 1 ? LONG_LONG_MIN : *std::max_element(h + j + 1, h + n))
            )};

            if (min == LONG_LONG_MAX) {
                min = 0;
            }

            if (max == LONG_LONG_MIN) {
                max = 0;
            }

            result = std::min(result, d * (j - i + 1) + max - min);
        }
    }

    return result;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        lli d; std::cin >> d;
        lli* h{new lli[n]};
        for (int i{}; i < n; ++i) {
            std::cin >> h[i];
        }

        std::cout << solve(n, d, h) << '\n';
    }
}
