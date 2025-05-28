// 0/1 Knapsack Problem	Given a set of items, each with a weight and a value, determine the maximum value that can be obtained by selecting items such that their total weight is less than or equal to a given limit.
// Traveling Salesman Problem (TSP)	Given a set of cities and the distances between each pair of cities, determine the shortest possible route that visits each city once and returns to the origin city.
// Integer Linear Programming (ILP)	Solve optimization problems where the objective function and constraints are linear, but the variables must take integer values.
// Job Scheduling Problem	Assign jobs to machines such that the total completion time is minimized, and each machine can process only one job at a time.
// Graph Coloring Problem	Assign colors to the vertices of a graph such that no two adjacent vertices share the same color, with the goal of minimizing the number of colors used.
// Bin Packing Problem	Pack a set of items of varying sizes into the minimum number of bins, where each bin has a fixed capacity.
// Subset Sum Problem	Given a set of integers, determine if there exists a subset whose sum is equal to a given number.
// Traveling Salesman Problem (with Time Windows)	TSP with additional constraints on when a city can be visited, typically solving for the shortest route while respecting time windows.
// Resource Constrained Project Scheduling Problem (RCPSP)	Schedule tasks of a project subject to constraints on the resources available, with the goal of minimizing project duration.
// Minimum Cost Hamiltonian Path	Find the minimum cost path in a graph that visits every vertex exactly once.
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

///////////////////////////////////////////////////////////////
// 1. 0/1 Knapsack Problem
///////////////////////////////////////////////////////////////
// Problem: Given a set of items, each with a weight and a value, determine the maximum value that can be obtained 
// by selecting items such that their total weight is less than or equal to a given limit.

struct Item {
    int weight;
    int value;
};

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

bool compare(Node a, Node b) {
    return a.bound > b.bound;
}

float bound(Node& u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0;
    int profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    if (j < n) {
        profitBound += (W - totalWeight) * items[j].value / float(items[j].weight);
    }

    return profitBound;
}

int knapsackBranchAndBound(vector<Item>& items, int W, int n) {
    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;

    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(compare);
    pq.push(u);

    int maxProfit = 0;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.level == n - 1) continue;

        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit) pq.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit) pq.push(v);
    }

    return maxProfit;
}

///////////////////////////////////////////////////////////////
// 2. Traveling Salesman Problem (TSP)
///////////////////////////////////////////////////////////////
// Problem: Given a set of cities and the distances between each pair of cities, determine the shortest possible route 
// that visits each city once and returns to the origin city.

struct TSPNode {
    vector<int> path;
    int cost;
};

int tspBranchAndBound(int graph[][4], int n) {
    int minCost = INT_MAX;
    vector<int> visited(n, false);
    visited[0] = true;
    vector<int> path;
    path.push_back(0);

    priority_queue<pair<int, TSPNode>> pq;

    pq.push({0, {path, 0}});

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int cost = current.first;
        TSPNode node = current.second;

        if (node.path.size() == n) {
            minCost = min(minCost, cost + graph[node.path.back()][0]);
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> newPath = node.path;
                newPath.push_back(i);
                visited[i] = true;
                pq.push({cost + graph[node.path.back()][i], {newPath, cost + graph[node.path.back()][i]}});
                visited[i] = false;
            }
        }
    }

    return minCost;
}

///////////////////////////////////////////////////////////////
// 3. Bin Packing Problem
///////////////////////////////////////////////////////////////
// Problem: Pack a set of items of varying sizes into the minimum number of bins, where each bin has a fixed capacity.

int binPackingBranchAndBound(vector<int>& items, int binCapacity) {
    sort(items.begin(), items.end(), greater<int>());
    int n = items.size();
    int minBins = n;

    function<void(int, vector<int>&)> branchAndBound = [&](int level, vector<int>& bins) {
        if (level == n) {
            int count = 0;
            for (int bin : bins) {
                if (bin > 0) count++;
            }
            minBins = min(minBins, count);
            return;
        }

        for (int i = 0; i < minBins; i++) {
            if (bins[i] + items[level] <= binCapacity) {
                bins[i] += items[level];
                branchAndBound(level + 1, bins);
                bins[i] -= items[level];
            }
        }

        bins.push_back(items[level]);
        branchAndBound(level + 1, bins);
        bins.pop_back();
    };

    vector<int> bins;
    branchAndBound(0, bins);
    return minBins;
}

///////////////////////////////////////////////////////////////
// 4. Job Scheduling Problem
///////////////////////////////////////////////////////////////
// Problem: Assign jobs to machines such that the total completion time is minimized.

struct Job {
    int start;
    int finish;
};

bool jobCompare(Job a, Job b) {
    return a.finish < b.finish;
}

int jobSchedulingBranchAndBound(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), jobCompare);

    vector<int> dp(jobs.size(), 0);
    dp[0] = 1;

    for (int i = 1; i < jobs.size(); i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < i; j++) {
            if (jobs[j].finish <= jobs[i].start) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp.back();
}

///////////////////////////////////////////////////////////////
// 5. Graph Coloring Problem
///////////////////////////////////////////////////////////////
// Problem: Assign colors to the vertices of a graph such that no two adjacent vertices share the same color, 
// with the goal of minimizing the number of colors used.

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, vector<int>& color, int m, int v) {
    if (v == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, color, m, v + 1)) return true;
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoringBranchAndBound(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0);
    return graphColoringUtil(graph, color, m, 0);
}

///////////////////////////////////////////////////////////////
// MAIN FUNCTION
///////////////////////////////////////////////////////////////

int main() {
    // 0/1 Knapsack Example
    vector<Item> items = {{2, 3}, {3, 4}, {4, 5}, {5, 6}};
    int W = 5;
    cout << "Maximum Value in Knapsack: " << knapsackBranchAndBound(items, W, items.size()) << endl;

    // TSP Example (with 4 cities)
    int graph[4][4] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};
    cout << "Minimum TSP Cost: " << tspBranchAndBound(graph, 4) << endl;

    // Bin Packing Example
    vector<int> items2 = {10, 20, 30, 40, 50};
    int binCapacity = 60;
    cout << "Minimum Number of Bins: " << binPackingBranchAndBound(items2, binCapacity) << endl;

    // Job Scheduling Example
    vector<Job> jobs = {{0, 3}, {5, 9}, {3, 5}, {8, 10}};
    cout << "Maximum Number of Jobs: " << jobSchedulingBranchAndBound(jobs) << endl;

    // Graph Coloring Example
    vector<vector<int>> graph = {{0, 1, 1, 0},
                                  {1, 0, 1, 1},
                                  {1, 1, 0, 1},
                                  {0, 1, 1, 0}};
    int m = 3;  // 3 colors
    cout << "Is Graph Colorable with " << m << " colors: " << (graphColoringBranchAndBound(graph, m) ? "Yes" : "No") << endl;

    return 0;
}
