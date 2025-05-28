#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
void sorts(int a[][3],int m){
    int maxi;
    for(int i=0;i<m;i++) maxi=max(maxi,a[i][2]);
    int hash[maxi];
      for(int i=0;i<maxi;i++) hash[i]=0;
    for(int i=0;i<m;i++) hash[a[i][2]]++;
    int k=0;
     for(int i=0;i<maxi;i++) {
        if(hash[i]){
a[k][2]=i;
k++;
hash[i]--;
        }
     }

}
int parent[1000];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unionSet(int x, int y) {
    parent[find(x)] = find(y);
}

int mincost(int connections[][3], int m, int n) {
    for (int i = 0; i <= n; i++) parent[i] = i;
    
    sorts(connections,3);
    
    int cost = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int u = connections[i][0], v = connections[i][1], w = connections[i][2];
        if (find(u) != find(v)) {
            unionSet(u, v);
            cost += w;
            cnt++;
        }
    }
    return (cnt == n - 1) ? cost : -1;
}
int main(){
    int connections[][3]={{1,2,5},{1,3,6},{2,3,1}};
    int n=3;
    int m=3;
cout<<mincost(connections,n,m);


}