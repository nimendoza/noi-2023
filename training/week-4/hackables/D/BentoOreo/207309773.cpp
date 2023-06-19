#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
void print(vector<long long int> a){
    for(long long int elem : a){
        cout << elem << " ";
    }
    cout << endl;
}

int main(){
    int len;
    cin >> len;
    vector <long long int> g = {0},h = {0},ans;
    long long int val;
    for(int i = 0; i < len; i++){
        cin >> val;
        g.push_back(val);
    }
    for(int i = 0; i < len; i++){
        cin >> val;
        h.push_back(val);
    }
    vector<long long int> gpresum,hpresum;
    gpresum.resize(len+1);
    hpresum.resize(len+1);
    partial_sum(g.begin(),g.end(),gpresum.begin());
    partial_sum(h.begin(),h.end(),hpresum.begin());
    for(int target = 1; target <= 2*len; target++){
        vector<pair<int,int> >sums;
        for(int i = 0; i <= min(target,len); i++){
            if(target - i <= len && i <= len){
                sums.push_back({i, target-i});
            }
        }
        long long int max_val = 0;
        for(auto elem: sums){
            max_val = max(max_val,gpresum[elem.first]+hpresum[elem.second]);
        }
        ans.push_back(max_val);
        sums.clear();
    }
    // print(ans);
    long long int temp = ans[0];
    for(int i = 1; i < ans.size(); i++){
        temp = temp ^ ans[i];
    }
    cout << temp << endl;
}