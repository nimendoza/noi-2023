#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> A = {0};
        int count = 0, currSum = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '1') {
                currSum -= 1;
                count += 1;
            }
            else {
                currSum += 1;
            }

            A.push_back(currSum);
        }

        for (auto pi = A.begin(); pi != A.end(); pi++) {
            for (auto pj = pi + 1; pj != A.end(); pj++) {
                ans = min(*pj-*pi,ans);
            }
        }
        cout << ans + count << endl;
    }
    return 0;
}