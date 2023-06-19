#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,h,g;
    vector <int> a,b;
    cin >> n >> h;
    a.resize(n);

    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= h; ++i) {
        if(i == 0 || i == 1){
            b.push_back(i);
            continue;
        }

        g = 100001;

        for (int j=0; j<n; j++){
            if (i - a[j] >= 0){
                g = min(g, b[i - a[j]]);
            }
        }
        b.push_back(g + 1);
    }
    cout << b[h] << '\n';
}