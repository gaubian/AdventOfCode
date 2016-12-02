#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int nb;
    bool not_found = true;
    bool flag = true;
    pair<int,int> pos = {0,0};
    pair<int,int> dir = {0,1};
    set<pair<int,int>> my_set = {pos};
    while(not_found && cin >> c) {
        if(flag) flag = false;
        else cin >> c;
        cin >> nb;
        int aux = dir.first;
        dir.first = dir.second;
        dir.second = aux;
        if(c == 'L') dir.first *= -1;
        else dir.second *= -1;
        for(int i = 0; (i < nb) && not_found; i++) {
            pos.first += dir.first;
            pos.second += dir.second;
            not_found = (my_set.count(pos) == 0);
            my_set.insert(pos);
        }
    }
    cout << abs(pos.first) + abs(pos.second) << endl;
}