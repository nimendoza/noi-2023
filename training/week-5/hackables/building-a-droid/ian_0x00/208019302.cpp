#include<iostream>
#include<map>
using namespace std;
using ll=long long;
ll p[3],v[3],c;int q;
map<ll,ll>m;
ll dafunc(ll k){
    if(m[k])return m[k];
    ll mv=0;
    for(int i=0;i<3;i++){
        if(p[i]<=k)mv=max(mv,dafunc(k-p[i])+v[i]);
    }
    m[k]=mv;return mv;
}
int main(){
    p[0]=1;
    cin>>q>>p[1]>>p[2]>>v[0]>>v[1]>>v[2];
    for(int i=0;i<q;i++){
        cin>>c;cout<<dafunc(c)<<endl;
        m.clear();
    }
    return 0;
}