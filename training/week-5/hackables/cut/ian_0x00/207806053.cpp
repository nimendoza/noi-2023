#include<iostream>
#include<queue>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,c,buf;cin>>n>>c;
        priority_queue<int>pq;
        for(int j=0;j<n;j++){
            cin>>buf;pq.push(buf);
        }
        for(int j=0;j<c;j++){
            int maxval=pq.top();pq.pop();
            pq.push(maxval/2);
            pq.push(maxval%2==0?maxval/2:maxval/2+1);
        }
        cout<<pq.top()<<endl;
    }
    return 0;
}