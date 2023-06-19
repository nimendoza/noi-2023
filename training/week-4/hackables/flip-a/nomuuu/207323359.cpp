#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, onechain; cin >> t;
    string k;
    while (t--) {
        int n1, n2;
        cin >> n;
        cin >> k;
        onechain = 0;
        vector<int> onechains;
        for (int i = 0; i < n; i++) {
            if (k[i] == '1') {
                onechain += 1;
                if (i == n - 1) {
                    onechains.push_back(onechain);
                }
            } else {
                if (onechain > 0) {
                    onechains.push_back(onechain);
                }
                onechain = 0;
            }
        }
        for (int i : onechains) n1 += i;
        n2 = *max_element(onechains.begin(), onechains.end());
        cout << n1 - n2 << "\n";
        n1 = 0;
    }
}