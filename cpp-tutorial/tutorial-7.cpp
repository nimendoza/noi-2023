#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    
    int sum{};
    for (int i{1}; i <= n; ++i) {
        if (!(n % i) && (i % 2)) {
            sum += i;
        }
    }

    std::cout << sum << '\n';
}
