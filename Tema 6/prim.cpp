#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

struct Muchie {
    int x, y, cost;
    Muchie(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost){}
};

struct Graph {
    int nr_noduri, nr_muchii;
    unordered_map<int, vector<pair<int, int>>> adiacenta;

    Graph(int n = 0, int m = 0) : nr_noduri(n), nr_muchii(m) {}
};

Graph citire_input() {
    ifstream in("input_kruskal.txt");
    Graph graph;

    in >> graph.nr_noduri >> graph.nr_muchii;

    for (int i = 0; i < graph.nr_muchii; i++) {
        int x, y, cost;
        in >> x >> y >> cost;
        graph.adiacenta[x].push_back({y, cost});
        graph.adiacenta[y].push_back({x, cost});
    }

    in.close();
    return graph;
}

vector<Muchie> prim(Graph& graph) {
    vector<int> cost(graph.nr_noduri + 1, INT_MAX);
    vector<int> parent(graph.nr_noduri + 1, -1);
    vector<bool> inMST(graph.nr_noduri + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startNode = 1;
    pq.push({0, startNode});
    cost[startNode] = 0;

    while (!pq.empty()) {
        int nod = pq.top().second;
        pq.pop();

        if (inMST[nod]) continue;

        inMST[nod] = true;

        for (auto vecin : graph.adiacenta[nod]) {
            int y = vecin.first;
            int cost_value = vecin.second;

            if (!inMST[y] && cost_value < cost[y]) {
                cost[y] = cost_value;
                pq.push({cost[y], y});
                parent[y] = nod;
            }
        }
    }

    vector<Muchie> rezultat;
    for (int i = 2; i <= graph.nr_noduri; ++i) {
        if (parent[i] != -1) {
            rezultat.push_back(Muchie(parent[i], i, cost[i]));
        }
    }

    return rezultat;
}


int main() {
    Graph graph = citire_input();

    vector<Muchie> rez = prim(graph);
    int costTotal = 0;

    for (auto muchie : rez) {
        costTotal += muchie.cost;
        cout << muchie.x << " " << muchie.y << " " << muchie.cost << endl;
    }

    cout << "Cost total: " << costTotal << endl;

    return 0;
}
