#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ll t,n,c,m,mID;
    m = 0;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        vector <ll> a;
        cin >> n >> c;

        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            a.push_back(b);

            if(b > m){
                m = b;
                mID = i;
            }
        }

        for (int i = 0; i < c; ++i) {
            if(a[mID] < 2){
                break;
            }

            if(a[mID] % 2 == 0){
                a[mID] /= 2;
                a.push_back(a[mID]);
            }
            else{
                a.push_back(a[mID] - ceil(a[mID] / 2));
                a[mID] = ceil(a[mID] / 2);
            }
            mID = max_element(a.begin(), a.end()) - a.begin();
        }
        cout << a[mID] << '\n';
    }
}