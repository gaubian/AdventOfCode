#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int nb;
    bool flag = true;
    pair<int,int> pos = {0,0};
    pair<int,int> dir = {0,1};
    while(cin >> c) {
        if(flag) flag = false;
        else cin >> c;
        cin >> nb;
        int aux = dir.first;
        dir.first = dir.second;
        dir.second = aux;
        if(c == 'L') dir.first *= -1;
        else dir.second *= -1;
        pos.first += nb * dir.first;
        pos.second += nb * dir.second;
    }
    cout << abs(pos.first) + abs(pos.second) << endl;
}