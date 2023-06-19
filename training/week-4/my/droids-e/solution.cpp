#include <bits/stdc++.h>
using lli = long long int;

auto solve(const int& n, const lli& d, const std::vector<lli>& h) {
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        lli d; std::cin >> d;
        std::vector<lli> h(n);
        for (lli& x : h) {
            std::cin >> x;
        }

        std::cout << solve(n, d, h) << '\n';
    } 
}
