// Activity Selection Problem
// Problem: Select the maximum number of activities that don't overlap.

// Greedy Strategy: Always pick the next activity that finishes the earliest.

// Used in: Scheduling, resource allocation.

// 💰 2. Fractional Knapsack Problem
// Problem: Maximize the value of items you can carry, but you're allowed to take fractions.

// Greedy Strategy: Take items in order of value/weight ratio.

// Note: Doesn’t work for 0/1 Knapsack.

// 📡 3. Huffman Coding
// Problem: Encode characters with minimum total bits used.

// Greedy Strategy: Always combine the two least frequent characters.

// Used in: Data compression.

// 💡 4. Kruskal’s Algorithm (for MST)
// Problem: Find Minimum Spanning Tree of a graph.

// Greedy Strategy: Add the smallest-weight edge that doesn’t form a cycle.

// Used in: Network design.

// 🔌 5. Prim’s Algorithm (for MST)
// Problem: Also finds Minimum Spanning Tree.

// Greedy Strategy: Add the smallest-weight edge connecting the tree to a new vertex.

// Used in: Similar to Kruskal’s.

// 🛣️ 6. Dijkstra’s Algorithm
// Problem: Find the shortest path from a source node to all other nodes in a graph.

// Greedy Strategy: Always pick the node with the smallest tentative distance.

// Used in: GPS, routing algorithms.

// 💵 7. Coin Change Problem (Greedy version)
// Problem: Find the minimum number of coins to make a given amount.

// Greedy Strategy: Always use the largest denomination coin.

// Note: Only works if the coin system is canonical (like Indian or US coins).

// 🧠 8. Job Sequencing with Deadlines
// Problem: Maximize profit by scheduling jobs before their deadlines.

// Greedy Strategy: Sort jobs by profit and schedule them in latest available time slots before their deadline.

// 🧭 9. Egyptian Fraction Representation
// Problem: Represent a fraction as a sum of distinct unit fractions.

// Greedy Strategy: Always subtract the largest possible unit fraction.



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
#include <map>
#include <numeric>
using namespace std;

//////////////////////////////////////////////////////////////////
// 1. Activity Selection Problem
//////////////////////////////////////////////////////////////////

bool activityComparator(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

void activitySelection() {
    vector<pair<int, int>> activities = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    sort(activities.begin(), activities.end(), activityComparator);
    int count = 1;
    int lastEnd = activities[0].second;
    for (int i = 1; i < activities.size(); ++i) {
        if (activities[i].first >= lastEnd) {
            count++;
            lastEnd = activities[i].second;
        }
    }
    cout << "Max activities selected: " << count << endl;
}

//////////////////////////////////////////////////////////////////
// 2. Fractional Knapsack Problem
//////////////////////////////////////////////////////////////////

struct Item {
    int weight, value;
};

bool ratioCompare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

void fractionalKnapsack() {
    int capacity = 50;
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    sort(items.begin(), items.end(), ratioCompare);
    double totalValue = 0.0;
    for (auto& item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += (double)item.value * capacity / item.weight;
            break;
        }
    }
    cout << "Max value in Knapsack: " << totalValue << endl;
}

//////////////////////////////////////////////////////////////////
// 3. Huffman Coding
//////////////////////////////////////////////////////////////////

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

void printHuffman(HuffmanNode* root, string s) {
    if (!root) return;
    if (root->ch != '#') cout << root->ch << ": " << s << endl;
    printHuffman(root->left, s + "0");
    printHuffman(root->right, s + "1");
}

void huffmanCoding() {
    vector<pair<char, int>> freq = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& p : freq) {
        pq.push(new HuffmanNode(p.first, p.second));
    }
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* merged = new HuffmanNode('#', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    HuffmanNode* root = pq.top();
    printHuffman(root, "");
}

//////////////////////////////////////////////////////////////////
// 4. Kruskal's MST
//////////////////////////////////////////////////////////////////

struct Edge {
    int u, v, wt;
};

bool edgeCompare(Edge a, Edge b) {
    return a.wt < b.wt;
}

int find(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u], parent);
}

