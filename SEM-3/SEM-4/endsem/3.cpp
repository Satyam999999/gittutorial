#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m; 
        vector<int> routerx(n);
                vector<int> routery(n);

        vector<int> usersx(m);
                vector<int> usersy(m);

for(int i=0;i<n;i++){
    int k,l;
    cin>>k>>l;
routerx[i] = k;
routery[i] =l;

}
for(int i=0;i<m;i++){
    int k,l;
    cin>>k>>l;
usersx[i]=k ;
usersy[i]=l ;

}
float maxi=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        int x=routerx[i] - usersx[j];
        int y=routery[i] - usersy[j];
        float dist = sqrt(pow(x,2)+pow(y,2));
        maxi=max(dist,maxi);
    }
}
cout<<maxi<<endl;
    }

