#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }

int t,k,c;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> c;

		if(c == 1) {
			cout << k + 1 << endl;
			continue;
		} else if(k == 1) {
			cout << 1 << endl;
			continue;
		}

		if (gcd(k, c) != 1) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			long long int q, r, s, t;
			long long int r1 = k, r2 = c;
			long long int s1 = 1, s2 = 0;
			long long int t1 = 0, t2 = 1;
			while (r2 > 0) {
				q = r1 / r2;

				r = r1 - r2 * q;
				r1 = r2;
				r2 = r;

				s = s1 - s2 * q;
				s1 = s2;
				s2 = s;

				t = t1 - t2 * q;
				t1 = t2;
				t2 = t;
			}

			while (t1 < 0) t1 += k;
			if (t1 > 1000000000) printf("IMPOSSIBLE\n");
			else cout << t1 << endl;
		}
	}
	return 0;
}