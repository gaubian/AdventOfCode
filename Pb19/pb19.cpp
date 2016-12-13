#include <bits/stdc++.h>

using namespace std;


int main() {
	int infin = 1000000;
	map<int,set<int>> bot;
	vector<pair<int,pair<int,int>>> instructions;
	string s;
	while(cin >> s) {
		if(s == "value") {
			int x, y;
			cin >> x >> s >> s >> s >> y;
			bot[y].insert(x);
		}
		else {
			int giver, low, hi;
			cin >> giver >> s >> s >> s >> s >> low;
			if(s != "bot") low = infin;
			cin >> s >> s >> s >> s >> hi;
			if(s != "bot") hi = infin;
			instructions.push_back({giver,{low,hi}});
		}
	}
	for(int lol = 0; lol < 250; lol++) {
	for(int i = 0; i < instructions.size(); i++) {

		pair<int,pair<int,int>> ins = instructions[i];
		int giver = ins.first;
		int low = ins.second.first;
		int hi = ins.second.second;
		if(bot[giver].size() == 2 && bot[low].size() < 2
			&& bot[hi].size() < 2) {
			int mini = infin;
			for(auto y : bot[giver]) mini = min(mini,y);
			int maxi = 0;
			for(auto y : bot[giver]) maxi = max(maxi,y);
			bot[giver].erase(mini);
			bot[giver].erase(maxi);
			bot[low].insert(mini);
			bot[hi].insert(maxi);
			if(mini == 17 && maxi == 61) cout << giver << endl;
		}
	}
	}
}