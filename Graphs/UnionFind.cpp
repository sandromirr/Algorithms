#include <iostream>

using namespace std;

class UnionFind {
	int n;
	int *id;
public:
	UnionFind(int n) {
		this->n = n;
		this->id = new int[n];
		for (int i = 0; i < n; i++) {
			this->id[i] = i;
		}
	}
	int root(int x) {
		while (x != id[x]) {
			x = id[x];
		}
		return x;
	}
	int find(int x){
		return id[x];
	}
	bool connected(int x, int y) {
		return id[x] == id[y];
	}
	void unite(int x,int y) {
		int i = root(x);
		int j = root(y);
		id[i] = j;
	}
};

int main() {
	UnionFind uf(10);
	cout << uf.connected(2, 3) << endl;
	cout << uf.find(4) << endl;
	uf.unite(3, 4);
	cout << uf.connected(3, 4) << endl;
	cout << uf.root(3) << " " << uf.root(4) << endl;
}