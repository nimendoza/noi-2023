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
            priority_queue<ll> sticks;
            while (n--) {
                float li;
                cin >> li;
                if (li == 1) {
                    continue;
                } else {
                    sticks.emplace(li);
                }
            }
 
            
 
            ll i = 0;
            while ((!sticks.empty()) && (i < c)) {
                float li = sticks.top();
                sticks.pop();
 
                ll s1 = ceil(li/2);
                ll s2 = floor(li/2);
                if (s1 > 1) {
                    sticks.emplace(s1);
                }
 
                if (s2 > 1) {
                    sticks.emplace(s2);
                }
 
                i++;
            }
 
            if (sticks.empty()) {
                cout << 1 << endl;
            }
            else {
                cout << sticks.top() << endl;
            }
            
        }
    }
 
    return 0;
}