

int countWaysBacktrack(int n) {
    if (n == 0) return 1;  
    if (n < 0) return 0;  
    
    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways = (ways + countWaysBacktrack(n - i)) % MOD;
    }
    return ways;
}


struct Project {
    int start, end, reward;
};

bool compare(Project &a, Project &b) {
    return a.end < b.end;
}

int maxEarningsGreedy(vector<Project>& projects) {
    sort(projects.begin(), projects.end(), compare);

    int maxEarnings = 0, lastEndTime = 0;

    for (const auto& project : projects) {
        if (project.start >= lastEndTime) { 
            maxEarnings += project.reward; 
            lastEndTime = project.end; 
        }
    }

    return maxEarnings;
}



struct Edge {
    int u, v, cost;
};

class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        parent[rootY] = rootX;
        return true;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
    });

    DSU dsu(n);
    int totalCost = 0, edgesUsed = 0;

    for (auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            totalCost += edge.cost;
            if (++edgesUsed == n - 1) return totalCost; 
        }
    }
    return -1;  
}
struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int maxActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);
    int count = 1, lastEnd = activities[0].end;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    return count;
}
