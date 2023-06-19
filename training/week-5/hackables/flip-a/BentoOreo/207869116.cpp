#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solve(int L, string ans){
    vector <int> ones = {0},zeros = {0};
    int oc = 0, zc = 0;
    for(char &c : ans){
        if (c == '0'){
            zc++;
        } else {
            oc++;
        }
        zeros.push_back(zc);
        ones.push_back(oc);
    }
    if(oc == 0){
        return 1;
    }
    int min1s = oc; //do nothing
    for(int i = 0; i <= L; i++){
        for(int j = i + 1; j <= L; j++){
            int oinsub = ones[j] - ones[i];
            int zinsub = zeros[j] - zeros[i];
            min1s = min(oc - oinsub + zinsub, min1s);
        }
    }
    return min1s;
}
int main(){
    int testcases;
    cin >> testcases;
    for(int x = 0; x < testcases; x++){
        int L;
        cin >> L;
        string ans;
        cin >> ans;
        cout << solve(L,ans) << endl;
    }
}