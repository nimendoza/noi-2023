#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int parents[500006];
int answers[500006][2];
//use dp on subtrees (may be wrong terminology?)
//[no restrictions with this subtree, this subtree but parent isn't chosen]

int main()
{
	int n, paren;
	cin >> n;
	parents[1]=0;
	for (int i=2; i<=n; i++)
		cin >> parents[i];
	for (int i=n; i>0; i--)
	{
		answers[i][0]++;
		answers[i][0]=max(answers[i][0], answers[i][1]);
		paren=parents[i];//useless if i=1
		answers[paren][0]+=answers[i][1];
		answers[paren][1]+=answers[i][0];
	}
	cout << answers[1][0] << '\n';
}