#include <bits/stdc++.h>
using vint = std::vector<int>;

struct gym {
    int x;
    int l;

    gym() : x{}, l{} {}
    gym(const int& x, const int& l) : x{x}, l{l} {}

    friend bool operator < (const gym& lhs, const gym& rhs) {
        if (lhs.x + lhs.l == rhs.x + rhs.l) {
            return lhs.l < rhs.l;
        }
        
        return lhs.x + lhs.l < rhs.x + rhs.l;
    }
};

struct data {
    int count;
    int level;

    data() : count{}, level{} {}
    data(const int count, const int level) : count{count}, level{level} {}
};

auto solve(const int& n, const vint& x, const vint& l) {
    std::vector<gym> gyms(n);
    for (int i{}; i < n; ++i) {
        gyms[i] = gym(x[i], l[i]);
    }

    std::sort(begin(gyms), end(gyms));

    std::vector<std::vector<data>> dp(n, std::vector<data>(n, data(0, -1)));
    for (int i{}; i < n; ++i) {
        dp[0][i] = data(1, gyms[i].x);
        dp[i][0] = data(1, gyms[i].x);
    }

    for (int i{1}; i < n; ++i) {
        for (int j{1}; j < n; ++j) {
            if (dp[i - 1][j - 1].level <= gyms[i].l
                && (dp[i - 1][j - 1].level + gyms[i].x
                    < dp[i - 1][j].level
            )) {
                dp[i][j].level = dp[i - 1][j - 1].level + gyms[i].x;
                dp[i][j].count = dp[i - 1][j - 1].count + 1;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (auto a : dp) {
        for (auto b : a) {
            std::cerr << '(' << b.count << ", " << b.level << ")\t";
        }

        std::cerr << '\n';
    }

    return dp[n - 1][n - 1].count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<int> x(n);
    for (int& y : x) {
        std::cin >> y;
    }

    std::vector<int> l(n);
    for (int& y : l) {
        std::cin >> y;
    }

    std::cout << solve(n, x, l) << '\n';
}
