#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> PA = {0};
        vector<int> A = {0};
        int count = 0, currSum = 0, ans = 0, Ai = 0;

        char prev;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (i == 0) {
                prev = c;
            } else if (c != prev) {
                A.push_back(Ai);
                PA.push_back(currSum);
                prev = c;
                Ai = 0;
            }

            if (c == '1') {
                Ai -= 1;
                currSum -= 1;
                count += 1;
            }
            else {
                Ai += 1;
                currSum += 1;
            }

            
        }
        A.push_back(Ai);
        PA.push_back(currSum);

        int BestI = 0, BestJ = 0;
        int s = PA.size();
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s; j++) {
                prev = ans;
                ans = min(PA[j]-PA[i],ans);
                if (ans != prev) {
                    BestI = i;
                    BestJ = j;
                }
            }
        }


        count += ans;
        ans = 0;
        currSum = PA[BestI];

        for (int i = BestI + 1; i < s; i++) {
            if (i <= BestJ) {
                currSum -= A[i];
            } else {
                currSum += A[i];
            }

            PA[i] = currSum;
        }

        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s; j++) {
                ans = min(PA[j]-PA[i],ans);
            }
        }
        

        
        cout << ans + count << endl;
    }
    return 0;
}