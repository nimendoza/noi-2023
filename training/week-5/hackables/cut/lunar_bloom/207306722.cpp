#include <bits/stdc++.h>

auto last(const std::map<int, int>& m) {
    return --end(m);
}

auto solve(const int& n, const int& c, const std::vector<int>& l) {
    std::map<int, int> count{};
    for (int x : l) {
        count[x]++;
    }

    for (int i{c}; i && i >= last(count)->second && last(count)->first >= 2;) {
        auto [value, amount]{*last(count)};
        count[value / 2 + (value & 1)] += amount;
        count[value / 2] += amount;
        count.erase(last(count));

        i -= amount;
    }

    return last(count)->first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int c; std::cin >> c;
        std::vector<int> l(n);
        for (int& x : l) {
            std::cin >> x;
        }

        std::cout << solve(n, c, l) << '\n';
    }
}
