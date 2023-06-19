#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ll q,p2,p3,v1,v2,v3,c,t;
    vector <ll> a;

    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;

    a.push_back(v3/p3);
    a.push_back(v2/p2);
    a.push_back(v1);

    sort(a.rbegin(),a.rend());

    for (ll i = 0; i < q; ++i) {
        t = 0;
        cin >> c;

        for (int j = 0; j < 3; ++j) {
            ll e;

            if(a[j] == v3/p3 && p3 <= c){
                e = ll(c/p3) * v3;
                c = c - (ll(e/v3) * p3);
            }
            else if(a[j] == v2/p2 && p2 <= c){
                e = ll(c/p2) * v2;
                c = c - (ll(e/v2) * p2);
            }
            else{
                e = c * v1;
                c -= c;
            }

            t += e;

            if(c == 0){
                break;
            }
        }

        cout << t << '\n';
    }
}