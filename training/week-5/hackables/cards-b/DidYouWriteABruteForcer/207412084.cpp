#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef __int128 LLL;
struct Fraction {
    LL num, den;
    Fraction(LL num, LL den): num(num), den(den) {}
    bool operator==(const Fraction& other) const {
        return this->num == other.num && this->den == other.den;
    }
    bool operator<(const Fraction& other) const {
        return ((LLL) this->num * other.den) < ((LLL) other.num * this->den);
    }
    void reduce() {
        function<LL(LL, LL)> gcd = [&](LL a, LL b) {
            return b == 0 ? a : gcd(b, a%b);
        };
        LL d = gcd(this->num, this->den);
        this->num /= d;
        this->den /= d;
    }
    void print() {
        cout << this->num << "/" << this->den << '\n';
    }
};
LL try_all_subarrays_of_size(int n, vector<LL>& v, int k) {
    LL curr = 0;
    for (int i = 0; i < k; i++) {
        curr += v[i];
    }
    LL best = curr;
    for (int i = k; i < n; i++) {
        curr -= v[i-k];
        curr += v[i];
        best = max(best, curr);
    }
    return best;
}
void solve(int n, vector<LL>& v, int l) {
    vector<Fraction> candidates;
    for (const int kk : {l, (l + n)/2, n}) {
        for (int d = -7; d <= 7; d++) {
            int k = kk + d;
            if (l <= k && k <= n) {
                candidates.emplace_back(try_all_subarrays_of_size(n, v, k), k);
            }
        }
    }
    Fraction minnie = *max_element(candidates.begin(), candidates.end());
    minnie.reduce();
    minnie.print();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, l; cin >> n >> l;
        vector<LL> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        solve(n, v, l);
    }
    cout << endl;
    return 0;
}