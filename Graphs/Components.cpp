#include <iostream>
#include <vector>
using namespace std;

enum Color{Black,White,Gray};

class Graph {
	int n;
	vector<int> *g , *gr;
	vector<int> components , item;
	int *d;
	int *f;
	int *p;
	Color *colors;
	int time = 0;
	bool *used;
public:
	Graph(int n) {
		this->n = n;
		g = new vector<int>[n + 1];
		gr = new vector<int>[n + 1];
		d = new int[n + 1];
		f = new int[n + 1];
		p = new int[n + 1];
		colors = new Color[n + 1];
		used = new bool[n + 1];
	}

	void AddEdge(int u, int v) {
		g[u].push_back(v);
		gr[v].push_back(u);
	}

	void DFS() {
		for (int i = 1; i <= n; i++) {
			colors[i] = White;
		}
		for (int i = 1; i <= n; i++) {
			if (colors[i] == White) {
				DFS_VISIT(i);
			}
		}
	}

	void DFS_VISIT(int u) {
		time++;
		d[u] = time;
		colors[u] = Gray;
		for (int v : g[u]) {
			if (colors[v] == White) {
				p[v] = u;
				DFS_VISIT(v);
			}
		}
		colors[u] = Black;
		time++;
		f[u] = time;
		components.push_back(u);
	}

	void Tree() {
		for (int i = components.size() - 1; i >= 0; i--) {
			cout << components[i] << " ";
 		}
	}

	void Components() {
		cout << "Components:" << endl;
		for (int i = 0; i <= n; i++) {
			used[i] = false;
		}
		for (int i = components.size() - 1; i >= 0; i--) {
			int v = components[i];
			if (!used[v]) {
				DFS2(v);
				for (auto i : item) {
					cout << i << " ";
				}
				cout << endl;
				item.clear();
			}
		}

	}

	void DFS2(int v) {
		used[v] = true;
		item.push_back(v);
		for (int u : gr[v]) {
			if (!used[u]) {
				DFS2(u);
			}
		}
	}
};

int main() {
	Graph g(8);

	g.AddEdge(1, 2);
	g.AddEdge(1, 6);

	g.AddEdge(2, 3);
	g.AddEdge(2, 6);
	
	g.AddEdge(3, 4);
	g.AddEdge(3, 7);

	g.AddEdge(5, 1);
	
	g.AddEdge(6,7);
	g.AddEdge(6, 5);
	
	g.AddEdge(7, 3);
	
	g.AddEdge(8, 7);

	g.DFS();
	g.Components();
}