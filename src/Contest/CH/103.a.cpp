#ifdef LOCAL
#include<pch.h>
#else
#define TEST(nl,nr) void nl##nr()
#define EXPECT_EQ(l,r) 
#include<iostream>
#include<algorithm>
using namespace std;
#endif
int gcd(int l, int r) {
	if (r == 0)return l;
	return gcd(r, l % r);
}
TEST(gcd, func) {
	EXPECT_EQ(gcd(1, 0), 1);
	EXPECT_EQ(gcd(3, 2), 1);
	EXPECT_EQ(gcd(6, 2), 2);
}

int main () {
	int a, b, n;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (gcd(max(a, b), min(a, b)) == 1) {
			cout << "Finite" << endl;
		}
		else {
			cout << "Infinite" << endl;
		}
	}
	return 0;
}