#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
};

vector<int> parent(100);

void DSU(int n) {
    
    for (int i = 0; i <= n; i++) parent[i] = i;
}

int find(int x) {
    return (parent[x] == x) ? x : (parent[x] = find(parent[x])); 
}

bool unite(int x, int y) {
    int rootX = find(x);
    int  rootY = find(y);
    if (rootX == rootY) return false; 
    parent[rootY] = rootX; 
    return true;
}
bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(),compare);

    DSU(n);  
    int totalCost = 0, edgesUsed = 0;

    for (const auto& edge : edges) {
        if (unite(edge.u, edge.v)) { 
            totalCost += edge.cost;
            if (++edgesUsed == n - 1) return totalCost;  
        }
    }
    return -1;  
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;

    int result = kruskal(n, edges);
if(result==-1) cout<<"IMPOSSIBLE"<<endl;
else cout<<result<<endl;

    return 0;
}
