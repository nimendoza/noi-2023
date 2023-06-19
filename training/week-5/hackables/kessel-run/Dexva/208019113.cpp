#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define lln long long
#define INF (unsigned)!((int)0)

// int solve(int n, int h, vector<int> c) {
//     if (h < 0) return INFINITY;
//     else if (h==0) return 0;
//     else {
//         int best = INFINITY;
//         for (auto coin : c) {
//             best = min(best, solve(n, h-coin, c)+1);
//         }
//         return best;
//     }
// }

int main() {
    int n, h; cin >> n >> h;
    int coins[n];
    for (int i=0;i<n;i++) {
        cin >> coins[i];
    }

    int value[h+1]; value[0] = 0;

    for (int x=1; x<=h; x++) {
        // cout << "im at i = " << x << '\n';
        value[x] = 20000000;
        for (auto c : coins) {
            if (x-c >= 0) {
                // cout << "yes " << c << " and " << value[x] << " " << value[x-c] << '\n';
                value[x] = min(value[x], value[x-c]+1);
            }
        }
        // cout << value[x] << '\n';
    }
    
    // for (int j=0; j<=h;j++) cout << j << " " << value[j] << '\n';

    cout << value[h] << '\n';
}