#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
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
        vector <int> ones ={0},zeros = {0};
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
        int maxratio = 0;
        for(int i = 0; i <= L; i++){
            for(int j = i; j <= L; j++){
                int oinsub = ones[j] - ones[i];
                int zinsub = zeros[j] - zeros[i];
                maxratio = max(oinsub-zinsub, maxratio);
            }
        }
        cout << oc - maxratio << endl;
        
    }
}