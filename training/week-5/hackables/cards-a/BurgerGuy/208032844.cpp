#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll H;
int L;
int U;

void solve(vector<ll> a, int g, ll n){
    for (int i = 0; i < n - g; ++i) {
        ll temp = 0;
        for (int j = 0; j < g + 1; ++j) {
            temp += a[i + j];
        }

        if(temp > H){
            H = temp;
            L = i;
            U = i + g + 1;
        }
    }
}

int main(){
    int t;
    cin >> t;

    for (int q = 0; q < t; ++q) {
        H = - 1000000000001;
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            solve(a,i,n);
        }

        ll b = -1000000000001;

        for (int i = L; i < U; ++i) {
            if(a[i] > b){
                b = a[i];
            }
        }

        cout << H - b << '\n';
    }
}