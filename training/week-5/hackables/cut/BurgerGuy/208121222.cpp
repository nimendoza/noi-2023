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
        vector <ll> a,ta;
        cin >> n >> c;
        int h = 0;
        for (int i = 0; i < n; ++i) {
            int b;
            cin >> b;
            ta.push_back(b);

            if(h < b){
                h = b;
            }
        }

        a.resize(h + 1);
        fill(a.begin(),a.end(),0);

        for (int i = 0; i < size(ta); ++i) {
            ++a[ta[i]];
        }

        for (int i = h; i > 0; --i) {
            while(a[i] == 0){
                --i;
            }

            if(i == 1){
                break;
            }

            if(i % 2 == 0){
                --a[i];
                a[i / 2] += 2;
            }
            else{
                --a[i];
                ++a[(i / 2) + 1];
                ++a[i / 2];
            }
            --c;

            if(c == 0){
                break;
            }

            if(a[i] != 0){
                ++i;
            }
        }

        int i = h;

        while(a[i] == 0){
            --i;
        }

        cout << i << '\n';
    }
}
