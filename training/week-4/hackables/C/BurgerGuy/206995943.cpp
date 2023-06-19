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
        a.resize((c * 2) + n);
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            a.insert(a.begin(),b);
        }

        sort(a.begin(),a.end());

        for (int i = 0; i < c; ++i) {
            if(a[size(a) - 1] < 2){
                break;
            }

            if(a[size(a) - 1] % 2 == 0){
                auto itr = upper_bound(a.begin(), a.end(), a[size(a) - 1] / 2);

                a.insert(itr,a[size(a) - 1]/2);
                a.insert(itr + 1,a[size(a) - 1]/2);
                a.pop_back();
            }
            else{
                auto itr = upper_bound(a.begin(), a.end(), a[size(a) - 1] - ceil(a[size(a) - 1] / 2));
                a.insert(itr,a[size(a) - 1] - ceil(a[size(a) - 1]/2));
                itr = upper_bound(a.begin(),a.end(),ceil(a[size(a) - 1] / 2));
                a.insert(itr,ceil(a[size(a) - 1] / 2));
                a.pop_back();
            }
        }
        cout << a[size(a) - 1] << '\n';
    }
}