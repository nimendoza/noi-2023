#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ll t,n,c,h,m;

    cin >> t;

    for (int q = 0; q < t; ++q) {
        vector <ll> a;
        cin >> n >> c;
        h = 0;

        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            a.push_back(b);

            if(b > h){
                h = b;
                m = i;
            }
        }

        for (int i = 0; i < c; ++i) {
            if(a[m] < 2){
                break;
            }

            if(a[m] % 2 == 0){
                a[m] /= 2;
                a.push_back(a[m]);
            }
            else{
                a.push_back(a[m] - ceil(a[m] / 2));
                a[m] = ceil(a[m] / 2);
            }
            m = max_element(a.begin(), a.end()) - a.begin();
        }
        cout << a[m] << '\n';
    }
}