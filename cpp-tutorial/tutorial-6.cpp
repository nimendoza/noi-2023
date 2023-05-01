#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> v(3);
    for (int& x : v) {
        std::cin >> x;
    }

    std::sort(begin(v), end(v));
    std::cout << v[1];
}
