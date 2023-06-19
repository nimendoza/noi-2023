#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
const lll ten = 10;

lll inlll(){
string s; cin >> s;
bool neg = false;
int curr = 0;
if (s[0] == '-'){
    neg = true;
    curr++;
}
lll res = 0;
while (curr != s.size()){
    res *= ten;
    res += s[curr] - '0';
    curr++;
}
if (neg) res *= -1LL;
    return res;
}

lll mod = 998244353LL;

int solve(ll n, ll w, int k, int f, vector<ll> &a){
    f %= k;
    lll mn = 0;
    lll summ = 0;
    for (lll i = 0; i < n; i++){
        f = (f * f) % k;
        summ += (lll) a[f] + (lll) (w * (i + 1LL));
        if (summ > 0LL) summ = 0LL;
        mn = min(mn, summ);
    }
    mn = (mn % mod + mod) % mod;
    return (ll) mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        ll n; int w, k, f;
        cin >> n >> w >> k >> f;
        vector<ll> a(k);
        for (int i = 0; i < k; i++){
            a[i] = inlll();
        }
        cout << solve(n, w, k, f, a) << "\n";
    }
}