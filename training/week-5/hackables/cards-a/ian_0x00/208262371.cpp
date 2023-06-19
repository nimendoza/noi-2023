#include<iostream>
using namespace std;
using ll=long long;
int main(){
    int t;cin>>t;
    for(int _t=0;_t<t;_t++){
        int n;cin>>n;
        ll arr[n],maxval;
        pair<int,int>maxpair;
        bool init=false;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ll tmp=0;
                for(int z=i;z<=j;z++)tmp+=arr[z];
                if(!init||tmp>maxval){
                    init=true;
                    maxval=tmp;
                    maxpair.first=i;
                    maxpair.second=j;
                }
            }
        }
        ll maxele,sum=0;init=false;
        for(int i=maxpair.first;i<=maxpair.second;i++){
            if(!init||arr[i]>maxele){
                init=true;
                maxele=arr[i];
            }sum+=arr[i];
        }
        cout<<sum-maxele<<endl;
    }
    return 0;
}