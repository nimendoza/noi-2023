#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct compare{
  bool operator()(const pair<double,double> &left, const pair<double,double> &right){
      if(left.first/left.second > right.first/right.second){
          return left > right;
      }
      else{
          return right > left;
      }
  }
};

int main(){
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        int n;
        double d,m;
        m = 0;

        cin >> n >> d;

        vector <pair<double,double>> a;

        for (int i = 0; i < n; ++i) {
            double v,c;

            cin >> v >> c;

            a.emplace_back(v,c);

            if(a[i].first > 100){
                cout << a[i].first << ' ' << i;
            }
        }

        sort(a.begin(),a.end(),compare {});

        for (int i = 0; i < size(a); ++i) {
            if(d >= a[i].second){
                m += floor((d/a[i].second)) * a[i].first;
                d = d - floor((floor(((d/a[i].second)) * a[i].first)/a[i].first)) * a[i].second;
            }
            if(d == 0){
                break;
            }
        }
        cout << int(m) << '\n';
    }
}