#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, cpt = 0;
	while(cin >> a >> b >> c) if(2 * max(a,max(b,c)) < a + b + c) cpt++;
	cout << cpt << endl;
}