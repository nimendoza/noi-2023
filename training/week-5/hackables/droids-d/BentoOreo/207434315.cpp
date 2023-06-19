#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

const ll MOD = 998244353;
ll modnegpos(ll a) {
    if (a < 0) {
        return ((a % MOD) + MOD) % MOD;
    } else {
        return a % MOD;
    }
}

int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int len;
        ll holder;
        cin >> len;
        vector<ll> vect;
        vector<vector<ll> > subs;
        for (int i = 0; i < len; i++) {
            cin >> holder;
            vect.push_back(holder);
        }
        for(int i = 0; i < len; i++){
            vector <ll> temp;
            for(int j = i; j < len; j++){
                temp.push_back(vect[j]);
                subs.push_back(temp);
            }
        }
        ll total = 0;
        for(auto row : subs){
            ll globalminimum = 0, runningtotal = 0;
            for(auto value : row){
                runningtotal = min(runningtotal+value, value);
                globalminimum = min(globalminimum,runningtotal);
            }
            total = modnegpos(total + modnegpos(globalminimum));
        }
        cout << total << endl;
    }
}