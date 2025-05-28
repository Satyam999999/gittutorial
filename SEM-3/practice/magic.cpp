void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) cin >> intervals[i].first;  
    for (int i = 0; i < n; i++) cin >> intervals[i].second; 
    sort(intervals.begin(), intervals.end());

    int shows = 0;
    int last_end = -1; 

    for (int i = 0; i < n; i++) {
        int start = intervals[i].first;
        int end = intervals[i].second;

        if (start > last_end) { 
            shows++;
            last_end = end;
        } else {
            last_end = max(last_end, end);
        }
    }

    cout << shows << endl;
}
