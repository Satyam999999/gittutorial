#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bitset>
using namespace std;

vector<string> generateCodewords(int k) {
    vector<string> codes;
    int total = 1 << k;
    for (int i = 0; i < total; i++)
        codes.push_back(bitset<16>(i).to_string().substr(16 - k)); // limit to k bits
    sort(codes.begin(), codes.end(), [](string &a, string &b) {
        return count(a.begin(), a.end(), '1') < count(b.begin(), b.end(), '1');
    });
    return codes;
}

int minSetBits(string s, int k) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    vector<pair<int, char>> freqList;
    for (auto &p : freq)
        freqList.push_back({-p.second, p.first}); // sort descending

    sort(freqList.begin(), freqList.end());

    vector<string> codes = generateCodewords(k);
    int totalBits = 0;
    for (int i = 0; i < freqList.size(); i++) {
        int setBits = count(codes[i].begin(), codes[i].end(), '1');
        totalBits += (-freqList[i].first) * setBits;
    }

    return totalBits;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << minSetBits(s, k) << endl;
    }
    return 0;
}
