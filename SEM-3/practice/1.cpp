#include <iostream>
#include <vector>

using namespace std;

void countWaysBacktrack(int n, vector<int>& path, int& count) {
    if (n == 0) { 
        count++;  
        for (int num : path) cout << num << " ";
        cout << endl;  
        return;
    }
    if (n < 0) return;  
    
    for (int i = 1; i <= 6; i++) {
        path.push_back(i); 
        countWaysBacktrack(n - i, path, count);
        path.pop_back();  
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> path;
    int count = 0;
    countWaysBacktrack(n, path, count);
    cout << "Total Ways: " << count << endl;
    return 0;
}
// #include <iostream>

// using namespace std;


// int countWaysBacktrack(int n) {
//     if (n == 0) return 1;
//     if (n < 0) return 0;   
    
//     int ways = 0;
//     for (int i = 1; i <= 6; i++) {
//         ways = (ways + countWaysBacktrack(n - i)) % MOD;
//     }
//     return ways;
// }

// int main() {
//     int n;
//     cin >> n;
//     cout << countWaysBacktrack(n) << endl;
//     return 0;
// }
