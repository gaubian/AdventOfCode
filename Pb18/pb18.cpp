#include <bits/stdc++.h>

using namespace std;

long long score(string s) {
    if(s.empty()) return 0;
    else {
        if(s[0] > '9') return 1 + score(s.substr(1,s.size() - 1));
        else {
            int x = 0, y = 0, i = 1;
            for(;s[i] != 'x'; i++) x = 10 * x + s[i] - '0';
            for(i++; s[i] != ')'; i++) y = 10 * y + s[i] - '0';
            long long sc_sub = score(s.substr(i+1,x));
            return (y * sc_sub) + score(s.substr(i+1+x,s.size()-i-1-x));
        }
    }
}

int main(){
    long long ans = 0;
    string s;
    while(cin >> s) ans += score(s);
    cout << ans << endl;
}