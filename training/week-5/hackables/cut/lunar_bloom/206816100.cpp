#include <bits/stdc++.h>

auto solve(int& n, int& c, std::vector<int>& l) {
    std::priority_queue<int> pq(begin(l), end(l));
    while (c-- && pq.top() >= 2) {
        int max{pq.top()}; pq.pop();
        pq.push(max / 2 + (max & 1));
        pq.push(max / 2);
    }

    return pq.top();
}

int main(int argc, char** argv) {
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
