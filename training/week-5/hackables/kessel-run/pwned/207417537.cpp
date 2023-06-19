#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
	int N, H;
	cin>>N>>H;
	int costs[N];
	for (int i = 0; i < N; i++) {
		cin>>costs[i];
	}
	vi dp(H + 1, 1e9);	// min bottles for i milligrams
	dp[0] = 0;
	for (int i = 0; i <= H; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= costs[j])
				dp[i] = min(dp[i], dp[i - costs[j]] + 1);
		}
	}
	cout<<dp[H]<<endl;
}