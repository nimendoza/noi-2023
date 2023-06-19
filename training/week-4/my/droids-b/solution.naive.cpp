#include <bits/stdc++.h>
using lli = long long int;

std::map<int, std::set<std::vector<int>>> partitions;

auto recurse(const std::vector<int>& coins, int n, int m, int k, int sum, std::vector<int> bag) {
    if (bag.size() > m) {
        return;
    }

    if (!sum) {
        std::sort(begin(bag), end(bag));
        partitions[k].insert(bag);

        return;
    }

    if (!n) {
        return;
    }

    recurse(coins, n - 1, m, k, sum, bag);

    bag.push_back(coins[n - 1]);
    recurse(coins, n, m, k, sum - coins[n - 1], bag);
}

auto& get_possible_setups(const int& n, const int& k) {
    if (!partitions[k].size()) {
        std::vector<int> coins{1, 2};

        recurse(coins, 2, n, k, k, {});
    }

    return partitions[k];
}

auto solve(const int& n, const int& k, const std::vector<lli>& b, const std::vector<lli>& d) {
    lli result{};
    for (auto v : get_possible_setups(n, k)) {
        while (v.size() <= n) {
            v.push_back(0);
        }

        std::sort(begin(v), end(v));

        do {
            lli sum{};
            for (int i{}; i < n; ++i) {
                if (v[i] == 1) {
                    sum += b[i];
                } else if (v[i] == 2) {
                    sum += b[i] + d[i];
                }
            }

            result = std::max(result, sum);
        } while (std::next_permutation(begin(v), end(v)));
    }

    return result;
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
