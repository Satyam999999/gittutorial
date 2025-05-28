

#include <bits/stdc++.h>
using namespace std;

struct Book {
    int price, pages;
    double ratio;
};

bool cmp(Book &a, Book &b) {
    return a.ratio > b.ratio; 
}

void maxPagesGreedy(int n, int X, vector<int>& bookprice, vector<int>& pages) {
    vector<Book> books(n);
    
    for (int i = 0; i < n; i++) {
        books[i] = {bookprice[i], pages[i], (double)pages[i] / bookprice[i]};
    }
    
    sort(books.begin(), books.end(), cmp);
    
    int totalPages = 0, totalBooks = 0, cost = 0;
    
    for (auto &book : books) {
        if (cost + book.price <= X) {
            cost += book.price;
            totalPages += book.pages;
            totalBooks++;
        }
    }

    cout << "Max Books = " << totalBooks << endl;
    cout << "Max cost of expenditure = " << cost << endl;
    cout << "Max Pages = " << totalPages << endl;
}

int main() {
    int n = 4, X = 10;
    vector<int> bookprice = {4, 8, 5, 3};
    vector<int> pages = {5, 12, 8, 1};

    maxPagesGreedy(n, X, bookprice, pages);
    return 0;
}
