#include <bits/stdc++.h>

auto solve(const int& n, const std::vector<int>& a) {
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        std::vector<int> a(n);
        for (int& x : a) {
            std::cin >> x;
        }

        std::cout << solve(n, a) << '\n';
    }
}
