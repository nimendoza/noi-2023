#include <bits/stdc++.h>
using lli = long long int;

auto solve(const int& n, const lli& d, const std::vector<lli>& h) {
    lli result{*std::max_element(begin(h), end(h)) - *std::min_element(begin(h), end(h))};
    for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
            if (!(j - i + 1 < n)) {
                break;
            }

            lli min{std::min(
                (i ? *std::min_element(begin(h), begin(h) + i) : LONG_LONG_MAX),
                (j == n - 1 ? LONG_LONG_MAX : *std::min_element(begin(h) + j + 1, begin(h) + n))
            )};

            lli max{std::max(
                (i ? *std::max_element(begin(h), begin(h) + i) : LONG_LONG_MIN),
                (j == n - 1 ? LONG_LONG_MIN : *std::max_element(begin(h) + j + 1, begin(h) + n))
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        lli d; std::cin >> d;
        std::vector<lli> h(n);
        for (lli& x : h) {
            std::cin >> x;
        }

        std::cout << solve(n, d, h) << '\n';
    } 
}
