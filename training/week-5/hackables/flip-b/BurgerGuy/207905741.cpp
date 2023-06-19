#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int t;

    cin >> t;

    for (int q = 0; q < t; ++q) {
        int n;

        cin >> n;
        string a;
        int h,l,r;
        h = 0;

        cin >> a;

        for (int i = 1; i < a.length() + 1; ++i) {
            for (int k = 0; k < a.length() - i + 1; ++k) {
                auto o = count(a.begin() + k,a.begin() + k + i,'1');
                auto z = i - o;

                if (h < o - z) {
                    l = k;
                    r = k + i;
                    h = o - z;
                }
            }
        }

        if(h == 1 && a.length() == 1){
            cout << '1' << '\n';
            continue;
        }
        else if(h == 0 && a.length() == 1){
            cout << '0' << '\n';
            continue;
        }

        h = 0;

        for (int i = l; i < r; ++i) {
            if(a[i] == '1'){
                a[i] = '0';
            }
            else{
                a[i] = '1';
            }
        }

        for (int i = 1; i < a.length() + 1; ++i) {
            for (int k = 0; k < a.length() - i + 1; ++k) {
                auto o = count(a.begin() + k,a.begin() + k + i,'1');
                auto z = i - o;

                if (h < o - z) {
                    l = k;
                    r = k + i;
                    h = o - z;
                }
            }
        }
        cout << a.length() - count(a.begin(),a.end(),'0') - h << '\n';
    }
}