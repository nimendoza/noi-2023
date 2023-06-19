#include <bits/stdc++.h>
using vint = std::vector<int>;

auto solve(const std::string& s, const std::string& t) {
    int m(s.size());
    int n(t.size());

    std::vector<vint> dp(2, vint(n + 1, 0));

    int answer{};
    for (int i{1}; i <= m; ++i) {
        for (int j{1}; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                answer = std::max(answer, dp[i % 2][j]);
            } else {
                dp[i % 2][j] = 0;
            }
        }
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s; std::cin >> s;
    std::string t; std::cin >> t;

    std::cout << solve(s, t) << '\n';
}
