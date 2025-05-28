#include <iostream>
using namespace std;

bool check(string X, string Y, string Z) {
    int i = 0, j = 0, k = 0;
    int n = X.size(), m = Y.size(), z = Z.size();

    if (z != n + m) return false;

    while (k < z) {
        if (i < n && Z[k] == X[i]) {
            i++;
        } else if (j < m && Z[k] == Y[j]) {
            j++;
        } else {
            return false;
        }
        k++;
    }

    return (i == n && j == m);
}

int main() {
    string X,Y,Z;
    cin>>X>>Y>>Z;
    if (check(X, Y, Z))
        cout << "Valid Shuffle\n";
    else
        cout << "Invalid Shuffle\n";

    return 0;
}