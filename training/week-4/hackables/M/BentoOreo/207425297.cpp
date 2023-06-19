#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, target, val, coins = 0;
    cin >> n >> target;
    vector <int> choices;
    for (int i = 0; i < n; i++){
        cin >> val;
        choices.push_back(val);
    }
    sort(choices.rbegin(),choices.rend());
    for(int elem : choices){
        if(elem <= target){
            coins += target / elem;
            target = target % elem;
        }
    }
    cout << coins << endl;
}