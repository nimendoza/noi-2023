#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t,n,b,c,d,m,g,h,o;
    string a,v;

    cin >> t;

    for(int q = 0; q < t; ++q){
        cin >> n >> a;
        b = 0;
        g = 0;
        c = 0;
        d = 0;
        o = 0;

        for (int i = 0; i < a.length(); ++i) {
            if(b == 0 && a[i] == '1'){
                c = i;
                b++;
            }
            else if(a[i] == '1'){
                b++;
            }
            else{
                d--;
            }

            if(b + d < 0){
                b = 0;
                d = 0;
            }

            else if(b + d > g){
                g = b + d;
                h = b - d;
                o = c;
            }
        }

        for (int i = o; i < o + h; ++i) {
            if(a[i] == '1'){
                a[i] = '0';
            }
            else{
                a[i] = '1';
            }
        }

        b = 0;
        g = 0;
        c = 0;
        d = 0;
        v = "";

        for (int i = 0; i < a.length(); ++i) {
            if(b == 0 && a[i] == '1'){
                c = i;
                b++;
            }
            else if(a[i] == '1'){
                b++;
            }
            else{
                d--;
            }

            if(b + d < 0){
                b = 0;
                d = 0;
            }

            else if(b + d > g){
                g = b + d;
                v = a.substr(c,b - d);
            }
        }


        m = count(v.begin(),v.end(), '1');
        cout << count(a.begin(),a.end(),'1') - m + (v.length() - m)<< '\n';
    }
}