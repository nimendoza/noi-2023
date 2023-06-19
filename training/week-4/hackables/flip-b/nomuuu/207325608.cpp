#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, onechain; cin >> t;
    string k;
    while (t--) {
        cin >> n; 
        cin >> k;
        // chains of one
        onechain = 0;
        vector<int> onechains;
        // casework
        if (n == 1) {
            (k[0] == '1') ? cout << 1 << "\n" : cout << 0 << "\n";
        } else if (n <= 4) {
            cout << 0 << "\n";
        } else {
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
            if (onechains.size() <= 2) {
                cout << 0 << "\n";
            } else {
                sort(onechains.begin(), onechains.end(), greater<int>());
                int n1 = 0;
                for (int i : onechains) n1 += i;
                cout << n1 - onechains[0] - onechains[1] << "\n";
            }
        }
    }
}