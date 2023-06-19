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
        cin >> len;
        vector<pair<ll, ll> > vect;
        ll L, R;
        for(int i = 0; i < len; i++){
            cin >> L >> R;
            pair<ll,ll> temp = {L,R};
            vect.push_back(temp);
        }
        sort(vect.begin(),vect.end(),[&](const auto &a, const auto &b){
            if(a.second - a.first == b.second - b.first)
                return a.first < b.first;
            return a.second - a.first < b.second - b.first;
        });
        ll parties_satisfied = 0;
        ll previous_end = -1;
        for(auto elem: vect){
            if(elem.first > previous_end){
                previous_end = elem.second;
                parties_satisfied++;
            }
        }
        cout << parties_satisfied << endl;
    }
}