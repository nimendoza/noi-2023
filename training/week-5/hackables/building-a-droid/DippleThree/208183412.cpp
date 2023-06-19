#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
const lll ten = 10;
lll p1 = 1, p2, p3, v1, v2, v3;
const int C = 2000001;
vector<lll> v;

lll inlll(){
    string s; cin >> s;
    lll res = 0;
    for (char c: s){
        res *= ten;
        res += c - '0';
    }
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

void pre(){
    v.resize(C);
    for (lll i = 0; i < C; i++){
        v[i] = v1 * i;
    }
    for (lll i = p2; i < C; i++){
        v[i] = max(v[i], v[i - p2] + v2);
    }
    for (lll i = p3; i < C; i++){
        v[i] = max(v[i], v[i - p3] + v3);
    }
}

lll solve(ll c){
    return v[c];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    p2 = inlll(); p3 = inlll(); v1 = inlll(); v2 = inlll(); v3 = inlll();
    pre();
    while (t--){
        ll c; cin >> c;
        outlll(solve(c));
        cout << "\n";
    }
}