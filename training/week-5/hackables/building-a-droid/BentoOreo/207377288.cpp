#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::ostream& operator <<(std::ostream& dest, __int128 v) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp(v < 0 ? -v : v);
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);

        if (v < 0) {
            --d;
            *d = '-';
        }

        int len(std::end(buffer) - d);
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }

    return dest;
}

int main() {
    int testcases;
    cin >> testcases;
    long long int sc = 1, d2, c3;
    long long int v1, v2, v3;
    cin >> d2 >> c3 >> v1 >> v2 >> v3;
    pair <__int128,__int128> ratio1,ratio2,ratio3;
    ratio1 = {v1,sc};
    ratio2 = {v2,d2};
    ratio3 = {v3,c3};
    vector<pair<__int128,__int128> > vect = {ratio1,ratio2,ratio3};
    sort(vect.begin(),vect.end(),[&](const auto &a,const auto &b){
        if(a.first * b.second == b.first * a.second){
            return a.second < b.second; //sma__int128er one first
        }
        return a.first * b.second > b.first * a.second;
    });

    for (int q = 0; q < testcases; q++) {
        long long int c2;
        cin >> c2;
        __int128 c = c2;
        __int128 quality = 0;
        //find the maximum fraction.
        for(int i = 0; i < 3; i++){
            auto elem = vect[i];
            if(elem.second <= c){
                //maximise the number of units I buy
                __int128 units = c / elem.second; // I just want integer anyways
                c -= units * elem.second; //deduct the cost
                quality += units * elem.first;
            }
        }
        cout << quality << endl;
    }
    return 0;
}
