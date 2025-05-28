#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int decimal(string s){
    int n=s.size();
    int ans=0;
    int k=0;
    for(int i=n-1;i>=0;i--){
int res=stoi(s[i]);
        ans+=pow(2,k)*res;
        k++;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string temp;
        cin>>temp;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int str1,str2,str3="";
                for(int l=0;l<i;l++) str1+=temp[i];
                 for(int l=i+1;l<j;l++) str2+=temp[i];
                for(int l=j+1;l<k;l++) str3+=temp[i];
if(decimal(str1)==decimal(str2) && decimal(str2)==decimal(str3) && decimal(str3)==decimal(str1)) {
    cout<<1<<endl;
    break;
}

                }
            }
        }
          cout<<-1<<endl;
    }
  
}