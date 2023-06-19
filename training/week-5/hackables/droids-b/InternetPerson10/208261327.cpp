#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll BIG = 99999999999;

void solve() {
    int n, k;
    cin >> n >> k;
    set<pair<ll, int>> s1, s2;
    vector<pair<pair<ll, ll>, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first.first;
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i].first.second;
    }
    for(int i = 0; i < n; i++) {
        v[i].second = i;
        s1.insert({0, -i-1});
        s1.insert({0, -n-i-1});
        s2.insert({v[i].first.first + v[i].first.second, i});
    }
    s1.insert({0, -2*n-1});
    s1.insert({0, -2*n-2});
    s2.insert({0, n});
    auto it1 = --s1.end();
    auto it2 = --s2.end();
    s1.insert({BIG, n});
    s1.insert({BIG, n+1});
    for(int i = 0; i < n; i++) {
        s2.insert({BIG, -i-1});
    }
    sort(v.rbegin(), v.rend());
    ll ans = -1, tot = 0;
    auto recalc = [&]() {
        // cout << "Start with " << k << endl;
        while(k < 0) {
            it2++;
            k += 2;
            tot -= (*it2).first;
        }
        while(k > 0) {
            tot += (*it1).first;
            k--;
            it1--;
        }
        while(true) {
            pair<ll, int> p1a = *(++it1);
            pair<ll, int> p1b = *(++it1);
            pair<ll, int> p2 = *it2;
            if(p1a.first + p1b.first >= p2.first) {
                it1--;
                it1--;
                break;
            }
            else {
                tot -= p1a.first;
                tot -= p1b.first;
                tot += p2.first;
                it2--;
            }
        }
        // cout << tot << endl;
        ans = max(ans, tot);
    };
    recalc();
    for(int i = 0; i < n; i++) {
        auto p = v[i];
        it1++;
        pair<ll, int> p1 = *it1;
        pair<ll, int> p2 = *it2;
        /*
        cout << "In s1: ";
        for(auto p : s1) cout << p.first << ' ' << p.second << ", ";
        cout << "\nIn s2: ";
        for(auto p : s2) cout << p.first << ' ' << p.second << ", ";
        cout << "\nBorders " << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << endl;
        */
        pair<ll, int> q1 = {p.first.second, p.second};
        pair<ll, int> q2 = {p.first.first + p.first.second, p.second};
        tot += p.first.first;
        k--;
        s1.insert(q1);
        if(q1 > p1) {
            tot -= p1.first;
            tot += q1.first;
            it1++;
        }
        it1--;
        if(q2 > p2) {
            tot -= q2.first;
            k += 2;
        }
        if(q2 == p2) {
            it2--;
        }
        s2.erase(q2);
        recalc();
    }
    cout << ans << '\n';
    s1.clear();
    s2.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
