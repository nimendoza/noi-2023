#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; std::cin >> t;
    for (int _{}; _ < t; ++_) {
        int n; std::cin >> n;
        
        std::vector<int> results(n);
        for (int i{1}; i <= n; ++i) {
            std::cout << "? " << i << ' ' << (i % n) + 1 << ' ' << ((i + 1) % n) + 1 << std::endl;
            std::cin >> results[i - 1];
        }

        std::vector<int> imposters{};
        std::vector<int> crewmates{};
        for (int i{}; i < n; ++i) {
            if (results[i] != results[(i + 1) % n]) {
                imposters.push_back((results[i] ? ((i + 3) % n) + 1 : i + 1));
                crewmates.push_back((results[i] ? i + 1 : ((i + 3) % n) + 1));
                break;
            }
        }

        assert(imposters.size() && crewmates.size());

        for (int i{1}; i <= n; ++i) {
            if (i != imposters[0] && i != crewmates[0]) {
                std::cout << "? " << imposters[0] << ' ' << crewmates[0] << ' ' << i << std::endl;

                int response; std::cin >> response;
                if (!response) {
                    imposters.push_back(i);
                } else {
                    crewmates.push_back(i);
                }
            }
        }

        std::cout << "! " << imposters.size() << std::endl;
        for (int i{}; i < imposters.size(); ++i) {
            std::cout << imposters[i] << (i == imposters.size() - 1 ? '\n' : ' ');
        }

        std::cout.flush();
    }
}
