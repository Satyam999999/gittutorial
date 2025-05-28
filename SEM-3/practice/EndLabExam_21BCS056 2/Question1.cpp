#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void pour(int a, int b, vector<int> &capacity, vector<int> &currentLevel) {
    if(currentLevel[a] > (capacity[b]-currentLevel[b])) {
        currentLevel[a] -= (capacity[b]-currentLevel[b]);
        currentLevel[b] = capacity[b];
    } else {
        currentLevel[b] += currentLevel[a];
        currentLevel[a] = 0;
    }
}

void helper(vector<int> &capacity, vector<int> currentLevel, vector<pair<int,int>> seq, set<vector<int>> &visited, bool &done) {
    if(done) return;

    if(currentLevel[1] == 2 || currentLevel[2] == 2) {
        cout << "Solution:\n";
        for(auto v : seq){
            cout << "Pour " << v.first << " -> " << v.second << endl;
        }
        done = true;
        return;
    }

    if(visited.count(currentLevel)) return;
    visited.insert(currentLevel);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i != j && currentLevel[i] > 0 && currentLevel[j] < capacity[j]) {
                vector<int> nextLevel = currentLevel;
                pour(i, j, capacity, nextLevel);
                vector<pair<int,int>> newSeq = seq;
                newSeq.push_back({i, j});
                helper(capacity, nextLevel, newSeq, visited, done);
            }
        }
    }
}

int main() {
    vector<int> capacity = {10, 7, 4};
    vector<int> currentLevel = {0, 7, 4};

    set<vector<int>> visited;
    vector<pair<int,int>> seq;
    bool done = false;

    helper(capacity, currentLevel, seq, visited, done);
}
