#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int p = 0; p < t; p++){
        int n,bullets;
        cin >> n >> bullets;
        vector<pair<int,int> > vect;
        int value,defence;
        for(int i = 0; i < n; i++){
            cin >> value >> defence;
            pair<int, int> temp = {value,defence};
            vect.push_back(temp);
        }
        sort(vect.begin(),vect.end(),[&](const auto &a,const auto &b){
            if(a.first * b.second == b.first * a.second){
                return a.second < b.second; //smaller defence first
            }
            return a.first * b.second > b.first * a.second;
        });
        int quality = 0;
        for(auto elem: vect){
            if(elem.second <= bullets){
                //maximise the number of units I buy
                int units = bullets / elem.second; // I just want integer anyways
                bullets -= units * elem.second; //deduct the cost
                quality += units * elem.first;
            }
        }
        cout << quality << endl;
    }

}