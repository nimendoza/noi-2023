#include<iostream>
#include<map>
using namespace std;
map<int,int>m;
int dafunc(int n,int k,int*v,int*c){
    if(m[k])return m[k];
    int mv=0;
    for(int i=0;i<n;i++){
        if(c[i]<=k)mv=max(mv,dafunc(n,k-c[i],v,c)+v[i]);
    }
    m[k]=mv;return mv;
}
int main(){
    int t;cin>>t;
    for(int _t=0;_t<t;_t++){
        int n,d;cin>>n>>d;
        int dp[n+1][d+1]={};
        int v[n],c[n];
        for(int i=0;i<n;i++)
            cin>>v[i]>>c[i];
        cout<<dafunc(n,d,v,c)<<endl;
    }
    return 0;
}