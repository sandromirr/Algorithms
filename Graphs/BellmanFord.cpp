#include <iostream>
#include <vector>
using namespace std;

class Graph {
	int n;
	vector< pair<int, pair<int,int>>> g;
	int s;
	int *d;
	int *p;
public:
	Graph(int n) {
		this->n = n;
		this->d = new int[n + 1];
		this->p = new int[n + 1];
	}
	void AddEdge(int u,int v,int w) {
		g.push_back(make_pair(u, make_pair(v, w)));
	}
	void Intialize(int s) {
		this->s = s;
		for (int i = 1; i <= n; i++) {
			d[i] = INT_MAX;
			p[i] = -1;
		}
		d[s] = 0;
		p[s] = s;
	}
	bool BelmanFord(int s) {
		Intialize(s);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g.size(); j++) {
				int u = g[j].first;
				int v = g[j].second.first;
				int w = g[j].second.second;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					p[u] = v;
				}
			}
		}
		for (int i = 0; i < g.size(); i++) {
			int u = g[i].first;
			int v = g[i].second.first;
			int w = g[i].second.second;
			if (d[v] > d[u] + w) {
				return false;
			}
		}
		return true;	
	}
	void Results() {
		for (int i = 1; i <= n; i++) {
			cout << s << "->" << i << " " << d[i] << endl;
		}
	}
};

int main() {
	Graph g(5);
	// none negative cycle graph
	g.AddEdge(1, 2, 6);
	g.AddEdge(1, 3, 7);
	g.AddEdge(2, 3, 8);

	g.AddEdge(3, 4, -3);
	g.AddEdge(3, 5, 9);
	g.AddEdge(5, 4, 7);
	
	g.AddEdge(2, 4, 5);
	g.AddEdge(4, 2, - 2);
	g.AddEdge(5, 1, 2);

	g.AddEdge(2, 5, -4);

	if (g.BelmanFord(1)) {
		cout << "No negative cycle" << endl;
	}
	else {
		cout << "Yes negative cycle" << endl;
	}
	g.Results();
}