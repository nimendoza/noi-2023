#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int H = 0;

void solve(int n,int x, vector<pair<int,int>> a, int c, int m,int d,int g,vector<int> b){
    b.push_back(g);
    ++x;

    m += floor((d/a[g].second)) * a[g].first;
    d = d - floor((floor(((d/a[g].second)) * a[g].first)/a[g].first)) * a[g].second;

    if(x == n || d == 0){
        if(H < m) {
            H = m;
        }
    }
    else if(x == n && d > 0){

    }
    else {
        for (int i = 0; i < n; ++i) {
            bool t = false;
            for (int j = 0; j < size(b); ++j) {
                if(i == b[j]){
                    t = true;
                }
            }

            if(!t){
                solve(n, x, a, c, m, d, i,b);
            }
        }
    }
}


int main(){
    int t;
    cin >> t;

    H = 0;
    for (int q = 0; q < t; ++q) {
        int n,d,c,m;
        cin >> n >> d;
        vector <pair<int,int>> a;

        for (int i = 0; i < n; ++i) {
            int t1,t2;
            cin >> t1 >> t2;

            a.emplace_back(t1,t2);
        }

        for (int i = 0; i < n; ++i) {
            c = 0;
            m = 0;
            vector <int> b;
            solve(n,0,a,c,m,d,i,b);
        }

        cout << H << '\n';
    }
}