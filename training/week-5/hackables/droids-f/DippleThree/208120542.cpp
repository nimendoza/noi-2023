#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(int n, vector<int> a){
    vector<int> non(n + 1, 0);
    vector<int> has(n + 1, 1);
    for (int i = n; i >= 1; i--){
        has[i] = max(has[i], non[i]);
        non[a[i]] += has[i];
        has[a[i]] += non[i];
    }
    return has[1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++){
        cin >> a[i];
    }
    cout << solve(n, a) << "\n";
}