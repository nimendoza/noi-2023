#include <bits/stdc++.h>

std::map<int, int> solve(int& n, std::vector<int>& a) {
    std::map<int, int> frequency{};
    for (int x : a) {
        frequency[x]++;
    }

    return frequency;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }

    for (auto [value, count] : solve(n, a)) {
        std::stringstream answer{};
        answer << value << "appears ";
        if (count == 1) {
            answer << "once ";
        } else {
            answer << count << " times ";
        }

        answer << "in the array.\n";

        std::cout << answer.str();
    }
}