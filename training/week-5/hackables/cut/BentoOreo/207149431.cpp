#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int posmaxid(vector<int> arr){
    int id = -1;
    int m = -1;
    for(int i = 0; i < arr.size(); i++){
        if (arr[i] > m){
            id = i;
            m = arr[i];
        }
    }
    return id;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, c;
        cin >> n >> c;
        vector<int> arr;
        int val;
        for(int i = 0; i < n; i++){
            cin >> val;
            arr.push_back(val);
        }
        bool flag = true;
        int m,temp;
        int maxodd = 0;
        while(c-- && arr.size() >= 1){
            m = posmaxid(arr);
            if (arr[m] % 2 != 0){
                maxodd = max(maxodd, arr[m]);// i will remove and ignore these.
                arr.erase(arr.begin()+m);
            } else {
                temp = arr[m]/2;
                arr[m] = temp;
                arr.push_back(temp);
            }
        }
        m = posmaxid(arr);
        cout << max(arr[m],maxodd) << endl;
    }
}