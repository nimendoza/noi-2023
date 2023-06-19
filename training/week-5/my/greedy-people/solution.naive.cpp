#include <bits/stdc++.h>
using lli = long long int;

auto count(const int& n, const std::vector<int>& a) {
    lli sum{std::accumulate(begin(a), end(a), 0LL)};
    
    int count{};
    for (int i{}; i < n; ++i) {
        if (sum == a[i] + a[i]) {
            count++;
        }
    }

    return count;
}

auto solve(const int& n, const std::vector<int>& a) {
    lli max(1e2);
    lli min(-1e2);
    std::vector<int> b(begin(a), end(a));

    int result{};
    for (int i{}; i < n; ++i) {
        for (lli number{min}; number <= max; ++number) {
            b[i] = number;
            result = std::max(result, count(n, b));
        }

        b[i] = a[i];
    }

    return result;
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
