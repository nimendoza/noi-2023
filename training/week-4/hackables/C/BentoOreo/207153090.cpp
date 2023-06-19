#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &vc) {
    for (auto i : vc) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, c;
        cin >> n >> c;
        vector<int> arr = {0};//garbage value
        int val;
        for(int i = 0; i < n; i++){
            cin >> val;
            arr.push_back(val);
        }
        make_heap(arr.begin(),arr.end());
        int m,temp;
        int maxodd = 0;
        while(c--){
            m = arr.front();
            pop_heap(arr.begin(),arr.end());
            arr.pop_back();
            if (m % 2 != 0){
                maxodd = max(maxodd, m);// i will remove and ignore these.
            } else {
                temp = m/2;
                arr.push_back(temp);
                push_heap(arr.begin(),arr.end());
                arr.push_back(temp);
                push_heap(arr.begin(),arr.end());
            }
        }
        cout << max(arr.front(),maxodd) << endl;
    }
}