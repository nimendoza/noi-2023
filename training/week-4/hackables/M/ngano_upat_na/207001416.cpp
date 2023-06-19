#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int inf = 1e9+7;

vector<int> good(10000001,inf);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, h;
    cin >> n >> h;
    vector<int> v(n);
    for (auto &e:v) cin >> e;
    sort(v.begin(),v.end());
    
    good[0] = 0;
    for (int i=1; i<=h; i++) {
        for (auto &a:v) {
            if (i-a>=0) {
                good[i] = min(good[i],good[i-a]+1);
            }
        }   
    }   
    cout << good[h];
}   