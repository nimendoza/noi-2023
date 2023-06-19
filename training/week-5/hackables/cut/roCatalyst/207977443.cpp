#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        ll ans = 0;

        
        if (n==1) {
            float li;
            cin >> li;
            cout << ceil(li/(c+1)) << endl;
        }
        else {
            vector<ll> sticks;
            while (n--) {
                float li;
                cin >> li;
                if (li == 1) {
                    continue;
                } else {
                    sticks.push_back(li);
                }
            }
            sort(sticks.begin(),sticks.end(),greater <>());

            for (int i = 1; i < n + 1; i++) {
                ll sum = 0;
                for (int j = 0; j < sticks.size(); j++) {
                    sum += sticks[j] / i;
                    if (sum > c) {
                        break;
                    }
                }

                if (sum <= c) {
                    cout << i << "\n";
                    break;
                }
            }

            
            
        }
    }

}