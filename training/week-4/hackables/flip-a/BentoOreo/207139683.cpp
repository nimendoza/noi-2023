#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int L;
        cin >> L;
        vector<int> arr;
        string binstr;
        cin >> binstr;
        int rt = 0;
        bool flip = false;
        int oc = 0;
        for(char c : binstr){
            if(c == '0'){
                if(rt > 0){//previous was negative
                    arr.push_back(rt);
                    rt = 0;
                }
                rt--;
            } else {
                if(rt < 0){
                    arr.push_back(rt);
                    rt = 0;
                }
                rt++;
                oc++;
            }
        }
        arr.push_back(rt);
        int maxrn = -20000000, BIGGEST = -20000000;
        for(int elem: arr){
            maxrn = max(maxrn + elem, elem);
            BIGGEST = max(BIGGEST,maxrn);
        }
        cout << oc-BIGGEST << endl;
    }
}
 