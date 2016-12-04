#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d, e, f, g, h, i, cpt = 0;
	while(cin >> a >> b >> c >> d >> e >> f >> g >> h >> i) {
		if(2 * max(a,max(d,g)) < a + d + g) cpt++;
		if(2 * max(b,max(e,h)) < b + e + h) cpt++;
		if(2 * max(c,max(f,i)) < c + f + i) cpt++;
	}
	cout << cpt << endl;
}