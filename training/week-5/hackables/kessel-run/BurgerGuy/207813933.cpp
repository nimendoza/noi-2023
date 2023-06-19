#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,h,c;
    c= 0;
    vector <int> a;

    cin >> n >> h;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.rbegin(),a.rend());
    int hc  = h + 1;
    int th = h;

    for (int i = 0; i < size(a); ++i) {
        c = 0;
        h = th;
        for (int j = i; j < size(a); ++j) {
            if (a[j] <= h) {
                c += floor(h / a[j]);
                h -= floor((h / a[j])) * a[j];
            }
            if (h == 0) {
                break;
            }
        }
        if(c < hc){
            hc = c;
        }
    }

    cout << hc;
}