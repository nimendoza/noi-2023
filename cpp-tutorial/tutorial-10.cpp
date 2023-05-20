#include <bits/stdc++.h>

int solve(int& n, int& k, std::vector<int>& a) {
    int answer{};
    for (int x : a) {
        if (x % k) {
            answer++;
        }
    }

    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n; std::cin >> n;
    int k; std::cin >> k;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }

    std::cout << solve(n, k, a) << '\n';
}