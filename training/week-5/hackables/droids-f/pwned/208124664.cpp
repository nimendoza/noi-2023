#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

vi children[500005];

int dp[500005];		// may be below, or the largest independent set including i
int dp2[500005];	// sum of largest independent sets of children

void dfs(int n) {
//	cout<<"at "<<n<<endl;
	dp[n] = 1;
	for (int i : children[n]) {
		dfs(i);
		dp[n] += dp2[i];
		dp2[n] += dp[i];
	}
	dp[n] = max(dp[n], dp2[n]);
}

int main() {
	int N;
	cin>>N;
	for (int i = 1; i < N; i++) {
		int p;
		cin>>p;
		p--;
		children[p].pb(i);
	}
	dfs(0);
/*
	cout<<"dp: ";
	for (int i = 0; i < N; i++) {
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<"dp2: ";
	for (int i = 0; i < N; i++) {
		cout<<dp2[i]<<" ";
	}
	cout<<endl;
*/
	cout<<max(dp[0], dp2[0])<<endl;
}