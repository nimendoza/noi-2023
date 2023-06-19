#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int MAX_N = 10000001;
int mi[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    for(int i = 0; i < MAX_N; i++) mi[i] = MAX_N;
    mi[0] = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++) {
        for(int j = v[i]; j < MAX_N; j++) {
            if(mi[j - v[i]] + 1 < mi[j]) mi[j] = mi[j - v[i]] + 1;
        }
    }
    cout << mi[h] << '\n';
}
