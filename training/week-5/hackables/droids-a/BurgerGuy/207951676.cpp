#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
    int n;
    ll c;
    cin >> n;

    vector<ll> a,b,f;
    a.push_back(0);
    b.push_back(0);

    for (int i = 1; i < n + 1; ++i) {
        ll temp;
        cin >> temp;

        a.push_back((a[i - 1] + temp));
    }
    for (int i = 1; i < n + 1; ++i) {
        ll temp;
        cin >> temp;

        b.push_back(b[i - 1] + temp);
    }

    for (int i = 1; i < (n * 2) + 1; ++i) {
        c = 0;

        for (int j = 0; j < n + 1; ++j) {
            if(i < j || i - j > n){
                continue;
            }
            if(c < a[j] + b[i - j]){
                c = a[j] + b[i - j];
            }
        }

        f.push_back(c);
    }
    

    ll h = 0;

    for (int i = 0; i < n * 2; ++i) {
        h ^= f[i];
    }

    cout << h << '\n';
}
