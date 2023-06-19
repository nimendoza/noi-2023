#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    cin >> n >> h;
    vector<int> c;

    for (int i = 0; i < n; i++) {
        int ci;
        cin >> ci;
        c.push_back(ci);
    }

    int ans = 0;

    while (h) {
        int ci = c.back();
        c.pop_back();
        ans += h / ci;
        h %= ci;
    }

    cout << ans << endl;

    return 0;


}