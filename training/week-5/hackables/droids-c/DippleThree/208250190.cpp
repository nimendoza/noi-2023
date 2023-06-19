#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
const lll ten = 10;

lll inlll(){
string s; cin >> s;
bool neg = false;
if (s[0] == '-'){
    neg = true;
    s = s.substr(1);
}
lll res = 0;
for (char c: s){
    res *= ten;
    res += c - '0';
}
if (neg) res *= -1;
    return res;
}

lll mod = 998244353LL;

int solve(ll n, ll w, int k, int f, vector<lll> a){
    f %= k;
    vector<lll> v;
    for (lll i = 0; i < n; i++){
        f = (f * f) % k;
        v.push_back(a[f] + (lll) (w * (i + 1LL)));
    }
    lll mn = 0;
    lll summ = 0;
    for (lll i = 0; i < n; i++){
        summ += v[i];
        if (summ > 0LL) summ = 0LL;
        mn = min(mn, summ);
    }
    mn = (mn % mod + mod) % mod;
    return (int) mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        ll n; int w, k, f;
        cin >> n >> w >> k >> f;
        vector<lll> a(k);
        for (int i = 0; i < k; i++){
            a[i] = inlll();
        }
        cout << solve(n, w, k, f, a) << "\n";
    }
}