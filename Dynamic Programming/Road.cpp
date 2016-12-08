#include <iostream>
using namespace std;
int main() {
	int n = 15;
	int Road[100];
	Road[1] = 1;
	Road[2] = 2;
	for (int i = 3; i <= n; i++) {
		Road[i] = Road[i - 1] + Road[i - 2];
	}
	cout << Road[n] << endl;
}