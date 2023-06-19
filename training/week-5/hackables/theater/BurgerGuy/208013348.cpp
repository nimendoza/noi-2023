#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

vector<int> solve(vector<pair<ll,ll>> a, vector<int> c){
    for (int i = 0; i < size(a); ++i) {
        for (int j = i + 1; j < size(a); ++j) {
            if(a[i].first <= a[j].second && a[i].second >= a[j].first){
                ++c[i];
                ++c[j];
            }
        }
    }
    return c;
}

int main(){
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        int n;
        ll h = 0;
        vector<pair<ll,ll>> a;
        vector<int> b,c;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            ll t1,t2;
            cin >> t1 >> t2;
            a.emplace_back(t1,t2);

            if(t2 > h){
                h = t2;
            }
        }
        c.resize(size(a));
        fill(c.begin(),c.end(),0);

        bool g = false;

        while(!g){
            fill(c.begin(),c.end(),0);
            g = true;
            int m = -1;
            int hID = -1;
            c = solve(a,c);
            for (int i = 0; i < size(c); ++i) {
                if(c[i] > 0){
                    g = false;
                    if(c[i] > m){
                        m = c[i];
                        hID = i;
                    }
                }
            }
            if(m  != -1){
                a.erase(a.begin() + hID);
                c.resize(size(a));
            }
        }

        cout << size(a) << '\n';

    }
}
