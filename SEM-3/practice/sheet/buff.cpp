#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Helper to count 1s in binary string
int countOnes(const string& s) {
    return count(s.begin(), s.end(), '1');
}

// Generate all binary strings of length k
void generateCodewords(int k, vector<string>& codewords) {
    int total = 1 << k;
    for (int i = 0; i < total; ++i) {
        string code = "";
        for (int j = k - 1; j >= 0; --j) {
            code += ((i >> j) & 1) ? '1' : '0';
        }
        codewords.push_back(code);
    }
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    // Generate codewords
    vector<string> codewords;
    generateCodewords(k, codewords);

    // Sort codewords by number of 1s
    sort(codewords.begin(), codewords.end(), [](string& a, string& b) {
        int countA = countOnes(a);
        int countB = countOnes(b);
        return countA < countB;
    });

    // Sort characters by frequency
    vector<pair<char, int>> freqList(freq.begin(), freq.end());
    sort(freqList.begin(), freqList.end(), [](pair<char,int>& a, pair<char,int>& b) {
        return a.second > b.second;
    });

    // Assign codewords
    unordered_map<char, string> encoding;
    for (int i = 0; i < freqList.size(); ++i) {
        encoding[freqList[i].first] = codewords[i];
    }

    // Encode string and count total 1s
    int totalSetBits = 0;
    for (char c : s) {
        totalSetBits += countOnes(encoding[c]);
    }

    cout << "Total number of set bits: " << totalSetBits << endl;
    cout << "Encoding Table:\n";
    for (auto& p : encoding) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
