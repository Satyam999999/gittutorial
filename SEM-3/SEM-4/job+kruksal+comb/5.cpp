#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;
    if (root->ch != '*') cout << root->ch << ": " << str << endl;
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    vector<pair<char, int>> data = {{'Q', 3}, {'P', 23}, {'T', 30}, {'a', 12}, {'d', 18}};
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    for (auto d : data) pq.push(new Node(d.first, d.second));

    while (pq.size() > 1) {
        Node *l = pq.top();
         pq.pop();
        Node *r = pq.top(); 
        pq.pop();
        Node *merged = new Node('*', l->freq + r->freq);
        merged->left = l;
        merged->right = r;
        pq.push(merged);
    }
    printCodes(pq.top(), "");
    return 0;
}