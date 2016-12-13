#include <bits/stdc++.h>

using namespace std;

int infi = 100000;

bool is_ok(vector<int> stt) {
    if(stt[10] == 4 || stt[10] == -1) return false;
    for(int i = 0; i < 5; i++) {
        if(stt[2*i] != stt[2*i + 1]) {
            for(int j = 0; j < 5; j++)
                if(stt[2*j + 1] == stt[2*i]) return false;
        }
    }
    return true;
}

vector<vector<int>> next(vector<int> stt) {
    cout << stt.size() << endl;
   vector<vector<int>> ans;
    int my_pos = stt[10];
    for(int i = 0; i < 10; i++) {
    for(int j = i; j < 10; j++) {
        if(stt[i] == stt[j] && stt[i] == my_pos) {
            vector<int> plus (11);
            for(int i = 0; i < 11; i++) plus[i] = stt[i];
            plus[i] = stt[i] + 1;
            plus[j] = stt[j] + 1;
            plus[10]++;
            vector<int> less (11);
            for(int i = 0; i < 11; i++) less[i] = stt[i];
            less[i] = stt[i] - 1;
            less[j] = stt[j] - 1;
            less[10]--;
            ans.push_back(plus);
            ans.push_back(less);
        }
    }
    }
    return ans;
}

long long code(vector<int> tab) {
    long long ans = 0;
    for(int i = 0; i < tab.size(); i++) ans = tab[i] + (4 * ans);
    return ans;
}

int dyna(map<long long,int> &dyn, vector<int> stt) {
    cout << "lol" << endl;
    long long code_stt = code(stt);
	if(dyn.find(code_stt) == dyn.end()) {
        if(is_ok(stt)) {
            cout << "a" << endl;
            dyn.insert({code_stt,infi});
            cout << "b" << endl;
            vector<vector<int>> option = next(stt);
            cout << "swag" << endl;
            int ans = infi;
            for(vector<int> next_opt : option)
                ans = min(ans,dyna(dyn,next_opt));
            return ans;
        }
        else return infi;
	}
	else {cout << "swag" << endl; return dyn[code_stt];}
}

int main() {
    map<long long,int> dyn;
    dyn[code({3,3,3,3,3,3,3,3,3,3,3})] = 0;
    int ans = dyna(dyn,{0,0,2,1,2,1,2,1,2,1,0});
    cout << ans;
}