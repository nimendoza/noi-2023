#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
	int times;
	cin>>times;
	for (int i = 0; i < times; i++) {
		int N, K;
		cin>>N>>K;
		ll t1[N];
		for (int j = 0; j < N; j++) {
			cin>>t1[j];
		}
		ll t2[N];
		for (int j = 0; j < N; j++) {
			cin>>t2[j];
			t2[j] += t1[j];
		}
		ll dp[N + 1][K + 1];	// up to nth, pick exactly 0 to K
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= K; k++) {
				dp[j][k] = 0;
			}
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= K; k++) {
				dp[j][k] = dp[j - 1][k];
				if (k >= 1)
					dp[j][k] = max(dp[j][k], dp[j - 1][k - 1] + t1[j - 1]);
				if (k >= 2)
					dp[j][k] = max(dp[j][k], dp[j - 1][k - 2] + t2[j - 1]);
			}
		}
//		cout<<"ANSWER: ";
		cout<<dp[N][K]<<endl;
	}
}