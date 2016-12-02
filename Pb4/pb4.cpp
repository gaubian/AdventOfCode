#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    char pos = '5';
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if( c == 'L' && pos != '1' && pos != '2'
            && pos != '5' && pos != 'A' && pos != 'D')
                pos--;
            if( c == 'R' && pos != '1' && pos != '4'
            && pos != '9' && pos != 'C' && pos != 'D')
                pos++;
            if( c == 'U' && pos != '5' && pos != '2'
            && pos != '1' && pos != '4' && pos != '9') {
                if( pos >= 'A' && pos < 'D') pos += '6' - 'A';
                else {
                    if(pos == '3' || pos == 'D') pos -= 2;
                    else pos -= 4;
                }
            }
            if( c == 'D' && pos != '5' && pos != 'A'
            && pos != 'D' && pos != 'C' && pos != '9') {
                if( pos >= '2' && pos < '5') pos += 4;
                else {
                    if(pos == '1' || pos == 'B') pos += 2;
                    else pos += 'A' - '6';
                }
            }
        }
        cout << pos;
    }
    cout << endl;
}