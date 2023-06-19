// might tle with 1010101010... 
// goal is min 1's aka max 0's
// edge cases all 1's or all 0's
#include <bits/stdc++.h>
using namespace std;
int sm(vector<int> g){
    int ans= - 200001, end =0;
    for (int i =0; i<g.size();i++){
        end += g[i];
        if (ans<end) ans =end;
        if (end<0) end=0;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int t,o,z,n,ans; cin>>t;string s;
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
    if (sm(g) <=0) cout<<ans<<"\n";
    else  cout<< ans-sm(g)<<"\n";
    
    }
}