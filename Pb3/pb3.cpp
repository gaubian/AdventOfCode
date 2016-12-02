#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int pos = 5;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            int c = s[i];
            if(c == 'L' && pos % 3 > 0) pos--;
            if(c == 'R' && pos % 3 < 2) pos++;
            if(c == 'U' && pos > 2) pos -= 3;
            if(c == 'D' && pos < 6) pos += 3;
        }
        cout << pos + 1;
    }
    cout << endl;
}