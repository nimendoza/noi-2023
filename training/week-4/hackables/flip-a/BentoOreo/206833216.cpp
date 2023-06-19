#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string binstr;
    long long int len, big = 0, cur = 0, ones = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> len;
        cin >> binstr;
        for(char c : binstr){
            if(c == '1'){
                cur++;
                ones++;
                big = max(big,cur);
            } else {
                cur = 0;
            }
        }
        cout << ones - big << '\n';
        ones = 0;
        cur = 0;
        big = 0;
    }

}