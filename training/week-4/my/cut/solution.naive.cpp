#include <bits/stdc++.h>

auto solve(const int& n, const int& c, const std::vector<int>& l) {
    std::priority_queue<int> queue(begin(l), end(l));
    for (int i{}; i < c && queue.top() >= 2; ++i) {
        int max{queue.top()}; queue.pop();
        queue.push(max / 2 + (max & 1));
        queue.push(max / 2);
    }

    return queue.top();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        int c; std::cin >> c;
        std::vector<int> l(n);
        for (int& x : l) {
            std::cin >> x;
        }

        std::cout << solve(n, c, l) << '\n';
    }
}
