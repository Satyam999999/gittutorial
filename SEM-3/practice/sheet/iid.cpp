#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <cstring>
using namespace std;

const int INF = 1e9;
const int MAX = 300;

int capacity[MAX][MAX];
vector<int> adj[MAX];
int parent[MAX];

// BFS for finding augmenting path
bool bfs(int s, int t) {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(s);
    parent[s] = -2;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                if (next == t) return true;
                q.push(next);
            }
        }
    }
    return false;
}

// Edmonds-Karp Max Flow
int maxflow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        int path_flow = INF;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            path_flow = min(path_flow, capacity[prev][cur]);
            cur = prev;
        }
        cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= path_flow;
            capacity[cur][prev] += path_flow;
            cur = prev;
        }
        flow += path_flow;
    }
    return flow;
}

// Graph node mapping helpers
int in(int x) { return 2 * x; }
int out(int x) { return 2 * x + 1; }

int main() {
    map<char, int> city_id;
    string cities = "ABCDEFGHIJKLMN";
    for (int i = 0; i < cities.size(); ++i)
        city_id[cities[i]] = i;

    // Add split vertices with capacity 1 between in and out
    for (int i = 0; i < cities.size(); ++i) {
        int u = i;
        int u_in = in(u), u_out = out(u);
        adj[u_in].push_back(u_out);
        capacity[u_in][u_out] = 1;
    }

    // Edges from the graph
    vector<pair<char, char>> edges = {
        {'A','B'}, {'A','C'}, {'A','D'}, {'A','E'},
        {'B','F'}, {'C','F'}, {'C','G'},
        {'D','H'}, {'E','H'},
        {'F','I'}, {'G','I'},
        {'H','I'},
        {'I','J'}, {'I','K'},
        {'J','N'}, {'K','L'}, {'L','N'},
        {'H','M'}, {'M','N'}
    };

    for (auto [u_char, v_char] : edges) {
        int u = city_id[u_char], v = city_id[v_char];
        int u_out = out(u), v_in = in(v);
        adj[u_out].push_back(v_in);
        capacity[u_out][v_in] = INF;
    }

    int source = out(city_id['A']);
    int sink = in(city_id['N']);
    int result = maxflow(source, sink);
    cout << "Minimum number of checkposts needed: " << result << endl;

    return 0;
}
