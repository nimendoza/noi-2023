#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h; cin >> n >> h;
    vector<int> a(h + 1, h);
    a[0] = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int i = x; i <= h; i++){
            a[i] = min(a[i], a[i - x] + 1);
        }
    }
    cout << a[h] << "\n";
}