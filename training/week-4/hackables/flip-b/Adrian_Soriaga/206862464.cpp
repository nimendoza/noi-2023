// might tle with 1010101010... 
// goal is min 1's aka max 0's
// edge cases all 1's or all 0's
//
#include <bits/stdc++.h>
using namespace std;
vector<int> ind(vector<int> g){
    vector<int> i;
    int ans= - 200001, end =0 , l=0 , r=0 , x=0;
    for (int i =0; i<g.size();i++){
        end += g[i];
        if (ans<end) {ans =end;
        l = x;
        r = i;}
        if (end<0) {end=0; x=i+1;}
    }
    i.push_back(l); i.push_back(r); i.push_back(ans);
    return i;
}
int main(){
    ios::sync_with_stdio(false);
    int t,o,z,n,ans; cin>>t;string s;
    vector <int> d;
    while (t--){        o=0,z=0,ans=0;
        vector<int> g;
        cin>>n;
        cin>>s; s+="2";
        for (int i=0;i<n;i++){
            if (s[i] =='0') z+=1;
            else if (s[i] =='1') o+=1;
            if (s[i+1]!=s[i]) {
                ans +=o;
                if (o!=0) g.push_back(o);
                else g.push_back(-z);
                o=0,z=0;
            }
        }
    d= ind(g);
    if (d[2]>0) {ans -=d[2];
    for (int i=d[0]; i<=d[1];i++){
        g[i] = -g[i];
    }}
    d= ind(g);
    if (d[2] <=0) cout<<ans<<"\n";
    else  cout<< ans-d[2]<<"\n";
    }
}