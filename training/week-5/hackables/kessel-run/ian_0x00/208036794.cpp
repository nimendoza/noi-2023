#include<iostream>
using namespace std;
int main(){
    int n,h;cin>>n>>h;
    int c[n];
    for(int i=0;i<n;i++)cin>>c[i];
    int dp[h+1];dp[0]=0;
    for(int i=1;i<h+1;i++)dp[i]=h;
    for(int i=1;i<=h;i++){
        for(int j=0;j<n;j++){
            if(c[j]<=i)dp[i]=min(dp[i],dp[i-c[j]]+1);
        }
    }
    cout<<dp[h];
    return 0;
}