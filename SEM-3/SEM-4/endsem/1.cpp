#include <iostream>
using namespace std;
struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

vector<int> parent;

int find(int x) {
    if (parent[x] != x) 
        return parent[x] = find(parent[x]); 
    return x;
}

void unionSet(int x, int y) {
    parent[find(x)] = find(y); 
}

int kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compare); 

    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    int cost = 0, cnt = 0;
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) { 
            unionSet(e.u, e.v);
            cost += e.weight;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return (cnt == n - 1) ? cost : -1; 
}
int main(){
    int n;
    cin>>n;
 vector<Edge> edges(n);
}