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

    for (int i = 0; i < size(a); ++i) {
        if(a[i] <= h){
            c += floor(h/a[i]);
            h -= floor((h/a[i])) * a[i];
        }
        if(h == 0){
            break;
        }
    }

    cout << c;
}