#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,h;cin>>n>>h;
    int c[n];
    for(int i=0;i<n;i++)cin>>c[i];
    sort(c,c+n,greater<int>());
    int ans=0;int count=0;
    for(int i=0;i<n;){
        if(ans==h)break;
        if(ans+c[i]<=h){
            ans+=c[i];
            count++;
        }
        else i++;
    }
    cout<<count;
    return 0;
}