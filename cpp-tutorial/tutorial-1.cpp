#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a; std::cin >> a;
    int b; std::cin >> b;
    int c; std::cin >> c;
    std::cout << std::max(a, b) << ' '
              << std::min(b, c) << ' '
              << std::floor(std::sqrt(a + c)) << '\n';
}
