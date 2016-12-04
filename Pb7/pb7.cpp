#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int cpt = 0;
    while(cin >> s) {
        bool flag = true;
        map<int,int> letters;
        priority_queue<pair<int,int>> heap_let;
        int id = 0;
        int i = 0;
        while(s[i] > '9' || s[i] == '-') {
            if(letters.find(s[i]) == letters.end()) letters[s[i]] = 1;
            else letters[s[i]]++;
            i++;
        }
        for(pair<int,int> occulet : letters) {
            if(occulet.first != '-')
                heap_let.push({occulet.second,-occulet.first});
        }
        while(s[i++] != '[') id = (10 * id) + s[i-1] - '0';
        for(int j = 0; j < 5 && flag; j++) {
            cout << s[i+j] << " " << heap_let.top().first << " " << heap_let.top().second << endl;
            flag = (s[i+j] == - heap_let.top().second);
            heap_let.pop();
        }
        if(flag) cpt += id;
    }
    cout << cpt << endl;
}