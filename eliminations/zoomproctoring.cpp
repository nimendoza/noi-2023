#include <bits/stdc++.h>

struct key {
    int frequency;
    std::string s;

    key(const std::string s, int &f) : frequency{f}, s{s} {}
    key(std::string s, int f) : frequency{f}, s{s} {}

    bool operator < (const key& k) const {
        return this->frequency < k.frequency;
    }
};

void solve(int& n, std::priority_queue<key>& maxheap, std::map<std::string, std::vector<int>>& keys) {
    std::vector<int> order{};
    key previous(std::string("__"), -1);
    while (!maxheap.empty()) {
        key k = maxheap.top(); maxheap.pop();
        order.push_back(keys[k.s].back()); keys[k.s].pop_back();
        k.frequency--;
        if (previous.frequency > 0) {
            maxheap.push(previous);
        }

        previous = k;
    }
    if (n != order.size()) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << "POSSIBLE\n";
        for (int i{}; i < n; ++i) {
            std::cout << order[i];
            if (i != n - 1) {
                std::cout << ' ';
            } else {
                std::cout << '\n';
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int m; std::cin >> m;
    std::map<std::string, std::vector<int>> keys{};
    for (int i{}; i < n; ++i) {
        std::string s; std::cin >> s;
        keys[s].push_back(i + 1);
    }

    std::priority_queue<key> maxheap{};
    for (auto [s, f] : keys) {
        maxheap.emplace(key(s, f.size()));
    }

    solve(n, maxheap, keys);
}