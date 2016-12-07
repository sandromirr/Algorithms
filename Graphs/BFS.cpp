#include <iostream>
#include <queue>
#include <vector>
using namespace std;

enum Color { White, Gray , Black};

class Graph {
	int n;
	vector<int> *g;
	Color *color;
	int *d;
	int *p;
	queue<int> q;
	int s;
	vector<int> travel;
public:
	Graph(int n) {
		this->n = n;
		this->g = new vector<int>[n + 1];
		this->color = new Color[n + 1];
		this->d = new int[n + 1];
		this->p = new int[n + 1];
	}
	void Intialize(int s){
		for (int i = 1; i <= n; i++) {
			color[i] = White;
			d[i] = INT_MAX;
			p[i] = -1;
		}
		color[s] = Gray;
		d[s] = 0;
		p[s] = s;
	}
	void AddEdge(int u, int v){
		g[u].push_back(v);
	}
	void BFS(int s){
		this->s = s;
		Intialize(s);
		q.push(s);
		travel.push_back(s);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (auto v : g[u]){
				if (color[v] == White){
					color[v] = Gray;
					p[v] = u;
					d[v] = d[u] + 1;
					q.push(v);
					travel.push_back(v);
				}
			}
			color[u] = Black;
		}
	}
	void path(int v){
		if (s == v) {
			cout << v << " ";
			return;
		}
		if (p[v] == -1){
			cout << "No path" << endl;
			return;
		}
		path(p[v]);
		cout << v << " ";
	}
	void tree(){
		for (int i = 0; i < travel.size(); i++) {
			cout << travel[i] << " ";
		}
	}
};

int main() {
	Graph g(7);

	g.AddEdge(1, 1);

	g.AddEdge(1, 2);
	g.AddEdge(2, 1);

	g.AddEdge(1, 3);
	g.AddEdge(3, 1);

	g.AddEdge(1, 7);
	g.AddEdge(7,1);

	g.AddEdge(1, 5);
	g.AddEdge(5, 1);

	g.AddEdge(5, 4);
	g.AddEdge(4,5);

	g.AddEdge(5, 6);
	g.AddEdge(6, 5);

	g.AddEdge(4, 6);
	g.AddEdge(6, 4);

	g.BFS(1);

	cout << "Tree" << endl;
	g.tree();

	cout << "\nPath" << endl;
	g.path(6);

}