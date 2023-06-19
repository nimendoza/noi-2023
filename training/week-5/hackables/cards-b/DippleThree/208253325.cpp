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

void outlll(lll res){
    if (res < ten){
        cout << (char)(res + '0');
    } else {
        outlll(res / ten);
        cout << (char)(res % ten + '0');
    }
}

struct frac{
    lll num;
    lll den;

    frac (lll n, lll d){
        num = n;
        den = d;
    }
};

bool operator<(const frac &a, const frac &b){
    return a.num * b.den < b.num * a.den;
}

frac reduce(frac f){
    lll g = __gcd(f.num, f.den);
    return frac(f.num / g, f.den / g);
}

frac solve(int n, int l, vector<ll> a){
    frac mx(0, 1);
    for (int i = 0; i <= n - l; i++){
        ll summ = 0;
        for (int j = i; j < i + l; j++){
            summ += a[j];
        }
        mx = max(mx, frac(summ, l));
        for (int j = i + l; j < n; j++){
            summ += a[j];
            mx = max(mx, frac(summ, j - i + 1));
        }
    }
    return reduce(mx);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n, l; cin >> n >> l;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        frac f = solve(n, l, a);
        outlll(f.num);
        cout << "/";
        outlll(f.den);
        cout << "\n";
    }
}