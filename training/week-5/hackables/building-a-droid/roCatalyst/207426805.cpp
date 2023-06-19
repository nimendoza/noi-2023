#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(__int128 n) {
    string num = "";
        do {
            int r = n%10;
            num += to_string(r);
            n /= 10;
        } while(n);

    reverse(num.begin(),num.end());
    cout << num << "\n";
}

ll gcd(ll a, ll b) {
    while (a != 0) {
        ll r = b%a;
        
        b = a;
        a = r;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    ll p2, p3, v1, v2, v3;
    cin >> q >> p2 >> p3 >> v1 >> v2 >> v3;
    vector<pair<__int128,__int128>> pieces;
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

    __int128 product1 = p3*v2;
    __int128 product2 = p2*v3; 

    if ((p==2) && (product1 > product2)) {
        __int128 lcm = (p2*p3)/gcd(p2,p3);
        __int128 v4 = lcm/p2*v2;

        pieces.push_back(pair<__int128,__int128> (lcm,v4));
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


        print(ans);

    }

    
    return 0;
}