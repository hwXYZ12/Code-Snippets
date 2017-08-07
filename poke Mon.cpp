# solves this problem https://i.gyazo.com/2ed2c9354e4798d5b7f8f7db27b14ea8.png

#include <iostream>

int main() {

	using namespace std;

	int n, m, y, pokes;
	cin >> n >> m >> y;
	if (n % (2 * m) == 0) {
		pokes += n / (2 * m);
		n /= 2;
		if (y != 0) {
			n /= y;
		}
	}
	pokes += n / m;
	n %= m;
	cout << n << endl;
	cout << pokes << endl;
}
	