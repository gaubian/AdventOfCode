#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(cin >> s) {
        string line;
        int id = 0, i = 0;
        while(s[i] > '9' || s[i] == '-') line += s[i++];
        while(s[i++] != '[') id = (10 * id) + s[i-1] - '0';
        for(int j = 0; j < line.size(); j++) {
            if(line[j] == '-') cout << " ";
            else cout << (char) (((line[j] - 'a' + id) % 26) + 'a');
        }
        cout << id << endl;
    }
}