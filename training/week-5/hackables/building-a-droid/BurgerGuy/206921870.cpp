#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

std::ostream& operator << (std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value<0?-value:value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            -- d;
            *d = "0123456789"[tmp%10];
            tmp/=10;
        }while(tmp!=0);
        if(value<0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer)-d;
        if (dest.rdbuf()->sputn(d,len)!=len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int main(){
    ll q,p2,p3,v1,v2,v3,c;
    __int128 t;
    vector <ll> a;

    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;

    a.push_back(v3/p3);
    a.push_back(v2/p2);
    a.push_back(v1);

    sort(a.rbegin(),a.rend());

    for (ll i = 0; i < q; ++i) {
        t = 0;
        cin >> c;

        for (int j = 0; j < 3; ++j) {
            ll e;

            if(a[j] == v3/p3 && p3 <= c){
                e = ll(c/p3) * v3;
                c = c - (ll(e/v3) * p3);
            }
            else if(a[j] == v2/p2 && p2 <= c){
                e = ll(c/p2) * v2;
                c = c - (ll(e/v2) * p2);
            }
            else{
                e = c * v1;
                c -= c;
            }

            t += e;

            if(c == 0){
                break;
            }
        }

        cout << t << '\n';
    }
}