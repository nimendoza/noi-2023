#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n; string s;

tuple<int, int, int> greedyonce(){
    int ones = 0;
    int currsum = 0;
    int maxsum = -1;
    int mxleft = 0, mxright = 0, currleft = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            ones++;
            currsum++;
        } else {
            currsum--;
        }
        if (currsum > maxsum){
            maxsum = currsum;
            mxleft = currleft;
            mxright = i;
        }
        if (currsum < 0){
            currsum = 0;
            currleft = i + 1;
        }
    }
    ones -= maxsum;
    return make_tuple(mxleft, mxright, ones);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> s;
        if (n == 1){
            cout << (s[0] == '1' ? 1 : 0) << "\n";
            continue;
        }
        int mxleft, mxright, ones;
        tie(mxleft, mxright, ones) = greedyonce();
        for (int i = mxleft; i <= mxright; i++){
            s[i] = '0' + '1' - s[i];
        }
        int ones2;
        ones2 = get<2>(greedyonce());
        cout << min(ones, ones2) << "\n";
    }
}