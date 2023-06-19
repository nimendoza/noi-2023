#include <bits/stdc++.h>

auto solve(const int& n, const int& h, const std::vector<int>& c) {
    std::vector<int> table(h + 1, INT_MAX); table[0] = 0;
    for (int i{1}; i <= h; ++i) {
        for (int j{}; j < n; ++j) {
            if (c[j] <= i) {
                if (table[i - c[j]] != INT_MAX && table[i - c[j]] + 1 < table[i]) {
                    table[i] = table[i - c[j]] + 1;
                }
            }
        }
    }

    return table[h];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int h; std::cin >> h;
    std::vector<int> c(n);
    for (int& x : c) {
        std::cin >> x;
    }

    std::cout << solve(n, h, c) << '\n';
}
