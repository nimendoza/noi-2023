#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ll t,n,c;

    cin >> t;

    for (int q = 0; q < t; ++q) {
        vector <ll> a;
        cin >> n >> c;

        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            a.push_back(b);
        }

        for (int i = 0; i < c; ++i) {
            int m;
            m = max_element(a.begin(), a.end()) - a.begin();

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
        }
        int m = max_element(a.begin(), a.end()) - a.begin();
        cout << a[m] << '\n';
    }
}