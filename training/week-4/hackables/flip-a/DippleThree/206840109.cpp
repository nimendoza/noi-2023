#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n; string s; cin >> s;
        int ones = 0;
        int currsum = 0;
        int maxsum = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                ones++;
                currsum++;
            } else {
                currsum--;
            }
            maxsum = max(maxsum, currsum);
            currsum = max(currsum, 0);
        }
        cout << ones - maxsum << "\n";
    }
}