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