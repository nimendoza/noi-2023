#include <bits/stdc++.h>
using lli = unsigned long long int;

auto solve(int& n, std::vector<lli>& g, std::vector<lli>& h) {
    std::vector<lli> pg{g};
    for (int i{1}; i < n; ++i) {
        pg[i] += pg[i - 1];
    }

    std::vector<lli> ph{h};
    for (int i{1}; i < n; ++i) {
        ph[i] += ph[i - 1];
    }

    lli result{};
    for (int k{1}; k <= 2 * n; ++k) {
        lli max{};
        for (int i{}; i <= std::min(n, k); ++i) {
            for (int j{}; j <= std::min(n, k - i); ++j) {
                if (i && j) {
                    max = std::max(max, pg[i - 1] + ph[j - 1]);
                } else if (i) {
                    max = std::max(max, pg[i - 1]);
                } else if (j) {
                    max = std::max(max, ph[j - 1]);
                }
            }
        }

        result ^= max;
    }

    return result;
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<lli> g(n);
    for (lli& x : g) {
        std::cin >> x;
    }

    std::vector<lli> h(n);
    for (lli& x : h) {
        std::cin >> x;
    }

    std::cout << solve(n, g, h) << '\n';
}