void kruskalMST() {
    int n = 4;
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    sort(edges.begin(), edges.end(), edgeCompare);
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) parent[i] = i;
    int mstCost = 0;
    for (auto& e : edges) {
        int pu = find(e.u, parent);
        int pv = find(e.v, parent);
        if (pu != pv) {
            mstCost += e.wt;
            parent[pu] = pv;
        }
    }
    cout << "Cost of MST using Kruskal: " << mstCost << endl;
}

//////////////////////////////////////////////////////////////////
// 5. Prim’s MST
//////////////////////////////////////////////////////////////////

void primMST() {
    int V = 5;
    vector<pair<int, int>> adj[5] = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}},
        {{1, 5}, {2, 7}}
    };
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> inMST(V, false);
    key[0] = 0;
    for (int count = 0; count < V; ++count) {
        int u = -1;
        for (int i = 0; i < V; ++i)
            if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
        inMST[u] = true;
        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }
    int total = accumulate(key.begin(), key.end(), 0);
    cout << "Cost of MST using Prim: " << total << endl;
}

//////////////////////////////////////////////////////////////////
// 6. Dijkstra's Algorithm
//////////////////////////////////////////////////////////////////

void dijkstra() {
    int V = 5;
    vector<pair<int, int>> graph[5] = {
        {{1, 10}, {4, 5}},
        {{2, 1}, {4, 2}},
        {{3, 4}},
        {{2, 6}, {0, 7}},
        {{1, 3}, {2, 9}, {3, 2}}
    };
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    set<pair<int, int>> pq;
    pq.insert({0, 0});
    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        for (auto& [v, wt] : graph[u]) {
            if (dist[u] + wt < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + wt;
                pq.insert({dist[v], v});
            }
        }
    }
    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; ++i) cout << i << ": " << dist[i] << endl;
}

//////////////////////////////////////////////////////////////////
// 7. Job Sequencing Problem
//////////////////////////////////////////////////////////////////

struct Job {
    int id, deadline, profit;
};

bool jobCompare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing() {
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    sort(jobs.begin(), jobs.end(), jobCompare);
    int maxDeadline = 0;
    for (auto& job : jobs) maxDeadline = max(maxDeadline, job.deadline);
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;
    for (auto& job : jobs) {
        for (int j = job.deadline; j > 0; --j) {
            if (slot[j] == -1) {
                slot[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }
    cout << "Total Profit from jobs: " << totalProfit << endl;
}

//////////////////////////////////////////////////////////////////
// 8. Greedy Coin Change
//////////////////////////////////////////////////////////////////

void coinChangeGreedy() {
    vector<int> coins = {25, 10, 5, 1};
    int amount = 63;
    int count = 0;
    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            count++;
        }
    }
    cout << "Minimum coins (Greedy): " << count << endl;
}

//////////////////////////////////////////////////////////////////
// 9. Egyptian Fraction Representation
//////////////////////////////////////////////////////////////////

void egyptianFraction(int num, int den) {
    cout << num << "/" << den << " = ";
    while (num != 0) {
        int x = (den + num - 1) / num;
        cout << "1/" << x;
        num = num * x - den;
        den *= x;
        if (num != 0) cout << " + ";
    }
    cout << endl;
}

//////////////////////////////////////////////////////////////////
// MAIN FUNCTION
//////////////////////////////////////////////////////////////////

int main() {
    cout << "\n--- Activity Selection ---\n";
    activitySelection();

    cout << "\n--- Fractional Knapsack ---\n";
    fractionalKnapsack();

    cout << "\n--- Huffman Coding ---\n";
    huffmanCoding();

    cout << "\n--- Kruskal's MST ---\n";
    kruskalMST();

    cout << "\n--- Prim's MST ---\n";
    primMST();

    cout << "\n--- Dijkstra's Algorithm ---\n";
    dijkstra();

    cout << "\n--- Job Sequencing ---\n";
    jobSequencing();

    cout << "\n--- Greedy Coin Change ---\n";
    coinChangeGreedy();

    cout << "\n--- Egyptian Fraction ---\n";
    egyptianFraction(6, 14);  // Example: 6/14 = 3/7

    return 0;
}
