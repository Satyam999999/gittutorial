#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
      int n,m;
      cin>>n>>m;
        vector<pair<int,int>> router(n);
        vector<pair<int,int>> users(m);
for(int i=0;i<n;i++){
    int k,l;
    cin>>k>>l;
router[i] = make_pair(k,l);

}
for(int i=0;i<m;i++){
    int k,l;
    cin>>k>>l;
users[i] = make_pair(k,l);

}
float maxi=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        int x=router[i].first-users[j].first;
        int y=router[i].second-users[j].second;
        float dist = sqrt(pow(x,2)+pow(y,2));
        maxi=max(dist,maxi);
    }
}
cout<<maxi<<endl;
    }

