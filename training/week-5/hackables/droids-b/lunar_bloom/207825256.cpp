#include <bits/stdc++.h>
using lli = long long int;

const int MAX(4e3);

struct ternary_bit {
    std::bitset<2> value;

    ternary_bit() : value(0) {}

    auto print() {
        return value[0] * 1 - value[1] * 2;
    }

    bool operator ==(int x) {
        return print() == x;
    }
};

auto solve(const int& n, const int& k, std::vector<lli>& b, const std::vector<lli>& d) {
    std::pair<lli, ternary_bit[MAX]> dp[k + 1];
    for (int i{}; i <= k; ++i) {
        dp[i].first = 0LL;
        for (int j{}; j < n; ++j) {
            dp[i].second[j] = ternary_bit();
        }
    }

    for (int w{}; w <= k; ++w) {
        for (int i{}; i < 2 * n; ++i) {
            int x{i < n ? 1 : 2};
            if (x <= w) {
                std::pair<lli, int> to_add{};
                if (dp[w - x].second[i % n].print() == 0) {
                    to_add = x == 1 ? std::make_pair(b[i], 1) : std::make_pair(b[i % n] + d[i % n], -1);
                } else if (dp[w - x].second[i % n].print() == 1) {
                    to_add = std::make_pair(d[i % n], -1);  // x == 1 ? std::make_pair(0LL, 1) : std::make_pair(d[i % n], -1);
                } else if (dp[w - x].second[i % n].print() == -1) {
                    to_add = {0LL, -1};
                } else {
                    assert(false);
                }

                if (dp[w].first < (dp[w - x].first + to_add.first)) {
                    // std::cerr << w << ' ' << i << '\n';
                    // std::cerr << "Adding " << to_add.first << '\n';
                    dp[w].first = dp[w - x].first + to_add.first;
                    for (int j{}; j < n; ++j) {
                        dp[w].second[j] = dp[w - x].second[j];
                    }

                    if (to_add.second == 1) {
                        dp[w].second[i % n].value[0] = 1;
                        dp[w].second[i % n].value[1] = 0;

                        assert(dp[w].second[i % n].print() == 1);
                    } else if (to_add.second == -1) {
                        dp[w].second[i % n].value[0] = 1;
                        dp[w].second[i % n].value[1] = 1;
                        
                        assert(dp[w].second[i % n].print() == -1);
                    } else {
                        assert(false);
                    }
                } else {
                    // std::cerr << "Not adding " << to_add.first << '\n';
                }
            }
        }
    }

    // for (int i{}; i < n; ++i) {
    //     std::cerr << dp[k].second[i].print() << ' ';
    // }

    // std::cerr << '\n';

    return dp[k].first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int k; std::cin >> k;
        std::vector<lli> b(n);
        for (lli& x : b) {
            std::cin >> x;
        }

        std::vector<lli> d(n);
        for (lli& x : d) {
            std::cin >> x;
        }

        std::cout << solve(n, k, b, d) << '\n';
    }
}
