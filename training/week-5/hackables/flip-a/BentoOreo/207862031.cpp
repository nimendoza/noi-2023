#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int flip(string ans, int L, int R){
    for(int i = L; i <= R; i++){
        if (ans.at(i) == '0'){
            ans.at(i) = '1';
        } else {
            ans.at(i) = '0';
        }
    }
    return count(ans.begin(),ans.end(),'1');
}
int solve(int L, string ans){
    int min1s = INT_MAX; //do nothing
    for(int i = 0; i < L; i++){
        for(int j = i; j < L; j++){
            min1s = min(min1s, flip(ans,i,j));
        }
    }
    return min1s;
}
int main(){
    int testcases;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> testcases;
    for(int x = 0; x < testcases; x++){
        int L;
        cin >> L;
        string ans;
        cin >> ans;
        cout << solve(L,ans) << endl;
    }
}