#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;


int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int len;
        ll holder;
        cin >> len;
        vector<ll> vect;
        for(int i = 0; i < len; i++){
            cin >> holder;
            vect.push_back(holder);
        }
        ll maxrn = 0;
        ll globalmax = 0;
        int globalstart,globallensofar;
        int start = 0, lensofar = 0;
        for(int i = 0; i < len; i++){
            if(vect[i] > maxrn + vect[i]){
                start = i;
                lensofar = 0;
                maxrn = vect[i];
            } else {
                maxrn = maxrn+vect[i];
                lensofar++;
            }
            if(maxrn > globalmax){
                globalmax = maxrn;
                globalstart = start;
                globallensofar = lensofar;
            }
        }
        ll Han = globalmax;
        ll Lando = vect[globalstart];
        for(int i = 1; i < globallensofar; i++){
            Lando = max(Lando, vect[globalstart+i]);
        }
        cout << Han - Lando << endl;
    }
}