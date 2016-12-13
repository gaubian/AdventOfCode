#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	char c;
	int x, y, count = 0;
	vector<vector<bool>> mat(6,vector<bool> (50,false));
	while(cin >> s) {
		if(s == "rect") {
			cin >> x >> c >> y;
			for(int i = 0; i < y; i++) {
				for(int j = 0; j < x; j++) mat[i][j] = true;
			}
		}
		else {
			cin >> s;
			if(s == "row") {
                cin >> c >> c >> x >> s >> y;
                vector<bool> row(50);
                for(int i = 0; i < 50; i++) row[(i+y) % 50] = mat[x][i];
                for(int i = 0; i < 50; i++) mat[x][i] = row[i];
			}
			else {
                cin >> c >> c >> x >> s >> y;
                vector<bool> col(6);
                for(int i = 0; i < 6; i++) col[(i+y) % 6] = mat[i][x];
                for(int i = 0; i < 6; i++) mat[i][x] = col[i];
			}
		}
	}
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 50; j++) if(mat[i][j]) count++; 
    }
    cout << count << endl;
}