#include <bits/stdc++.h>
using lli = long long int;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int m; std::cin >> m;

    lli sum{};
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            sum += lli(i) * j;
        }
    }

    std::cout << sum << '\n';
}
