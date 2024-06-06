#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



struct Muchie{
    int x, y, cost;
};

struct Graph{
    int nr_noduri, nr_muchii;
    vector<Muchie> muchii;
};

Graph citire_input() {

    ifstream in("input_kruskal.txt");
    Graph graph;

    in >> graph.nr_noduri >> graph.nr_muchii;

    for (int i = 0; i < graph.nr_muchii; i++) {
            Muchie muchie;
            in >> muchie.x >> muchie.y >> muchie.cost;
            graph.muchii.push_back(muchie);
        
    } 

    in.close();

    return graph;
}

//Functia gaseste parintele nodului i
int findParent(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = findParent(parent, parent[i]);
    }
    return parent[i];
}

void reuniune(vector<int>& parent, vector<int>& rang, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rang[rootX] < rang[rootY]) {
        parent[rootX] = rootY;
    } else if (rang[rootX] > rang[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rang[rootX]++;
    }
}

vector<Muchie> kruskal(Graph& graph) {

    vector<Muchie> rez;
    
    //Sortare muchii crescator dupa cost
    sort(graph.muchii.begin(), graph.muchii.end(), [](Muchie a, Muchie b) {
        return a.cost < b.cost;
    });

    vector<int> parent(graph.nr_noduri + 1);
    vector<int> rang(graph.nr_noduri + 1, 0);

    //Initializare vector de parinti
    for (int i = 1; i <= graph.nr_noduri; i++) {
        parent[i] = i;
    }

    for (auto muchie : graph.muchii) {
        int x = findParent(parent, muchie.x);
        int y = findParent(parent, muchie.y);

        if (x != y) {
            rez.push_back(muchie);
            reuniune(parent, rang, x, y);
        }
    }

    return rez;
}

int main(){

    Graph graph;
    graph = citire_input();

    int cost = 0;
    vector<Muchie> rez = kruskal(graph);

    for (auto m : rez){
        cost += m.cost;

        cout<< m.x << " " << m.y << endl;
    }
    
    cout<<cost;

    return 0;
}