#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll gcd(ll a, ll b) {
    while (a != 0) {
        ll r = b%a;
        
        b = a;
        a = r;
    }
    return b;
}

int main() {
    ll q, p2, p3, v1, v2, v3;
    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;
    vector<pair<ll,ll>> pieces;
    pieces.push_back(pair<ll,ll> (1,v1));
    
    int p = 0;
    if (p2 * v1 <= v2) {
        pieces.push_back(pair<ll,ll> (p2,v2));
        p++;
    }
    if (p3 * v1 <= v3) {
        pieces.push_back(pair<ll,ll> (p3,v3));
        p++;
    }
    if ((p==2) && (p3*v2 >p2*v3)) {
        ll lcm = (p2*p3)/gcd(p2,p3);
        ll v4 = lcm/p2*v2;
        pieces.push_back(pair<ll,ll> (lcm,v4));
    }
    
    
    


    int n = pieces.size();

    while (q--) {
        ll c;
        cin >> c;
        __int128 ans = 0;

        ll quo = 0;
        int i = n-1;
        do {
            ll c1 = pieces[i].first, c2 = pieces[i].second;

            ll quo = c / c1;

            ans += quo * c2;
            c %= c1;

            i--;
        } while (c);


        string num = "";
        do {
            int r = ans%10;
            num += to_string(r);
            ans /= 10;
        } while(ans);

        reverse(num.begin(),num.end());
        cout << num << endl;

    }

    
    return 0;
}