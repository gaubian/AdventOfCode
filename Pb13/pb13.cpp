#include <bits/stdc++.h>

using namespace std;

bool is_ok(string s) {
    bool supp_outs = false, is_in = false;
    for(int i = 0; i + 3 < s.size(); i++) {
        if(s[i] == '[') is_in = true;
        else {
            if(s[i] == ']') is_in = false;
            else {
                if(s[i] != s[i+1] && s[i] == s[i+3] && s[i+1] == s[i+2]) {
                    if(is_in) return false;
                    else supp_outs = true;
                }
            }
        }
    }
    return supp_outs;
}

int main() {
	string s;
	int count = 0;
	while(cin >> s) if(is_ok(s)) count++;
    cout << count << endl;
}