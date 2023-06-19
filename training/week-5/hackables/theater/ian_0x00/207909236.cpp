#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
using davect=vector<pair<ll,ll>>;
davect elim_int(davect arr,pair<ll,ll>e){
    davect tmp;
    for(const auto&x:arr){
        if(x.second<e.first||x.first>e.second)
            tmp.push_back(x);
    }
    return tmp;
}
int rec(davect arr){
    int maxval=0;
    for(const auto&x:arr)
        maxval=max(maxval,1+rec(elim_int(arr,x)));
    return maxval;
}
int main(){
    int t;cin>>t;
    for(int _t=0;_t<t;_t++){
        int n;cin>>n;
        davect gr(n);
        for(int i=0;i<n;i++)
            cin>>gr[i].first>>gr[i].second;
        cout<<rec(gr)<<endl;;
    }
    return 0;
}