void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), done(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--; 
    }

    for (int day = 0; day < N; day++) {
        int task = A[day];
        done[task] = 1; 

        if ((task - K - 1 >= 0 && done[task - K - 1]) ||
            (task + K + 1 < N && done[task + K + 1])) {
            cout << (day + 1) << endl;
            return;
        }
    }

    cout << "-1" << endl; 
}