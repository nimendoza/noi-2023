#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string binstr;
    vector<int> continousones;
    long long int len, big = 0, cur = 0, ones = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> len;
        cin >> binstr;
        for(char c : binstr){
            if(c == '1'){
                cur++;
                ones++;
            } else {
                continousones.push_back(cur);
                cur = 0;
            }
        }
        continousones.push_back(cur);
        sort(continousones.rbegin(),continousones.rend());
        if(continousones.size() == 0){
            cout << ones << endl;
        } else if (continousones.size() == 1){
            cout << 0 << endl;
        } else {
            cout << ones - continousones.at(0) - continousones.at(1) << endl;
        }
        ones = 0;
        cur = 0;
        big = 0;
        continousones.clear();
    }
}