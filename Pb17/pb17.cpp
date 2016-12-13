#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    char c;
    int x, y;
    int ans = 0;
    while(cin >> c) {
        if(c == '(') {
            cin >> x >> c >> y >> c;
            ans += x * y;
            for(int i = 0; i < x; i++) cin >> c;
        }
        else ans++;
    }
    cout << ans;
}