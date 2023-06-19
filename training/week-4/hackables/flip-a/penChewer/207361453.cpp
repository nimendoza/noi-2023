#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, numI=0, num=0, highest=0; string s; cin >> n >> s;
        for (char c : s) {
            if (c=='1') {
                numI++;
                num++;
                if (highest < num)
                    highest = num;
            }
            else if (num>0)
                num--;
        }
        cout << numI-highest << endl;
    }
    return 0;
}