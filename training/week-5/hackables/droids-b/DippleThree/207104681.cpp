#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

priority_queue<pair<ll, int>> newd, botd, newb, insing, dotb;
vector<ll> b, d;
vector<int> state;

void s0(int i){
    state[i] = 0;
    newb.push({b[i], i});
    newd.push({b[i] + d[i], i});
}

void s1(int i){
    state[i] = 1;
    insing.push({-b[i], i});
    botd.push({d[i], i});
}

void s2(int i){
    state[i] = 2;
    dotb.push({-d[i], i});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        while (!newd.empty()) newd.pop();
        while (!botd.empty()) botd.pop();
        while (!newb.empty()) newb.pop();
        while (!insing.empty()) insing.pop();
        while (!dotb.empty()) dotb.pop();
        int n, k;
        cin >> n >> k;
        ll mx = 0;
        b.resize(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        d.resize(n);
        for (int i = 0; i < n; i++) cin >> d[i];
        state = vector<int>(n, 0);
        for (int i = 0; i < n; i++){
            newd.push({d[i] + b[i], i});
            newb.push({b[i], i});
        }
        while (k--){
            while (!newd.empty() && state[newd.top().second] != 0){
                newd.pop();
            }
            while (!newb.empty() && state[newb.top().second] != 0){
                newb.pop();
            }
            while (!insing.empty() && state[insing.top().second] != 1){
                insing.pop();
            }
            while (!botd.empty() && state[botd.top().second] != 1){
                botd.pop();
            }
            while (!dotb.empty() && state[dotb.top().second] != 2){
                dotb.pop();
            }
            ll x = (newd.empty() || insing.empty()) ? -1 : newd.top().first + insing.top().first;
            ll y = botd.empty() ? -1 : botd.top().first;
            ll z = newb.empty() ? -1 : newb.top().first;
            ll q = (dotb.empty() || newd.empty()) ? -1 : dotb.top().first + newd.top().first;
            ll m = max({x, y, z, q});
            mx += m;
            if (m == z){
                s1(newb.top().second);
                newb.pop();
            } else if (m == x){
                s0(insing.top().second);
                insing.pop();
                s2(newd.top().second);
                newd.pop();
            } else if (m == y){
                s2(botd.top().second);
                botd.pop();
            } else {
                s2(newd.top().second);
                newd.pop();
                s1(dotb.top().second);
                dotb.pop();
            }
        }
        cout << mx << "\n";
    }
}