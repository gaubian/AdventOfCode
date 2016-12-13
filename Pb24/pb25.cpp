#include <bits/stdc++.h>

using namespace std;

int val(map<string,int> regis, string s) {
	if(s[0] > '9') return regis[s];
	else return atoi(s.c_str());
}

int main() {
	string name, fst_arg, snd_arg;
	map<string,int> regis = {{"a", 0}, {"b", 0}, {"c", 1}, {"d", 0}};
	vector<vector<string>> instruc;
	while(cin >> name) {
		if(name == "cpy" || name == "jnz") {
			cin >> fst_arg >> snd_arg;
			instruc.push_back({name,fst_arg,snd_arg});
		} 
		else {
			cin >> fst_arg;
			instruc.push_back({name,fst_arg});	
		}
	}
	int i = 0;
	while(i < instruc.size()) {
		vector<string> ans = instruc[i];
		char fst_char = ans[0][0];
		switch (fst_char) {
			case 'i' : regis[ans[1]]++; ++i; break;
			case 'd' : regis[ans[1]]--; ++i; break;
			case 'c' : regis[ans[2]] = val(regis,ans[1]); ++i; break;
			case 'j' : if(val(regis,ans[1]) != 0)
						  i += val(regis,ans[2]);
						  else ++i;
		}
	}
	cout << regis["a"] << endl;
}