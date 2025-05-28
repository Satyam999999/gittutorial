#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    cout << maxEarningsGreedy(projects) << endl;
    return 0;
}
