#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct book{
    int ratio;
};
bool cmp(const book &a,const book &b){
    return a.ratio<b.ratio;
}
int main(){
    vector<book> books(6);
      for(int i=0;i<6;i++) cin>>books[i].ratio;

  sort(books.begin(),books.end(),cmp);
  for(int i=0;i<6;i++) cout<<books[i].ratio<<endl;
}
