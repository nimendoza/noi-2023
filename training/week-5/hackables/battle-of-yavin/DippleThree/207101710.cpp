#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n, d; cin >> n >> d;
        vector<int> value(d + 1, 0);
        while (n--){
            int v, c; cin >> v >> c;
            for (int i = c; i <= d; i++){
                value[i] = max(value[i], value[i - c] + v);
            }
        }
        cout << value[d] << "\n";
    }
}