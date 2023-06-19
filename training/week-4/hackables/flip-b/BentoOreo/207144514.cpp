#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
pair<vector<int>,int> grouponeandzero(string binstr){
    vector<int> arr;
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
    pair<vector<int>,int> out = {arr, oc};// return the array and number of ones 
    return out;
}
vector<int> maxsumcontinoussubarr(vector<int> arr){
    int maxrn = -20000000, BIGGEST = -20000000;
    int index = 0;
    int curroot = 1,curlen = 1;
    int bestroot = 1, bestlen = 1;
    for(int elem: arr){
        if(maxrn + elem < elem){//my current running total fails
            maxrn = elem;
            curroot = index;
            curlen = elem;
        } else {
            maxrn = maxrn + elem;
            curlen += abs(elem);
        }
        if(maxrn > BIGGEST){
            BIGGEST = maxrn;
            bestroot = curroot;
            bestlen = curlen;
        }
        index += abs(elem);
    }
    vector<int> out = {BIGGEST,bestroot,bestlen};//SUM, ROOT, LENGTH
    return out;
}
int main(){
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int L;
        cin >> L;
        string binstr;
        cin >> binstr;
        for(int i = 1; i <= 2; i++){
            pair<vector<int>,int> retval = grouponeandzero(binstr);
            int oc = retval.second;
            vector<int> arr = retval.first;
            int SUM, ROOT, LENGTH;
            vector<int> retval2 = maxsumcontinoussubarr(arr);
            SUM = retval2[0];
            ROOT = retval2[1];
            LENGTH = retval2[2];
            for(int i = 0; i < LENGTH; i++){ 
                binstr[ROOT+i] = (binstr[ROOT+i] == '1') ? '0':'1';//flip bits in the best subarr
            }   
        }
        int cnt;
        cnt = count(binstr.begin(),binstr.end(),'1');
        cout << cnt;
    }
}
 