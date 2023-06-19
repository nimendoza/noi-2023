#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int currsum;
int mx;
int n, a;
vector<int> v;

void recurse(int dex){
    if (dex == n){
        mx = max(mx, currsum);
        return;
    }
    recurse(dex + 1);
    currsum += v[dex];
    if (currsum <= a) recurse(dex + 1);
    currsum -= v[dex];
}

int solve(){
    sort(v.rbegin(), v.rend());
    currsum = 0;
    mx = 0;
    recurse(0);
    return mx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> a;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve() << "\n";
    }
}