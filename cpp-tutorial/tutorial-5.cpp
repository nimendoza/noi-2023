#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x; std::cin >> x;
    int y; std::cin >> y;
    int z; std::cin >> z;
    std::cout << ((x + y) == z) << '\n';
    std::cout << ((x <= y) && (y <= z)) << '\n';
    std::cout << ((x * y * z) % 2 == 0) << '\n';
    std::cout << ((x != y) && (y != z) && (z != x)) << '\n';
    std::cout << ((x + y > z) && (y + z > x) && (z + x > y)) << '\n';
}
