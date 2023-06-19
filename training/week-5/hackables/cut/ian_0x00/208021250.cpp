#include<iostream>
#include<queue>
using namespace std;
using ll=long long;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        ll c,b;cin>>c;
        priority_queue<ll>pq;
        for(int j=0;j<n;j++){
            cin>>b;pq.push(b);
        }
        for(ll j=0;j<c;j++){
            ll maxval=pq.top();pq.pop();
            pq.push(maxval/2LL);
            pq.push(maxval%2LL==0?maxval/2LL:maxval/2LL+1LL);
        }
        cout<<pq.top()<<endl;
    }
    return 0;
}