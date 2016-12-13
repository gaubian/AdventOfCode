#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int,map<char,int>> my_map;
	string s;
	while(cin >> s) for(int i = 0; i < s.size(); i++) my_map[i][s[i]]++;
	for(pair<int,map<char,int>> xy : my_map) {
		map<char,int> map_x = xy.second;
		char most_freq;
		int nb_seen = 100000;
		for(pair<char,int> ch_seen : map_x) {
			if(ch_seen.second < nb_seen) {
				nb_seen = ch_seen.second;
				most_freq = ch_seen.first;
			}
		}
		cout << most_freq;
	}
}