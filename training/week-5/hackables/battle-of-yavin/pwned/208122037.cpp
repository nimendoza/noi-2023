#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int solve(int N, int D, vector<ii> arr) {
	int dp[D + 1];	// maximum value for cost exactly d
	for (int i = 0; i <= D; i++) {
		dp[i] = -1e9;
	}
	dp[0] = 0;
	for (int i = 0; i <= D; i++) {
		for (int j = 0; j < N; j++) {
			if (i - arr[j].se >= 0)
				dp[i] = max(dp[i], dp[i - arr[j].se] + arr[j].fi);
		}
	}
	int maximum = 0;
	for (int i = 0; i <= D; i++) {
		maximum = max(maximum, dp[i]);
	}
	return maximum;
}

int main() {
	int times;
	cin>>times;
	for (int i = 0; i < times; i++) {
		int N, D;
		cin>>N>>D;
		vector<ii> arr(N);
		for (int j = 0; j < N; j++) {
			cin>>arr[j].fi>>arr[j].se;
		}
		cout<<solve(N, D, arr)<<endl;
	}
}