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
        int o,z;
        int h;
        h = 0;

        cin >> a;

        for (int i = 1; i < a.length() + 1; ++i) {
            for (int k = 0; k < a.length() - i + 1; ++k) {
                o = 0;
                z = 0;
                for (int j = k; j < k + i; ++j) {
                    if (a[j] == '1') {
                        ++o;
                    }
                    else if (a[j] == '0') {
                        ++z;
                    }
                    else {
                        break;
                    }
                }
                if (h < o - z) {
                    h = o - z;
                }
            }
        }
        auto w = count(a.begin(),a.end(),'1');
        if(w == 0){
            cout << '1' << '\n';
        }
        else {
            cout << w - h << '\n';
        }
    }
}