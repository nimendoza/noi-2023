#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
typedef long long LL;
LL solve(int n, vector<LL>& l, int s) {
    LL sum = accumulate(l.begin(), l.end(), 0);
    if (n % s == 0) {
        return sum;
    } else {
        int res = n % s;
        LL from_the_start = accumulate(l.begin()+res, l.begin()+s, 0);
        LL from_the_end = accumulate(l.end()-s, l.end()-res, 0);
        return sum + min(from_the_start, from_the_end); 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        vector<LL> l(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }
        for (int q_ = 0; q_ < q; q_++) {
            int s; cin >> s;
            cout << solve(n, l, s) << (q_ == q-1 ? '\n' : ' ');
        }
    }
    cout << endl;
    return 0;
}