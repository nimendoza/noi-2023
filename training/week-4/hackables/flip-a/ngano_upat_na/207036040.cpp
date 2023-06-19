#include "bits/stdc++.h"
using namespace std;
using ll = long long;

string modify(int n, string s) {
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            p[i] = 1;
        }   
        else {
            p[i] = -1;
        }   
    }   
    int sum = 0, best = 0, r = -1;
    for (int i=0; i<n; i++) {
        sum = max(p[i],sum+p[i]);   
        if (sum > best) {
            best = sum;
            r = i;
        }   
    }   
    if (r == -1) return s; // no change
    
    int sum1 = 0, l = 0;
    for (int i=r; i>=0; i--) {
        if (sum1 + p[i] == best) {
            l = i;
            break;
        }   
        sum1 += p[i];  
    }   
    for (int i=l; i<=r; i++) {
        p[i] *= (-1);
    }   
    string ans;
    for (int i=0; i<n; i++) {
        if (p[i] == 1) {
            ans.push_back('1');
        }   
        else {
            ans.push_back('0');
        }   
    }   
    return ans;
}   

void sol() {
    int n;
    string s;
    cin >> n >> s;
    
    string a = modify(n,s);
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == '1') ans++;
    }   
    cout << ans << '\n';
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) sol();
}   