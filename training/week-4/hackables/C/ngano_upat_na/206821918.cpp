#include "bits/stdc++.h"
using namespace std;

void sol() {
    int n, c;
    cin >> n >> c;
    
    priority_queue<int> pq;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }   
    while (c--) {
        int a = pq.top();
        if (a == 1) {
            cout << 1 << '\n';
            return;
        }   
        if (a % 2 == 0) {
            pq.pop();
            pq.push(a/2);
            pq.push(a/2);
        }   
        else {
            pq.pop();
            pq.push(a/2);
            pq.push(a/2+1);
        }   
    }   
    cout << pq.top() << '\n';
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) sol();
}   