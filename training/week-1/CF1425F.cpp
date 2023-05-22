#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;

    std::vector<int> v(n);
    for (int i{1}; i < n; ++i) {
        std::cout << "? " << i << ' ' << n << std::endl;
        std::cin >> v[i - 1];
    }

    int entirety{v[0]};
    for (int i{}; i < n - 1; ++i) {
        v[i] -= v[i + 1];
    }

    std::cout << "? " << n - 2 << ' ' << n - 1 << std::endl;
    std::cin >> v[n - 1];
    
    v[n - 2] = v[n - 1] - v[n - 3];
    v[n - 1] = entirety - std::accumulate(begin(v), --end(v), 0);

    std::cout << "! ";
    for (int i{}; i < n; ++i) {
        std::cout << v[i] << (i == n - 1 ? '\n' : ' ');
    }
}
