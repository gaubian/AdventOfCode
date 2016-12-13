#include <bits/stdc++.h>

using namespace std;

bool is_ok(string s) {
    set<pair<char,char>> outside, inside;
    bool is_in = false, ans = false;
    for(int i = 0; i + 2 < s.size(); i++) {
        if(s[i] == '[') is_in = true;
        else {
            if(s[i] == ']') is_in = false;
            else {
                if(s[i] != s[i+1] && s[i] == s[i+2]
                && s[i+1] != '[' && s[i+1] != ']') {
                    if(is_in) inside.insert({s[i],s[i+1]});
                    if(!is_in) outside.insert({s[i],s[i+1]});
                }
            }
        }
    }
    for(pair<char,char> xy : outside) {
        if(inside.find({xy.second,xy.first}) != inside.end()) ans = true;
    }
    return ans;
}

int main() {
	string s;
	int count = 0;
	while(cin >> s) if(is_ok(s)) count++;
    cout << count << endl;
}