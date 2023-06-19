#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    for(int _t=0;_t<t;_t++){
        int n;cin>>n;
        vector<pair<ll,ll>>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i].first>>a[i].second;
        sort(
            a.begin(),
            a.end(),
            [](pair<ll,ll>const&x,pair<ll,ll>const&y){
                return x.second<y.second;
            }
        );
        vector<pair<ll,ll>>s={a[0]};
        for(int i=1;i<n;i++)
            if(s.back().second<a[i].first)
                s.push_back(a[i]);
        cout<<s.size()<<endl;
    }
    return 0;
}