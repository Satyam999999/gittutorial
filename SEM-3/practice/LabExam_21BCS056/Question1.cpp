#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
void shortestPath(int src, vector<vector<pair<int, int>>> adj, int n, vector<int> &dist){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist.assign(n, INF);

    pq.push({0, src});
    dist[src] = 0;
    
    //O(ElogE)
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
 
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }        
    }
}


int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    //O(m)
    int u,v,w;
    for(int i = 0;i<m;i++){
        cin >> u >> v >> w;
        if(w < 0){
            w = INF;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist;

    shortestPath(0,adj,n,dist);

    cout << "n" << " " << "d" << endl;
    for(int i = 0;i<n;i++){
        cout << i << " " << dist[i] << endl;
    }
}