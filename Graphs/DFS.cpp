#include <iostream>
#include <vector>
using namespace std;

enum Color {Black,White,Gray};

class Graph {
	int n;
	vector<int> *g;
	Color *colors;
	int *d;
	int *f;
	int *p;
	int time;
public:
	Graph(int n) {
		this->n = n;
		this->g = new vector<int>[n + 1];
		this->colors = new Color[n + 1];
		this->d = new int[n + 1];
		this->f = new int[n + 1];
		this->p = new int[n + 1];
	}
	void AddEdge(int u, int v) {
		g[u].push_back(v);
	}
	void DFS(){
		for (int i = 1; i <= n; i++) {
			colors[i] = White;
			p[i] = -1;
		}
		time = 0;
		for (int i = 1; i <= n; i++) {
			if (colors[i] == White) {
				DFS_VISIT(i);
			}
		}
	}
	void DFS_VISIT(int u) {
		
		time++;
		colors[u] = Gray;
		d[u] = time;
		for (int v : g[u]){
			if (colors[v] == White) {
				p[v] = u;
				DFS_VISIT(v);
			}
		}
		time++;
		colors[u] = Black;
		f[u] = time;
	}
	void Results(){
		for (int i = 1; i <= n; i++) {
			cout << "Vertex " << i << " d " << d[i] << " f " << f[i] << endl;
		}
	}
};

int main() {
	Graph g(6);
	g.AddEdge(1, 3);
	g.AddEdge(1, 2);
	g.AddEdge(4, 2);
	g.AddEdge(2, 3);
	g.AddEdge(5,4);
	g.AddEdge(5, 6);
	g.AddEdge(6, 6);
	g.DFS();
}