#include <iostream>
using namespace std;

void Quick(int a[], int low, int high) {
	int i = low;
	int j = high;
	int pivot = a[(low + high) / 2];
	int tmp;
	while (i <= j) {
		while (a[i] > pivot) i++;
		while (a[j] < pivot) j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < high) {
		Quick(a, i, high);
	}
	if (low < j) {
		Quick(a, low, j);
	}
}

int main() {
	int n = 6;
	int a[6] = { -4,2,-11,-3,3,1 };
	Quick(a, 0, n - 1);
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}