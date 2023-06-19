#include <bits/stdc++.h>
using vint = std::vector<int>;

auto solve(const int& m, const int& n, const std::string& s, const std::string& t) {
    std::vector<std::vector<vint>> dp(m + 1, std::vector<vint>(n + 1, vint(2, INT_MIN)));
    for (int i{m}; i >= 0; --i) {
        for (int j{n}; j >= 0; --j) {
            dp[i][j][1] = 0;

            if (i < m) {
                bool c{s[i] == 'O'};
                dp[i][j][c] = std::max(dp[i][j][c], dp[i + 1][j][!c] + 1);
            }

            if (j < n) {
                bool c{t[j] == 'O'};
                dp[i][j][c] = std::max(dp[i][j][c], dp[i][j + 1][!c] + 1);
            }
        }
    }

    int answer{};
    for (int i{}; i <= m; ++i) {
        for (int j{}; j <= n; ++j) {
            answer = std::max(answer, dp[i][j][0]);
        }
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m; std::cin >> m;
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::string t; std::cin >> t;

    std::cout << solve(m, n, s, t) << '\n';
}
